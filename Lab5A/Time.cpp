#include "Time.h"

//////////////////
// CONSTRUCTORS //
//////////////////

Time::Time(int in_seconds) {
	this->in_seconds = in_seconds;
	//Time must be valid. Forcefully loop invalid values.
	while (this->in_seconds < MIN_TIME) this->in_seconds += DAY;
	while (this->in_seconds > MAX_TIME) this->in_seconds -= DAY;
}
Time::Time(int hours, int minutes) {
	this->in_seconds = HOURS_TO_SECONDS(hours) + MINUTES_TO_SECONDS(minutes);
	//Time must be valid. Forcefully loop invalid values.
	while (this->in_seconds < MIN_TIME) this->in_seconds += DAY;
	while (this->in_seconds > MAX_TIME) this->in_seconds -= DAY;
}
Time::Time(int hours, int minutes, int seconds) {
	this->in_seconds = HOURS_TO_SECONDS(hours) + MINUTES_TO_SECONDS(minutes) + seconds;
	//Time must be valid. Forcefully loop invalid values.
	while (this->in_seconds < MIN_TIME) this->in_seconds += DAY;
	while (this->in_seconds > MAX_TIME) this->in_seconds -= DAY;
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
		else if (new_hours < MIN_HOURS || new_hours > MAX_HOURS) {
			std::cout << "Hours \'" << new_hours << "\' out of bounds.((hh::mm) " << MIN_HOURS << " <= hh <= " << MAX_HOURS << ")" << std::endl
				<< "Try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(255, '\n');
			failed = true;
		}
		else if (new_minutes < MIN_MINUTES || new_minutes > MAX_MINUTES) {
			std::cout << "Minutes \'" << new_minutes << "\' out of bounds.((hh::mm) " << MIN_MINUTES << " <= mm <= " << MAX_MINUTES << ")" << std::endl
				<< "Try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(255, '\n');
			failed = true;
		}
		//Input is correct.
		else {
			new_time.in_seconds = HOURS_TO_SECONDS(new_hours) + MINUTES_TO_SECONDS(new_minutes);
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
	return this->in_seconds / HOUR_IN_SECONDS;
}

/*
* Gets minutes.
*/
int Time::get_minutes() const{
	return this->in_seconds % HOUR_IN_SECONDS / MINUTE_IN_SECONDS;
}

/*
* Gets seconds.
*/
int Time::get_seconds() const{
	return this->in_seconds % HOUR_IN_SECONDS % MINUTE_IN_SECONDS / MINUTE_IN_SECONDS;
}

//////////////////////////
// OPERATOR OVERLOADING //
//////////////////////////

/*
* Display time in format '(hh:mm)'.
*/
std::ostream &operator<<(std::ostream &out, const Time &time) {
	std::cout << std::setfill('0') << std::setw(2) << time.get_hours() << ":" << std::setfill('0') << std::setw(2) << time.get_minutes() << std::endl;
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
	this->in_seconds += MINUTE_IN_SECONDS;
	if (this->in_seconds > MAX_TIME) this->in_seconds -= DAY;
	return *this;
}

/*
* Post-increment
*/
Time Time::operator++(int) {
	Time old_time = *this;
	this->in_seconds += MINUTE_IN_SECONDS;
	if (this->in_seconds > MAX_TIME) this->in_seconds -= DAY;
	return old_time;
}