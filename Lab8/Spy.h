#pragma once
#ifndef SPY_H
#define SPY_H

#include "Person.h"

class Spy : public Person {
public:
	Spy(const std::string name = "nobody", const std::string alias = "nobody", int resistance = 0);
	virtual ~Spy() = default;
	void identity() const override;
	void interrogate() override;
	void set_identity(const char *alias);
private:
	const std::string name;
	std::string alias;
	int resistance;
};

#endif