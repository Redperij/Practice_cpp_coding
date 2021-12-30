#include "Quiz.h"

Quiz::Quiz(std::vector<Question> q) : questions(q) {}

//By default takes 5 questions from the database.
//In order to override it you have to use the other constructor receiving vector of questions.
// - Database class has get_questions() function returning questions vector.
Quiz::Quiz(const Database &db) {
    if (db.size() != 0) {
        std::vector<Question> db_questions = db.get_questions();
        UniqueRng rnd(0, db_questions.size() - 1);
        std::vector<unsigned int> chosen_q(quiz_const::N_QUESTIONS);
        //There must be at least 5 questions in the database. If there is not enough, constructor will throw an error.
        try {
            generate(chosen_q.begin(), chosen_q.end(), rnd);
            for (unsigned int pos : chosen_q) {
                this->questions.push_back(db_questions[pos]);
            }
        }
        catch (std::runtime_error) {
            std::cout << "Not enough questions in the database!" << std::endl << "Quiz must be aborted!" << std::endl;
        }
    }
    else {
        std::cout << "Database is empty. Quiz must be aborted." << std::endl;
    }
    
}

// Holds a quiz for the user using aquired questions.
void Quiz::hold_quiz() const{
    if (this->questions.size() == 0) throw std::runtime_error("Attempted to start quiz, but got no questions.");
    else {
        unsigned int score = 0;
        unsigned int cor_ans = 0;
        unsigned int percent;
        unsigned int counter = 1;

        std::cout << "Quiz with " << this->questions.size() << " questions has started!" << std::endl;
        //Asking all questions and getting score.
        for (Question q : this->questions) {
            std::cout << "Question " << counter++ << std::endl;
            cor_ans = q.show_question(); //Show question to user and save correct answer place.
            //Get user choice and increment score if the answer is correct.
            if (get_user_ans() == cor_ans) {
                std::cout << "Correct!" << std::endl << ".........................." << std::endl;
                score++;
            }
            else std::cout << "Incorrect!" << std::endl << ".........................." << std::endl;
        }
        std::cout << "Your score is " << score << " out of " << this->questions.size() << std::endl;
        
        //EXTRA (I didn't care about it too much)
        percent = static_cast<size_t> (score) * 100 / this->questions.size();
        if(percent == 0) std::cout << "Nothing? Really?" << std::endl;
        else if(percent < 25) std::cout << "Maybe it was too hard?" << std::endl;
        else if(percent < 50) std::cout << "You can do better!" << std::endl;
        else if(percent < 75) std::cout << "You are halfway there!" << std::endl;
        else if(percent < 80) std::cout << "3/4 - good score!" << std::endl;
        else if(percent < 90) std::cout << "Almost!" << std::endl;
        else if(percent < 99) std::cout << "There is always one stupid question that messes everything up!" << std::endl;
        else if(percent <= 100) std::cout << "Great!" << std::endl;
        else std::cout << "Well, I messed up here. Great job!... I guess... :D" << std::endl;
    }
}

//Asks user to enter 1, 2 or 3.
unsigned int Quiz::get_user_ans() const{
    int ans = 0;
    std::cout << "Enter answer number (1, 2 or 3): ";
    while (!(std::cin >> ans) || (ans <= 0 || ans >= 4)) {
        std::cout << "Error while reading input. Please, write 1, 2 or 3." << std::endl;
		std::cin.clear();
		std::cin.ignore(255, '\n');
        std::cout << "Enter answer number (1, 2 or 3): ";
    }
    return (unsigned int)ans;
}