#ifndef TIME_H
#define TIME_H

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

class Time
{
public:
	Time(int in_seconds = 0);
	Time(int hours, int minutes);
	Time(int hours, int minutes, int seconds);
	Time read(const char *message);
	bool lessThan(const Time time);
	Time subtract(const Time time);
	void display();
private:
	int hours;
	int minutes;
	int seconds;
	int in_seconds;
};
#endif