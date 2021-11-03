#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*
* Reads numbers from the user until negative number is given.
*/
int ioread_doub_nneg(vector<double> &list_doub_nneg);

int main() {
	vector<double> list_numbers;

	ioread_doub_nneg(list_numbers);

	cout << "Numbers list:" << endl;
	for (auto num : list_numbers) {
		cout << num << endl;
	}
	return 0;
}

/*
* Reads numbers from the user until negative number is given.
*/
int ioread_doub_nneg(vector<double> &list_doub_nneg) {
	double n = 0;
	cout << "Please, enter numbers. Negative number will stop the execution." << endl;
	cout << "Input: ";
	do {
		n = -1;
		cin >> n;
		cin.clear();
		cin.ignore(255, '\n');
		if (n >= 0) list_doub_nneg.push_back(n);
		cout << "Input: ";
	} while (n >= 0);
	list_doub_nneg.pop_back();

	return 0;
}