#include "main.h"
#include "Question.h"
#include "Database.h"
#include "Quiz.h"

using namespace std;

void show_menu();

int get_option();

string get_filename();

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
			filename = get_filename();
			if(filename != "/stop") {
				db.save_questions(filename);
				cout << "Questions successfully saved in \"" << filename << "\" file." << endl;
			}
			break;
		case 3: //Read questions.
			filename = get_filename();
			if(filename != "/stop") {
				{
					ifstream fin(filename);
					while (fin.fail()) {
						cout << "Error. Unable to open specified file." << endl;
						filename = get_filename();
						fin.open(filename);
					}
					fin.close();
				}
				db.read_questions(filename);
				cout << "Successfully read " << db.size() << " questions from \"" << filename << "\" file." << endl; 
			}
			break;
		case 4: //Add question.
			db.add_question();
			break;
		case 5: //Take quiz.
			try {
				Quiz(db).hold_quiz();
			}
			catch (runtime_error) {
				cout << "Aborted Quiz. Add more questions to the database. Currecntly have " << db.size() << " questions out of 5 required." << endl;
			}
			break;
		case 6: //Print a report.
			cout << db << endl;
			break;
		case 7: //Exit
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
	cout << "******************************************\n* Choose option:                         *\n* 1. Initialize. Clear all questions.    *\n* 2. Save questions to file.             *\n* 3. Read questions from file.           *\n* 4. Add question.                       *\n* 5. Take quiz.                          *\n* 6. Print a report.                     *\n* 7. Exit.                               *\n******************************************" << endl;
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
	cin.clear();
	cin.ignore(255, '\n');
	return choice;
}

string get_filename() {
	string filename;
	cout << "Please, specify name of the file or path.\nWrite \"/stop\" in order to escape." << endl << "Input: ";
	getline(cin, filename);
	return filename;
}