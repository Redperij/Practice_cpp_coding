#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int function(int &a);

int main() {
	vector <int> A;
	ifstream fin;
	string finally = "WE HAVE THEM! ";
	int a = 5;

	A.push_back(a);
	fin = ifstream("in.txt");
	cout << "Hello, cruel world." << endl;
	function(a);
	A.push_back(a);
	cout << finally << a << "\n";
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << ", ";
	}
	cout << endl;
	fin.close();
	return 0;
}

int function(int &a) {
	a = 20;
	return 0;
}