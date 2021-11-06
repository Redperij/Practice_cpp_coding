#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>

#define STOP "stop"

using namespace std;

/*
* Reverses all strings inside vector and sorts them.
*/
int backwards(vector<string> &vec_str);

int main() {
	vector<string> all_input;
	string input_string;

	cout << "Please, write strings. Enter \"stop\" to stop the execution" << endl;
	//Reading input.
	do {
		getline(cin, input_string);
		all_input.push_back(input_string);
	} while (input_string != STOP);
	all_input.pop_back(); //Getting rid of the STOP string

	if (all_input.size() > 0) {
		//Original output.
		cout << "Original content of the vector:" << endl;
		for (auto str : all_input) {
			cout << str << endl;
		}
		cout << endl;
		
		backwards(all_input);

		//Reverse sorted output.
		cout << "Reversed content of the vector:" << endl;
		for (auto str : all_input) {
			cout << str << endl;
		}
		cout << endl;
	}
	else {
		cout << "No strings were entered." << endl;
	}
	
	return 0;
}

/*
* Reverses all strings inside vector and sorts them in descending order.
*/
int backwards(vector<string> &vec_str) {
	for (size_t i = 0; i < vec_str.size(); i++) 
		reverse(vec_str[i].begin(), vec_str[i].end());
	sort(vec_str.begin(), vec_str.end(), greater<string>());
	return 0;
}