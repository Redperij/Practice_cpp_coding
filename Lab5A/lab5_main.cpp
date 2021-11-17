#include <iostream>
#include <vector>
#include <algorithm>
#include "Time.h"

using namespace std;

void print(const vector<Time> &v) 
{
	for(auto &t : v) {
		cout << t << endl;
	}
}

int main() {
	Time time1, time2, duration;

	time1.read("Enter time 1");
	time2.read("Enter time 2");
	if (time1 < time2) {
		duration = time2 - time1;
		cout << "Starting time was " << time1 << endl;
	} else {
		duration = time1 - time2;
		cout << "Starting time was " << time2 << endl;
	}
	cout << "Duration was " << duration << endl;

	vector<Time> tv(5); 
	for(auto &t : tv) {
		t.read("Enter time:");
	}

	cout << "Times: " << endl;
	print(tv);
	
	Time sum;
	for(auto t : tv) {
		sum = sum + t;
	}
	
	cout << "Sum of times: " << sum << endl;
	
	cout << "Post-increment: " << endl;
	print(tv);
	for(auto &t : tv) {
		cout << t++ << endl;
	}
	
	print(tv);

	cout << "Pre-increment: " << endl;
	for(auto &t : tv) {
		cout << ++t << endl;
	}

	sort(tv.begin(), tv.end());

	cout << "Sorted times: " << endl;
	print(tv);

	//Some additional checks.
	tv.push_back(Time(minute_in_seconds * 13 * -1));
	tv.push_back(Time(day * -3 + minute_in_seconds * 3));
	tv.push_back(Time(day * 9 + minute_in_seconds * 93));
	cout << "Vector with last 3 looped times:" << endl;
	print(tv);

	tv[0] = tv[0] - tv[1];
	cout << "Vector with first looped time:" << endl;
	print(tv);

	sort(tv.begin(), tv.end());
	cout << "Sorted times: " << endl;
	print(tv);
	return 0;
}

