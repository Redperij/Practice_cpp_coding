#include "Time.h"
#include <iostream>
#include <iomanip>

Time::Time(int in_seconds) {
	if (in_seconds < 0) in_seconds = 0;
	if (in_seconds == 0) {
		this->in_seconds = 0;
		this->hours = 0;
		this->minutes = 0;
		this->seconds = 0;
	}
	else {
		this->in_seconds = in_seconds;
		this->hours = in_seconds / HOUR_IN_SECONDS;
		in_seconds %= HOUR_IN_SECONDS;
		this->minutes = in_seconds / MINUTE_IN_SECONDS;
		in_seconds %= MINUTE_IN_SECONDS;
		this->seconds = in_seconds;
	}
}
Time::Time(int hours, int minutes) {
	//Time must be valid. Forcefully rewrite invalid values.
	if (hours < MIN_HOURS) hours = MIN_HOURS;
	else if (hours > MAX_HOURS) hours = MAX_HOURS;
	if (minutes < MIN_MINUTES) minutes = MIN_MINUTES;
	else if (minutes > MAX_MINUTES) minutes = MAX_MINUTES;

	this->hours = hours;
	this->minutes = minutes;
	this->seconds = 0;
	this->in_seconds = HOURS_TO_SECONDS(hours) + MINUTES_TO_SECONDS(minutes);
}
Time::Time(int hours, int minutes, int seconds) {
	//Time must be valid. Forcefully rewrite invalid values.
	if (hours < MIN_HOURS) hours = MIN_HOURS;
	else if (hours > MAX_HOURS) hours = MAX_HOURS;
	if (minutes < MIN_MINUTES) minutes = MIN_MINUTES;
	else if (minutes > MAX_MINUTES) minutes = MAX_MINUTES;
	if (seconds < MIN_SECONDS) seconds = MIN_SECONDS;
	else if (seconds > MAX_SECONDS) seconds = MAX_SECONDS;

	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
	this->in_seconds = HOURS_TO_SECONDS(hours) + MINUTES_TO_SECONDS(minutes) + seconds;
}

/*
* Reads new time from user input.
* Returns Time new_time.
*/
Time Time::read(const char *message) {
	Time new_time;
	char colon; //char to read colon (or any other character, we still want to make input valid).
	bool failed; //Reading failure flag.

	do {
		failed = false;
		std::cout << message << std::endl;
		std::cin >> new_time.hours >> colon >> new_time.minutes;
		//Validating input.
		if (std::cin.fail()) {
			std::cout << "Incorrect formatting. Time should be given as (hh:mm)" << std::endl
				<< "Try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(255, '\n');
			failed = true;
		}
		else if (new_time.hours < MIN_HOURS || new_time.hours > MAX_HOURS) {
			std::cout << "Hours \'" << new_time.hours << "\' out of bounds.((hh::mm) " << MIN_HOURS << " <= hh <= " << MAX_HOURS << ")" << std::endl
				<< "Try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(255, '\n');
			failed = true;
		}
		else if (new_time.minutes < MIN_MINUTES || new_time.minutes > MAX_MINUTES) {
			std::cout << "Minutes \'" << new_time.minutes << "\' out of bounds.((hh::mm) " << MIN_MINUTES << " <= mm <= " << MAX_MINUTES << ")" << std::endl
				<< "Try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(255, '\n');
			failed = true;
		}
		//Input is correct.
		else {
			new_time.in_seconds = HOURS_TO_SECONDS(new_time.hours) + MINUTES_TO_SECONDS(new_time.minutes);
			this->hours = new_time.hours;
			this->minutes = new_time.minutes;
			this->in_seconds = new_time.in_seconds;
		}
	} while (failed);
	
	return new_time;
}
/*
* 
*/
bool Time::lessThan(const Time time) {
	if (this->in_seconds < time.in_seconds) return true;
	return false;
}
/*
* 
*/
Time Time::subtract(const Time time) {
	Time new_time(this->in_seconds - time.in_seconds);
	return new_time;
}
/*
* 
*/
void Time::display() {
	std::cout << std::setfill('0') << std::setw(2) << this->hours << ":" << std::setfill('0') << std::setw(2) << this->minutes << std::endl;
}