#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
public:
	Person(const char *name = "nobody");
	virtual ~Person() = default;
	virtual void identity() const;
	virtual void interrogate();
private:
	std::string name;
};

#endif