#pragma once
#ifndef _Quiz_h
#define _Quiz_h

#include "main.h"
#include "Question.h" 
#include "Database.h"
#include "UniqueRng.h"

class Quiz
{
public:
	enum quiz_const {
		N_QUESTIONS = 5
	};
	Quiz(std::vector<Question> q = {});
	Quiz(const Database &db);
	void hold_quiz() const;
private:
	std::vector<Question> questions;
	unsigned int get_user_ans() const;
};

#endif