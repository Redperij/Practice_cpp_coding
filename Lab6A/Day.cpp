#include "Day.h"

//////////////////
// CONSTRUCTORS //
//////////////////
Day::Day() {
	this->day = 0;
	this->month = "";
	this->list = {};
}

///////////
// LOGIC //
///////////

/// <summary>
/// Reads date and events from string. Sorts event times in ascending order.
/// </summary>
/// <param name="s">String to process</param>
/// <returns>'true' if got date and at least one valid event. 'false' otherwise.</returns>
bool Day::from_str(const std::string &s) {
	std::istringstream strm(s);
	if (strm >> *this && this->list.size() > 0) {
		std::sort(this->list.begin(), this->list.end());
		return true;
	}
	return false;
}

/// <summary>
/// Converst day to string.
/// </summary>
/// <returns>Day string</returns>
std::string Day::to_str() {
	std::ostringstream to_string;
	to_string << *this;
	return to_string.str();
}

/// <summary>
/// Adds offset to all values in the list of times.
/// </summary>
/// <param name="offset">Number of hours to add</param>
void Day::dst(int offset) {
	for (auto &t : this->list) {
		t += hour_in_seconds * offset;
	}
	std::sort(this->list.begin(), this->list.end());
}

///////////////
// OVERLOADS //
///////////////

/// <summary>
/// Display day in format "[date] [month] [list of times in format "hh:mm" separated by whitespaces]"
/// </summary>
/// <param name="out">Output stream</param>
/// <param name="day">Day to display</param>
/// <returns>Output stream</returns>
std::ostream &operator<<(std::ostream &out, const Day &day) {
	out << day.day << " " + day.month << day.list;
	return out;
}

/// <summary>
/// Reads day.
/// </summary>
/// <param name="in">Input stream</param>
/// <param name="day">Day to read</param>
/// <returns>Input stream</returns>
std::istream &operator>>(std::istream &in, Day &day) {
	day = Day();
	if (in >> day.day >> day.month) {
		while (!in.fail()) {
			Time new_event;
			if (in >> new_event) {
				day.list.push_back(new_event);
			}
		}
		in.clear();
	}
	return in;
}