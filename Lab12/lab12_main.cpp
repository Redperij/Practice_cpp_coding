#include "UniqueRng.h"

#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>

using namespace std;

void test_generator(UniqueRng ur, int count);


int main(void) {
    UniqueRng randGen(5, 13);

    test_generator(randGen, 6);
    test_generator(randGen, 9);
    test_generator(randGen, 13);

    UniqueRng randGen2(1, 35);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 70);

    return 0;
}

void test_generator(UniqueRng ur, int count) {
    vector<unsigned int> numbers;
    cout << "Generating numbers:" << endl;
    try {
        for (int i = 0; i < count; i++) {
            numbers.push_back(ur());
        }
    }
    catch (std::runtime_error) {
        cout << "Tried to generate " << count << " random numbers.Got only " << numbers.size() << endl;
    }
    for (unsigned int num : numbers) {
        cout << num << endl;
    }
    cout << "End of generator" << endl;
}