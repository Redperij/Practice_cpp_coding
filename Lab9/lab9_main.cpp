#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <memory>
#include "Point.h"
#include "Circle.h"
#include "Square.h"

using namespace std;

#define EXTRA 1 //Set to 0 to disable extra B part.

#if EXTRA
#include <time.h>
void add_random_obj(vector<shared_ptr<Point>> &ptrvec, const int count);
#endif

int main() {
    vector<shared_ptr<Point>> ptrvec(6);

    ptrvec[0] = make_shared<Point>(1.0, 1.0);
    ptrvec[1] = make_shared<Circle>(2.0, 2.0, 2.0);
    ptrvec[2] = make_shared<Square>(5.0, 5.0, 2.0, 2.0);
    ptrvec[3] = make_shared<Point>();
    ptrvec[4] = make_shared<Circle>();
    ptrvec[5] = make_shared<Square>();
    ptrvec[3]->input("Please, give x and y values for point.\n");
    ptrvec[4]->input("Please, give radius of the circle.\n");
    ptrvec[5]->input("Please, give width and height of the square.\n");

    cout << endl << "Unsorted vector for part A:" << endl;
    for (auto ptr : ptrvec) {
        ptr->output();
    }
    cout << endl;

    sort(ptrvec.begin(), ptrvec.end(), sort_by_area);

    cout << endl << "Sorted vector for part A:" << endl;
    for (auto ptr : ptrvec) {
        ptr->output();
    }
    cout << endl;

#if EXTRA
    srand(time(NULL)/10);
    add_random_obj(ptrvec, 5);

    cout << endl << "Unsorted vector for part B:" << endl;
    for (auto ptr : ptrvec) {
        ptr->output();
    }
    cout << endl;

    sort(ptrvec.begin(), ptrvec.end(), sort_by_area);

    cout << endl << "Sorted vector for part B:" << endl;
    for (auto ptr : ptrvec) {
        ptr->output();
    }
    cout << endl;
#endif

    return 0;
}

#if EXTRA
void add_random_obj(vector<shared_ptr<Point>> &ptrvec, const int count) {
    short int random; //Having only 3 objects to choose from.
    shared_ptr<Point> shptr;

    ptrvec.reserve(ptrvec.size() + count);
    for (int i = 0; i < count; i++) {
        random = rand() % 3 + 1;
        switch (random)
        {
        case 1:
            shptr = make_shared<Point>();
            shptr->input("Please, give x and y values for point.\n");
            ptrvec.push_back(shptr);
            break;
        case 2:
            shptr = make_shared<Circle>();
            shptr->input("Please, give radius of the circle.\n");
            ptrvec.push_back(shptr);
            break;
        case 3:
            shptr = make_shared<Square>();
            shptr->input("Please, give width and height of the square.\n");
            ptrvec.push_back(shptr);
            break;
        default:
            //Something went completely wrong
            return;
        }
    }
}
#endif