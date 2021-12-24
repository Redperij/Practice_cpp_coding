#pragma once
#ifndef _Database_h
#define _Database_h

#include "main.h"
#include "Question.h"

class Database
{
	friend std::ostream &operator<<(std::ostream &out, const Database &db);
	friend std::ofstream &operator<<(std::ofstream &fout, const Database &db);
	friend std::ifstream &operator>>(std::ifstream &fin, const Database &db);
public:
	Database(std::vector<Question> q = {});
	void add_question();
	void add_question(Question &q);
	void remove_question();
	void remove_question(int pos);
	void remove_question(Question &q);
	void remove_question(std::string q_text);
	void read_questions(std::string filename);
	void save_questions(std::string filename);
	//void reinit(std::vector<Question> q = {});
private:
	std::vector<Question> questions;
};

#endif