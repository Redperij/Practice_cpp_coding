#include "Database.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS //
//////////////////

Database::Database(std::vector<Question> q) : questions(q) {}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS //
///////////////

// Asks user for the new question to add to the database.
void Database::add_question() { //ch
	Question q;
	std::cin >> q;
	this->add_question(q);
}
// Adds question to the database.
void Database::add_question(Question &q) {
	this->questions.push_back(q);
}
// Removes last question from the database.
void Database::remove_question() { //ch
	this->questions.pop_back();
}
// Removes question on a specified postition from the database.
void Database::remove_question(int pos) { //ch
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
// Reads questions from the specified file.
void Database::read_questions(std::string filename) {
	std::ifstream fin(filename);
	fin >> *this;
	fin.close();
}
// Save questions to the specified file.
void Database::save_questions(std::string filename) {
	std::ofstream fout(filename);
	fout << *this;
	fout.close();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OPERATORS //
///////////////

// Shows all questions from the database.
std::ostream &operator<<(std::ostream &out, const Database &db) {
	unsigned int counter = 1;
	std::cout << "All questions:" << std::endl;
	for(auto question : db.questions) {
		std::cout << counter++ << ") " << question << std::endl;
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// JSON PARSING //
//////////////////

void to_json(json &j, const Database &db) {
    j = json{{"questions", db.questions}};
}

void from_json(const json &j, Database &db) {
    j.at("questions").get_to(db.questions);
}