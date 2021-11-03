#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*
* Reads numbers from the user until negative number is given.
*/
int ioread_doub_nneg(vector<double> &list_doub_nneg);

/*
* Sorts numbers in the vector<double>. (From lowest to highest)
*/
int sort_numbers(vector<double> &list_doub);

int main() {
	vector<double> list_numbers;

	ioread_doub_nneg(list_numbers);
	if (!sort_numbers(list_numbers)) {
		cout << endl << "Sorted numbers list:" << endl;
		for (auto num : list_numbers) {
			cout << setprecision(3) << fixed << num << endl;
		}
	}
	else {
		cout << "No numbers were given." << endl;
	}

	return 0;
}

/*
* Reads numbers from the user until negative number is given.
*/
int ioread_doub_nneg(vector<double> &list_doub_nneg) {
	double n = -1;
	cout << "Please, enter numbers. Negative number will stop the execution." << endl;
	do {
		cout << "Input: ";
		cin >> n;
		//User gave wrong input -> do nothing.
		if (cin.fail()) {
			cin.clear();
			cin.ignore(255, '\n');
			cout << "Try again." << endl;
		}
		//Correct input -> add to vector.
		else {
			list_doub_nneg.push_back(n);
		}
	} while (n >= 0);
	//Get rid of the escape number.
	list_doub_nneg.pop_back();

	return 0;
}

/*
* Sorts numbers in the vector<double>. (From lowest to highest)
*/
int sort_numbers(vector<double> &list_doub) {
	size_t size = list_doub.size();
	
	if (size < 1) return 1;

	for (size_t i = 0; i < size; i++) {
		for (size_t q = 1; q < size; q++) {
			if (list_doub[q - 1] > list_doub[q]) {
				swap(list_doub[q - 1], list_doub[q]);
			}
		}
	}

	return 0;
}