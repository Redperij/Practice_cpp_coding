#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>

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
public:
	//Constructors.
	Time(int in_seconds = 0);
	Time(int hours, int minutes);
	Time(int hours, int minutes, int seconds);

	//Logic.
	Time read(const char *message);
	bool lessThan(const Time time) const;
	Time subtract(const Time time);
	void display() const;
	
	//Get functions.
	int get_hours() const;
	int get_minutes() const;
	int get_seconds() const;

	//Operator overloading.
	bool operator<(const Time &time) const;
	bool operator==(const Time &time) const;
	bool operator>(const Time &time) const;
	Time operator+(const Time &time) const;
	Time operator-(const Time &time) const;
	Time &operator++(); //pre-increment
	Time operator++(int); //post-increment
private:
	int in_seconds; //Time is stored in seconds.
};
#endif