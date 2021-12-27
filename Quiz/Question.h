#pragma once
#ifndef _Question_h
#define _Question_h

#include "main.h"
#include "UniqueRng.h"

class Question
{
	friend std::ostream &operator<<(std::ostream &out, const Question &question);
	friend std::istream &operator>>(std::istream &in, Question &question);
	friend std::ofstream &operator<<(std::ofstream &fout, const Question &question);
	friend std::ifstream &operator>>(std::ifstream &fin, Question &question);
	//json
	friend void to_json(json &j, const Question &q);
	friend void from_json(const json &j, Question &q);
public:
	Question(std::string q_text = "EMPTY QUESTION", std::string cor_ans = "EMPTY CORRECT ANSWER", std::vector<std::string> alt_ans = {});
	unsigned int show_question() const;	
	//Operators.
	bool operator==(const Question &q) const;
	bool operator==(const std::string &str) const;
	bool operator<(const Question &q) const;
private:
	std::string q_text; //Question itself.
	std::string cor_ans; //Correct answer.
	std::vector<std::string> alt_ans; //Alternative wrong answers.
};

bool validate(const std::string &str);

#endif