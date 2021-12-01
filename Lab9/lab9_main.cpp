#include <iostream>
#include <vector>
#include "Point.h"
#include "Circle.h"
#include "Square.h"

using namespace std;

int main() {
    vector<Point> *ptrvec; //Is there another way?
    Point check;
    check.input("Please, give x and y values.\n");
    check.output();
    return 0;
}