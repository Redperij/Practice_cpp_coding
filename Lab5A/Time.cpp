#include "Time.h"

const int min_seconds = 0;
const int max_seconds = 59;
const int min_minutes = 0;
const int max_minutes = 59;
const int min_hours = 0;
const int max_hours = 23;
const int hour_in_seconds = 3600;
const int minute_in_seconds = 60;
const int min_time = 0;
const int max_time = ((max_hours + 1) * hour_in_seconds) - 1; //24 hours minus 1 second
const int day = max_time + 1; //24 hours

//////////////////
// CONSTRUCTORS //
//////////////////

Time::Time(int in_seconds) {
	this->in_seconds = in_seconds;
	//Time must be valid. Forcefully loop invalid values.
	while (this->in_seconds < min_time) this->in_seconds += day;
	while (this->in_seconds > max_time) this->in_seconds -= day;
}
Time::Time(int hours, int minutes) {
	this->in_seconds = hour_in_seconds * hours + minute_in_seconds * minutes;
	//Time must be valid. Forcefully loop invalid values.
	while (this->in_seconds < min_time) this->in_seconds += day;
	while (this->in_seconds > max_time) this->in_seconds -= day;
}
Time::Time(int hours, int minutes, int seconds) {
	this->in_seconds = hour_in_seconds * hours + minute_in_seconds * minutes + seconds;
	//Time must be valid. Forcefully loop invalid values.
	while (this->in_seconds < min_time) this->in_seconds += day;
	while (this->in_seconds > max_time) this->in_seconds -= day;
}

///////////
// LOGIC //
///////////

/*
* Reads new time from user input.
* Returns Time new_time.
*/
Time Time::read(const char *message) {
	Time new_time;
	int new_hours, new_minutes;
	char colon; //char to read colon (or any other character, we still want to make input valid).
	bool failed; //Reading failure flag.

	do {
		failed = false;
		std::cout << message << std::endl;
		std::cin >> new_hours >> colon >> new_minutes;
		//Validating input.
		if (std::cin.fail()) {
			std::cout << "Incorrect formatting. Time should be given as (hh:mm)" << std::endl
				<< "Try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(255, '\n');
			failed = true;
		}
		else if (new_hours < min_hours || new_hours > max_hours) {
			std::cout << "Hours \'" << new_hours << "\' out of bounds.((hh::mm) " << min_hours << " <= hh <= " << max_hours << ")" << std::endl
				<< "Try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(255, '\n');
			failed = true;
		}
		else if (new_minutes < min_minutes || new_minutes > max_minutes) {
			std::cout << "Minutes \'" << new_minutes << "\' out of bounds.((hh::mm) " << min_minutes << " <= mm <= " << max_minutes << ")" << std::endl
				<< "Try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(255, '\n');
			failed = true;
		}
		//Input is correct.
		else {
			new_time.in_seconds = hour_in_seconds * new_hours + minute_in_seconds * new_minutes;
			this->in_seconds = new_time.in_seconds;
		}
	} while (failed);

	return new_time;
}

/*
* const Time time - time to compare to.
* Returns false if calling time is lesser than passed. True in other case.
*/
bool Time::lessThan(const Time time) const{
	if (this->in_seconds < time.in_seconds) return true;
	return false;
}

/*
* Subtracts passed time from calling time.
* const Time time - time to subtract.
* Returns resulting time.
*/
Time Time::subtract(const Time time) {
	Time new_time(this->in_seconds - time.in_seconds);
	return new_time;
}

/*
* Display time in format '(hh:mm)'.
*/
void Time::display() const{
	std::cout << std::setfill('0') << std::setw(2) << this->get_hours() << ":" << std::setfill('0') << std::setw(2) << this->get_minutes() << std::endl;
}

///////////////////
// GET FUNCTIONS //
///////////////////

/*
* Gets hours.
*/
int Time::get_hours() const{
	return this->in_seconds / hour_in_seconds;
}

/*
* Gets minutes.
*/
int Time::get_minutes() const{
	return this->in_seconds % hour_in_seconds / minute_in_seconds;
}

/*
* Gets seconds.
*/
int Time::get_seconds() const{
	return this->in_seconds % hour_in_seconds % minute_in_seconds / minute_in_seconds;
}

//////////////////////////
// OPERATOR OVERLOADING //
//////////////////////////

/*
* Display time in format '(hh:mm)'.
*/
std::ostream &operator<<(std::ostream &out, const Time &time) {
	out << std::setfill('0') << std::setw(2) << time.get_hours() << ":" << std::setfill('0') << std::setw(2) << time.get_minutes() << std::endl;
	return out;
}

/*
* Compares time by value in seconds.
*/
bool Time::operator<(const Time &time) const {
	return (this->in_seconds < time.in_seconds);
}

/*
* Compares time by value in seconds.
*/
bool Time::operator==(const Time &time) const {
	return (this->in_seconds == time.in_seconds);
}

/*
* Compares time by value in seconds.
*/
bool Time::operator>(const Time &time) const {
	return (this->in_seconds > time.in_seconds);
}

/*
* Adds one time to another by value in seconds.
*/
Time Time::operator+(const Time &time) const {
	Time new_time(this->in_seconds + time.in_seconds);
	return new_time;
}

/*
* Subtracts one time from another by value in seconds.
*/
Time Time::operator-(const Time &time) const {
	Time new_time(this->in_seconds - time.in_seconds);
	return new_time;
}

/*
* Pre-increment
*/
Time &Time::operator++() {
	this->in_seconds += minute_in_seconds;
	if (this->in_seconds > max_time) this->in_seconds -= day;
	return *this;
}

/*
* Post-increment
*/
Time Time::operator++(int) {
	Time old_time = *this;
	this->in_seconds += minute_in_seconds;
	if (this->in_seconds > max_time) this->in_seconds -= day;
	return old_time;
}