#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"

class Circle : public Point {
public:
    //constructor
    Circle(double xcoord = 0.0, double ycoord = 0.0, double radius = 0);
    // destructor
    virtual ~Circle() = default;

    virtual void input(const char *prompt) override;
    virtual void output() const override;
    virtual double area() const override;
    virtual bool operator<(const std::shared_ptr<Point> p) const override; //Haven't used
private:
    double radius;
};

#endif