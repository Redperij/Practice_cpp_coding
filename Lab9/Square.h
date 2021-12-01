#pragma once
#ifndef SQUARE_H
#define SQUARE_H

#include "Point.h"

class Square : public Point {
public:
    //constructor
    Square(double xcoord = 0.0, double ycoord = 0.0, double width = 0, double height = 0);
    // destructor
    virtual ~Square() = default;

    virtual void input(const char *prompt) override;
    virtual void output() const override;
    virtual double area() const override;
private:
    double width;
    double height;
};

#endif