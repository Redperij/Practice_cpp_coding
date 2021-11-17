#pragma once
#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>
#include <vector>

extern const int min_seconds;
extern const int max_seconds;
extern const int min_minutes;
extern const int max_minutes;
extern const int min_hours;
extern const int max_hours;
extern const int hour_in_seconds;
extern const int minute_in_seconds;

extern const int min_time;
extern const int max_time;
extern const int day;

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