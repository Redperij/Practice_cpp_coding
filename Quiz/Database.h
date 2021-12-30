#pragma once
#ifndef _Database_h
#define _Database_h

#include "main.h"
#include "Question.h"

class Database
{
	friend std::ostream &operator<<(std::ostream &out, const Database &db);
	friend std::ofstream &operator<<(std::ofstream &fout, const Database &db);
	friend std::ifstream &operator>>(std::ifstream &fin, Database &db);
	//json
	friend void to_json(json &j, const Database &db);
	friend void from_json(const json &j, Database &db);
public:
	Database(std::vector<Question> q = {});
	void add_question();
	void add_question(Question &q);
	void add_question(Question &q, bool bypass_check); //not used
	void remove_question(); //not used
	void remove_question(int pos); //not used
	void remove_question(Question &q); //not used
	void remove_question(std::string q_text); //not used
	unsigned int size() const;
	void read_questions(std::string filename);
	void save_questions(std::string filename) const;
	std::vector<Question> get_questions() const;
	//Operators.
	Database operator+=(Database &db);
private:
	std::vector<Question> questions;
};

#endif