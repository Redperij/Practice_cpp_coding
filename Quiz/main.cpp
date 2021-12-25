#include "main.h"
#include "Question.h"

using namespace std;

int main() {

	//1. init - clear questions.
	//2. save questions.
	//3. read questions from file.
	//4. add question.
	//5. take quiz.
	//6. print all questions.

	Question q1;
	int cor_ans;
	cin >> q1;
	cout << q1;
	cout << endl << endl << endl;
	cor_ans = q1.show_question();
	cout << "Correct answer: " << cor_ans << endl;
	system("pause");
	cor_ans = q1.show_question();
	cout << "Correct answer: " << cor_ans << endl;
	system("pause");
	cor_ans = q1.show_question();
	cout << "Correct answer: " << cor_ans << endl;
	return 0;
}