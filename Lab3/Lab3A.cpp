#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

/*
* Reads numbers from the user until negative number is given.
*/
int ioread_doub_nneg(vector<double> &list_doub_nneg);

int main() {
	vector<double> list_numbers;

	ioread_doub_nneg(list_numbers);
	if (list_numbers.size() > 0) {
		sort(list_numbers.begin(), list_numbers.end());
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