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
	//Time must be valid.
	this->roll_over();
}
Time::Time(int hours, int minutes) {
	this->in_seconds = hour_in_seconds * hours + minute_in_seconds * minutes;
	//Time must be valid.
	this->roll_over();
}
Time::Time(int hours, int minutes, int seconds) {
	this->in_seconds = hour_in_seconds * hours + minute_in_seconds * minutes + seconds;
	//Time must be valid.
	this->roll_over();
}

///////////
// LOGIC //
///////////

/// <summary>
/// Reads new time from user input.
/// </summary>
/// <param name="message">Message to display for user</param>
/// <returns>New valid time object</returns>
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

/// <summary>
/// Compares times.
/// </summary>
/// <param name="time">Time to compare to</param>
/// <returns>Result of comparison</returns>
bool Time::lessThan(const Time time) const{
	return this->in_seconds < time.in_seconds;
}

/// <summary>
/// Subtracts passed time from calling time.
/// </summary>
/// <param name="time">Time to subtract</param>
/// <returns>Result of subtraction</returns>
Time Time::subtract(const Time time) {
	Time new_time(this->in_seconds - time.in_seconds);
	return new_time;
}

/// <summary>
/// Display time in format '(hh:mm)'.
/// </summary>
void Time::display(void) const{
	std::cout << std::setfill('0') << std::setw(2) << this->get_hours() << ":" << std::setfill('0') << std::setw(2) << this->get_minutes() << std::endl;
}

/////////////
// GETTERS //
/////////////

/// <summary>
/// Determines hours value from time.
/// </summary>
/// <returns>Hours value</returns>
int Time::get_hours(void) const{
	return this->in_seconds / hour_in_seconds;
}

/// <summary>
/// Determines minutes value from time.
/// </summary>
/// <returns>Minutes value</returns>
int Time::get_minutes(void) const{
	return this->in_seconds % hour_in_seconds / minute_in_seconds;
}

/// <summary>
/// Determines seconds value from time.
/// </summary>
/// <returns>Seconds value</returns>
int Time::get_seconds(void) const{
	return this->in_seconds % hour_in_seconds % minute_in_seconds / minute_in_seconds;
}

///////////////
// OVERLOADS //
///////////////

/// <summary>
/// Display time in format 'hh:mm'.
/// </summary>
/// <param name="out">Output stream</param>
/// <param name="time">Time to display</param>
/// <returns>Output stream</returns>
std::ostream &operator<<(std::ostream &out, const Time &time) {
	out << std::setfill('0') << std::setw(2) << time.get_hours() << ":" << std::setfill('0') << std::setw(2) << time.get_minutes();
	return out;
}

/// <summary>
/// Display time vector in format 'hh:mm ...'.
/// </summary>
/// <param name="out">Output stream</param>
/// <param name="list">Time vector to display</param>
/// <returns>Output stream</returns>
std::ostream &operator<<(std::ostream &out, const std::vector<Time> &list) {
	for (auto time : list) {
		out << " " << time;
	}
	return out;
}

/// <summary>
/// Reads time in the format: 'hh:mm'.
/// </summary>
/// <param name="in">Input stream</param>
/// <param name="time">Time to read</param>
/// <returns>Input stream</returns>
std::istream &operator>>(std::istream &in, Time &time) {
	int new_hours, new_minutes;
	char c;
	if (in >> new_hours >> c >> new_minutes) {
		time = Time(new_hours, new_minutes);
	}
	return in;
}

/// <summary>
/// Compares time by value in seconds.
/// </summary>
/// <param name="time">Right value</param>
/// <returns>Result of comparison</returns>
bool Time::operator<(const Time &time) const {
	return (this->in_seconds < time.in_seconds);
}

/// <summary>
/// Compares time by value in seconds.
/// </summary>
/// <param name="time">Right value</param>
/// <returns>Result of comparison</returns>
bool Time::operator==(const Time &time) const {
	return (this->in_seconds == time.in_seconds);
}

/// <summary>
/// Compares time by value in seconds.
/// </summary>
/// <param name="time">Right value</param>
/// <returns>Result of comparison</returns>
bool Time::operator>(const Time &time) const {
	return (this->in_seconds > time.in_seconds);
}

/// <summary>
/// Adds one time to another by value in seconds.
/// </summary>
/// <param name="time">Right value</param>
/// <returns>Result of operation</returns>
Time Time::operator+(const Time &time) const {
	Time new_time(this->in_seconds + time.in_seconds);
	return new_time;
}

/// <summary>
/// Adds integer to the time by value in seconds.
/// </summary>
/// <param name="time_to_add">Right value</param>
/// <returns>Result of operation</returns>
Time Time::operator+(const int &time_to_add) const {
	Time new_time(this->in_seconds + time_to_add);
	return new_time;
}

/// <summary>
/// Adds integer to the time by value in seconds.
/// </summary>
/// <param name="time_to_add">Right value</param>
/// <returns>Left value incremented by right value</returns>
Time &Time::operator+=(const int &time_to_add) {
	this->in_seconds += time_to_add;
	this->roll_over();
	return *this;
}

/// <summary>
/// Subtracts one time from another by value in seconds.
/// </summary>
/// <param name="time">Right value</param>
/// <returns>Result of operation</returns>
Time Time::operator-(const Time &time) const {
	Time new_time(this->in_seconds - time.in_seconds);
	return new_time;
}

/// <summary>
/// Pre-increment.
/// </summary>
/// <returns>time + one minute</returns>
Time &Time::operator++() {
	this->in_seconds += minute_in_seconds;
	if (this->in_seconds > max_time) this->in_seconds -= day;
	return *this;
}

/// <summary>
/// Post-increment.
/// </summary>
/// <param name=""></param>
/// <returns>Time before increment.</returns>
Time Time::operator++(int) {
	Time old_time = *this;
	this->in_seconds += minute_in_seconds;
	if (this->in_seconds > max_time) this->in_seconds -= day;
	return old_time;
}

/////////////
// HELPERS //
/////////////

/// <summary>
/// Rolls time if it is invalid.
/// </summary>
void Time::roll_over() {
	while (this->in_seconds < min_time) this->in_seconds += day;
	while (this->in_seconds > max_time) this->in_seconds -= day;
}