#include "Time.h"

//////////////////
// CONSTRUCTORS //
//////////////////

Time::Time(int in_seconds) {
	this->in_seconds = in_seconds;
	//Time must be valid.
	this->roll_over();
}
Time::Time(int hours, int minutes) {
	this->in_seconds = HOURS_TO_SECONDS(hours) + MINUTES_TO_SECONDS(minutes);
	//Time must be valid.
	this->roll_over();
}
Time::Time(int hours, int minutes, int seconds) {
	this->in_seconds = HOURS_TO_SECONDS(hours) + MINUTES_TO_SECONDS(minutes) + seconds;
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
	return this->in_seconds / HOUR_IN_SECONDS;
}

/// <summary>
/// Determines minutes value from time.
/// </summary>
/// <returns>Minutes value</returns>
int Time::get_minutes(void) const{
	return this->in_seconds % HOUR_IN_SECONDS / MINUTE_IN_SECONDS;
}

/// <summary>
/// Determines seconds value from time.
/// </summary>
/// <returns>Seconds value</returns>
int Time::get_seconds(void) const{
	return this->in_seconds % HOUR_IN_SECONDS % MINUTE_IN_SECONDS / MINUTE_IN_SECONDS;
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
	this->in_seconds += MINUTE_IN_SECONDS;
	if (this->in_seconds > MAX_TIME) this->in_seconds -= DAY;
	return *this;
}

/// <summary>
/// Post-increment.
/// </summary>
/// <param name=""></param>
/// <returns>Time before increment.</returns>
Time Time::operator++(int) {
	Time old_time = *this;
	this->in_seconds += MINUTE_IN_SECONDS;
	if (this->in_seconds > MAX_TIME) this->in_seconds -= DAY;
	return old_time;
}

/////////////
// HELPERS //
/////////////

/// <summary>
/// Rolls time if it is invalid.
/// </summary>
void Time::roll_over() {
	while (this->in_seconds < MIN_TIME) this->in_seconds += DAY;
	while (this->in_seconds > MAX_TIME) this->in_seconds -= DAY;
}