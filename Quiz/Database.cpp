#include "Database.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS //
//////////////////

Database::Database(std::vector<Question> q) : questions(q) {}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS //
///////////////

// Asks user for the new question to add to the database.
void Database::add_question() {
	Question q;
	std::cin >> q;
	this->add_question(q);
}
// Adds unique question to the database.
void Database::add_question(Question &q) {
	//If the question is found in existing database - it is dropped.
	if ( std::find_if(this->questions.begin(), this->questions.end(), [&q](Question &question) {return question == q;}) == this->questions.end() ) {
		this->questions.push_back(q);
	}
	else {
		this->remove_question(q);
		this->questions.push_back(q);
		std::cout << "Question:\n\"" << q << "\"\n-> This question was overriden." << std::endl;
	}
}
// Adds question to the database.
// If bypass_check is set to 'true', adds question to the batabase even if such question already exists.
void Database::add_question(Question &q, bool bypass_check) {
	if (bypass_check) this->questions.push_back(q);
	else this->add_question(q);
}
// Removes last question from the database.
void Database::remove_question() {
	this->questions.pop_back();
}
// Removes question on a specified postition from the database.
void Database::remove_question(int pos) {
	this->questions.erase(this->questions.begin() + pos);
}
// Removes specified question from the database.
void Database::remove_question(Question &q) {
	this->questions.erase(std::find(this->questions.begin(), this->questions.end(), q));
}
// Removes all questions with the specified question text.
void Database::remove_question(std::string q_text) {
	auto ite = std::find_if(this->questions.begin(), this->questions.end(), [&q_text](Question &question) {
		return question == q_text;
	});
	while(ite != this->questions.end()) {
		this->questions.erase(ite);
		ite = std::find_if(this->questions.begin(), this->questions.end(), [&q_text](Question &question) {
			return question == q_text;
		});
	} 
}
// Returns number of questions in the database.
unsigned int Database::size() const{
	return this->questions.size();
}
// Reads questions from the specified file and adds them to the existing database.
void Database::read_questions(std::string filename) {
	Database in_db;
	std::ifstream fin(filename);
	fin >> in_db;
	fin.close();
	*this += in_db; 
}
// Save questions to the specified file.
void Database::save_questions(std::string filename) const{
	std::ofstream fout(filename);
	fout << *this;
	fout.close();
}
// Returns vector of questions stored in database.
std::vector<Question> Database::get_questions() const{
	return this->questions;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OPERATORS //
///////////////

// Shows all questions from the database.
std::ostream &operator<<(std::ostream &out, const Database &db) {
	unsigned int counter = 1;
	out << "All questions:" << std::endl;
	for(auto question : db.questions) {
		out << std::setw(2) << counter++ << ") " << question << std::endl;
	}
	return out;
}
// Saves database to the file.
std::ofstream &operator<<(std::ofstream &fout, const Database &db) {
	json j(db);
    fout << std::setw(4) << j << std::endl;
	return fout;
}
// Reads database from the file.
std::ifstream &operator>>(std::ifstream &fin, Database &db) {
	json j;
    fin >> j;
    from_json(j, db);
	return fin;
}
// Copies non-repeating questions from one database to another.
Database Database::operator+=(Database &db) {
	for (Question q : db.get_questions()) {
		this->add_question(q);
	}
	return *this;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// JSON PARSING //
//////////////////

void to_json(json &j, const Database &db) {
    j = json{{"questions", db.questions}};
}

void from_json(const json &j, Database &db) {
    j.at("questions").get_to(db.questions);
}