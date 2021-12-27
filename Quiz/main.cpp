#include "main.h"
#include "Question.h"
#include "Database.h"
#include "Quiz.h"

using namespace std;

int main() {

	//1. init - clear questions.
	//2. save questions.
	//3. read questions from file.
	//4. add question.
	//5. take quiz.
	//6. print all questions.

	vector<Question> questions;
	questions.push_back(Question("1?", "Hello", {"1.1", "1.2", "1.3"}));
	questions.push_back(Question("2?", "Hello2", {"2.1", "2.2", "2.3"}));
	questions.push_back(Question("Question", "Correct", {"1", "2", "3"}));

	Database db(questions);

	db.read_questions("Save1.json");
	cout << db << endl;
	//db.remove_question(0);
	//cout << "Removed question" << endl << db << endl;
	//db.save_questions("Save1.json");
	Quiz quiz(db);
	quiz.hold_quiz();
	
	return 0;
}