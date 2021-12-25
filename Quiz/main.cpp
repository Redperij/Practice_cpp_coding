#include "main.h"
#include "Question.h"
#include "Database.h"

using namespace std;

int main() {

	//1. init - clear questions.
	//2. save questions.
	//3. read questions from file.
	//4. add question.
	//5. take quiz.
	//6. print all questions.

	vector<Question> questions;
	questions.push_back(Question("Hello?", "Hello", {"Hey", "How are you?", "Go away"}));
	questions.push_back(Question("Hello2?", "Hello2", {"Hey2", "How are you?2", "Go away2"}));
	questions.push_back(Question("Question", "Correct", {"1", "2", "3"}));

	Database db(questions);

	ofstream fout("db.json");
	fout << db;
	fout.close();
	ifstream fin("db.json");
	Database db2;
	fin >> db2;
	fin.close();

	cout << db2;
	return 0;
}