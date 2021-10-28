#include <iostream>
#include <string>
#include <vector>

#define STOP "stop"

using namespace std;

/*
* Gets longest string index from string vector.
* const vector<string> strvec - vector with strings.
* Returns index of the longest string.
*/
size_t get_lstr_index(const vector<string> strvec);

int main() {
	vector<string> all_input; //Vector with all input strings.
	string input_string; //Input string from the user.
	size_t longest_index; //Index of the longest string.

	cout << "Please, write strings. Enter \"stop\" to stop the execution" << endl;
	//Reading input.
	do {
		getline(cin, input_string);
		all_input.push_back(input_string);
	} while (input_string != STOP);
	all_input.pop_back(); //Getting rid of the STOP string

	if (all_input.size() != 0) {
		//Output. (strings and their number)
		cout << endl << "You have entereed:" << endl;
		for (size_t i = 0; i < all_input.size(); i++) {
			cout << i + 1 << ": " << all_input[i] << endl;
		}
		cout << "Number of strings: " << all_input.size() << endl;

		longest_index = get_lstr_index(all_input);
		//Output. (the longest string)
		cout << endl << "The longest string is:" << endl << longest_index + 1 << ": " << all_input[longest_index] << endl << "Size: " << all_input[longest_index].size() << endl;
		//(size and capacity of the vector)
		cout << endl << "Vector size: " << all_input.size() << endl << "Vector capacity: " << all_input.capacity() << endl << endl;
	}
	else {
		cout << endl << "Only stop command was given. Stopping execution." << endl;
	}
	
	return 0;
}

/*
* Gets longest string index from string vector.
* const vector<string> strvec - vector with strings.
* Returns index of the longest string.
*/
size_t get_lstr_index(const vector<string> strvec) {
	size_t max = 0;
	size_t longest_ind = 0;
	for (size_t i = 0; i < strvec.size(); i++) {
		if (max < strvec[i].size()) {
			max = strvec[i].size();
			longest_ind = i;
		}
	}
	return longest_ind;
}