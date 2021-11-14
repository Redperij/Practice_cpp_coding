#pragma once
#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>
#include <vector>

#define MIN_SECONDS 0
#define MAX_SECONDS 59
#define MIN_MINUTES 0
#define MAX_MINUTES 59
#define MIN_HOURS 0
#define MAX_HOURS 23
#define HOUR_IN_SECONDS 3600
#define MINUTE_IN_SECONDS 60
#define HOURS_TO_SECONDS(x) (x * HOUR_IN_SECONDS)
#define MINUTES_TO_SECONDS(x) (x * MINUTE_IN_SECONDS)

#define MIN_TIME 0
#define MAX_TIME (HOURS_TO_SECONDS((MAX_HOURS + 1)) - 1) //24 hours minus 1 second
#define DAY (MAX_TIME + 1) //24 hours

class Time
{
	friend std::ostream &operator<<(std::ostream &out, const Time &time);
	friend std::ostream &operator<<(std::ostream &out, const std::vector<Time> &list);
	friend std::istream &operator>>(std::istream &in, Time &time);
public:
	//Constructors.
	Time(int in_seconds = 0);
	Time(int hours, int minutes);
	Time(int hours, int minutes, int seconds);

	//Logic.
	Time read(const char *message);
	bool lessThan(const Time time) const;
	Time subtract(const Time time);
	void display(void) const;
	
	//Getters.
	int get_hours(void) const;
	int get_minutes(void) const;
	int get_seconds(void) const;

	//Overloads.
	bool operator<(const Time &time) const;
	bool operator==(const Time &time) const;
	bool operator>(const Time &time) const;
	Time operator+(const Time &time) const;
	Time operator+(const int &time_to_add) const;
	Time &operator+=(const int &time_to_add);
	Time operator-(const Time &time) const;
	Time &operator++(); //pre-increment
	Time operator++(int); //post-increment
private:
	int in_seconds; //Time is stored in seconds.
	void roll_over();
};
#endif