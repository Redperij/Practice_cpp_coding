#pragma once
#ifndef _Question_h
#define _Question_h

#include "main.h"
#include "UniqueRng.h"

class Question
{
	friend std::ostream &operator<<(std::ostream &out, const Question &question);
	friend std::istream &operator>>(std::istream &in, const Question &question);
	friend std::ofstream &operator<<(std::ofstream &fout, const Question &question);
	friend std::ifstream &operator>>(std::ifstream &fin, const Question &question);
public:
	Question(std::string q_text = "EMPTY QUESTION", std::string cor_ans = "", std::vector<std::string> alt_ans = {});
	unsigned int show_question();
	//modifications (if needed)
private:
	std::string q_text; //Question itself.
	std::string cor_ans; //Correct answer.
	std::vector<std::string> alt_ans; //Alternative wrong answers.
};

#endif