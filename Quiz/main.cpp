#include "main.h"
#include "Question.h"
#include "Database.h"
#include "Quiz.h"

using namespace std;

void show_menu();

int get_option();

int main() {
	Database db;
	string filename;
	bool exit = false;

	while (!exit) {
		show_menu();
		switch (get_option())
		{
		case 1: //Initialize.
			db = Database();
			break;
		case 2: //Save questions.
			//filename =
			//Give file choice.
			db.save_questions("temp.json");
			cout << "Questions successfully saved in \"" << "temp.json" << "\" file." << endl;
			break;
		case 3: //Read questions.
			//filename = 
			//Give file choice.
			db.read_questions("Save1.json");
			cout << "Successfully read " << db.size() << " questions from \"" << "Save1.json" << "\" file." << endl; 
			break;
		case 4: //Add question.
			db.add_question();
			break;
		case 5: //Take quiz.
			Quiz(db).hold_quiz();
			break;
		case 6: //Print a report.
			cout << db << endl;
			break;
		case 7:
			cout << "Terminating." << endl;
			exit = true;
			break;
		default: //Wrong number.
			cout << "Number must be (1 <= x <= 7)." << endl;
			break;
		}
	}
	cout << "Terminated." << endl;
	return 0;
}

void show_menu() {
	cout << "******************************************\n* Choose option:                         *\n* 1. Initialize. Clear all questions.    *\n* 2. Save questions to file.             *\n* 3. Read questions from file.           *\n* 4. Add question.                       *\n* 5. Take queiz.                         *\n* 6. Print a report.                     *\n* 7. Exit.                               *\n******************************************" << endl;
}

int get_option() {
	int choice = 0;
	cout << "Inter a number of option: ";
    while (!(std::cin >> choice)) {
        cout << "Error while reading input." << endl;
		cin.clear();
		cin.ignore(255, '\n');
		cout << "Inter a number of option: ";
    }
	return choice;
}