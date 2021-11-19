#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include "RandGen.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

bool ask_stop();

void main(void) {
	bool stop = true;
	do {

		vector<int> lotto(7), viking_lotto(6), eurojackpot(5), two_intersection, intersection;
		ostream_iterator<int> ostr_it(cout, " ");
		RandGen randGen(1, 40);

		generate(lotto.begin(), lotto.end(), randGen);
		randGen = RandGen(1, 48);
		generate(viking_lotto.begin(), viking_lotto.end(), randGen);
		randGen = RandGen(1, 50);
		generate(eurojackpot.begin(), eurojackpot.end(), randGen);

#if DEBUG //Force all three sets to have the same number.
		lotto[0] = 1;
		viking_lotto[0] = 1;
		eurojackpot[0] = 1;
#endif

		//Printing first two sets.
		cout << "Lotto: ";
		copy(lotto.begin(), lotto.end(), ostr_it);
		cout << endl << "Viking Lotto: ";
		copy(viking_lotto.begin(), viking_lotto.end(), ostr_it);
		cout << endl;
		//Sort two sets to use set_intersection() algorithm.
		sort(lotto.begin(), lotto.end());
		sort(viking_lotto.begin(), viking_lotto.end());

		//Find intersection from first two sets.
		set_intersection(lotto.begin(), lotto.end(), viking_lotto.begin(), viking_lotto.end(), back_inserter(two_intersection));
		//Print intersection.
		cout << "Matching numbers:" << endl;
		{
			int indexing = 0;
			for_each(two_intersection.begin(), two_intersection.end(), [&indexing](const int number) {
				indexing++;
				cout << "#" << indexing << ": " << number << endl;
				});
		}

		//Print third set.
		cout << "Eurojackpot: ";
		copy(eurojackpot.begin(), eurojackpot.end(), ostr_it);
		cout << endl;
		//Sort last set to use set_intersection() algorithm.
		sort(eurojackpot.begin(), eurojackpot.end());

		//Find intersection from three setrs.
		set_intersection(two_intersection.begin(), two_intersection.end(), eurojackpot.begin(), eurojackpot.end(), back_inserter(intersection));
		//Print intersection from three sets.
		cout << "Matching numbers in three sets:" << endl;
		{
			int indexing = 0;
			for_each(intersection.begin(), intersection.end(), [&indexing](const int number) {
				indexing++;
				cout << "#" << indexing << ": " << number << endl;
				});
		}
		stop = ask_stop();
	} while (!stop);
}

bool ask_stop() {
	string user_input;
	bool incorrect_input = true;
	bool stop = true;
	cout << "Should the program continue?" << endl;
	do {
		cout << "[yes/no]: ";
		getline(cin, user_input);
		//Setting all input to uppercase.
		for_each(user_input.begin(), user_input.end(), [](char &c) {
			c = toupper(c);
		});
		if (user_input == "YES" || user_input == "Y" || user_input == "YE") {
			stop = false;
			incorrect_input = false;
		}
		else if (user_input == "NO" || user_input == "N") {
			stop = true;
			incorrect_input = false;
		}
	} while (incorrect_input);
	cout << endl;
	return stop;
}