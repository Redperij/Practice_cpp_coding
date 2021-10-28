#include <iostream>
#include <cstdlib>
#include <ctime>

#define NEED_PAUSE 0

using namespace std;

int mean(const int *array, const int n);

int main() {
	int n = 0; // Number of integers in array.
	int *arr; //Array with integers
	srand(time(NULL)); //Random seed is time.

	//Reading user input.
	cout << "Please, enter count of numbers:" << endl;
	cout << "Input: ";
	cin >> n;
	while (n <= 0) {
		cin.clear();
		cin.ignore(255, '\n');
		cout << "Give a number in range of: x > 0" << endl;
		cout << "Input: ";
		cin >> n;

	}

	//Initializing array. 
	arr = new int[n];
	for (unsigned int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}

	//Prinitng array and average.
	cout << "Array is:" << endl;
	for (unsigned int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Mean is: " << mean(arr, n) << endl;

	//Free memory.
	delete[] arr;
#if NEED_PAUSE
	system("pause");
#endif
	return 0;
}

int mean(const int *array, const int n) {
	int mean = 0;
	for (unsigned int i = 0; i < n; i++) {
		mean += array[i];
	}
	return mean / n;
}