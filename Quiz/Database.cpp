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
// Adds question to the database.
void Database::add_question(Question &q) {
	this->questions.push_back(q);
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
	std::cout << "All questions:" << std::endl;
	for(auto question : db.questions) {
		std::cout << std::setw(2) << counter++ << ") " << question << std::endl;
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

Database Database::operator+=(Database &db) {
	for (Question q : db.get_questions()) {
		//If the question is found in existing database - it is dropped.
		if ( std::find_if(this->questions.begin(), this->questions.end(), [&q](Question &question) {return question == q;}) == this->questions.end()) {
			this->questions.push_back(q);
		}
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