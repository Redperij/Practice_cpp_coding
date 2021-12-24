#pragma once
#ifndef _Quiz_h
#define _Quiz_h

#include "main.h"
#include "Question.h" 

class Quiz
{
public:
	Quiz(std::vector<Question> q = {});
	void hold_quiz();
private:
	std::vector<Question> all_questions;
};

#endif