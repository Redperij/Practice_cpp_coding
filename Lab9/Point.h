#pragma once
#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <iomanip>
#include <memory>

class Point {
public:
    //constructor
    Point(double xcoord = 0.0, double ycoord = 0.0);
    // destructor
    virtual ~Point() = default;
    virtual void input(const char *prompt);
    virtual void output() const;
    virtual double area() const;
    void move(double deltax, double deltay);
    virtual bool operator<(const std::shared_ptr<Point> p) const; //Haven't used
private:
    double x;
    double y;
};

bool sort_by_area(const std::shared_ptr<Point> p1, const std::shared_ptr<Point> p2);

#endif