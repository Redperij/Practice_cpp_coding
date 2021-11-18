#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

class Time {
private:
    int hour;
    int minute;


public:
    Time(int h = 0, int m = 0) {
        hour = h;
        minute = m;
    }

    void read(string t) {
        cout << t << endl;
        cout << "Enter hours" << endl;
        cin >> hour;
        hour = hour % 24;
        cout << "Enter min" << endl;
        cin >> minute;
        hour += minute / 60;
        minute = minute % 60;
    }

    Time operator+(const Time &t1) const {
        Time sum(0, 0);
        sum.minute = (this->minute + t1.minute) % 60;
        sum.hour = ((this->hour + t1.hour) + ((this->minute + t1.minute) / 60)) % 24;
        return sum;
    }


    Time operator-(const Time &t1) const {
        Time timeDiff(0, 0);
        int remain = 0;
        timeDiff.minute = (this->minute - t1.minute) % 60;
        if (timeDiff.minute < 0) {
            remain = 1;
            timeDiff.minute = (timeDiff.minute % 60) + 60;
        }
        timeDiff.hour = (this->hour - t1.hour - remain) % 24;

        if (timeDiff.hour < 0) {
            timeDiff.hour += 24;
            return timeDiff;
        }
        return timeDiff;
    }

    Time operator++() {
        minute = minute + 1;
        if (minute == 60) {
            hour += 1;
            minute = 0;
        }
        return *this;
    }

    Time operator++(int) {
        Time old_time = *this;
        minute = minute + 1;
        if (minute == 60) {
            hour += 1;
            minute = 0;
        }
        return old_time;
    }

    bool operator<(const Time &t) const{
        if (hour < t.hour) {
            return true;
        }
        if (hour == t.hour && minute << t.minute) {
            return true;
        }
        return false;
    }

    friend ostream &operator<<(ostream &output, const Time &t) {
        output << setfill('0') << fixed << setprecision(2) << setw(2) << t.hour << ":" << fixed << setprecision(2)
            << setw(2) << t.minute;
        return output;
    }
};

void print(const vector<Time> &tv) {
    for (auto &t : tv) {
        cout << t << endl;
    }
}

int main() {

    Time time1(0, 0), time2(0, 00), duration(0, 0);

    time1.read("Enter time 1");
    time2.read("Enter time 2");
    if (time1 < time2) {
        duration = time2 - time1;
        cout << "Starting time was (time1 < time2)" << time1 << endl;
    } else {
        duration = time1 - time2;
        cout << "Starting time was (time2 < time1)" << time2 << endl;
    }
    cout << "Duration was " << duration << endl;


    vector<Time> tv(5);
    for (auto &t: tv) {
        t.read("Enter time:");
    }
    cout << "Times: " << endl;
    print(tv);
    Time sum;
    for (auto t: tv) {
        sum = sum + t;
    }
    cout << "Sum of times: " << sum << endl;
    cout << "Post-increment: " << endl;
    print(tv);
    for (auto &t: tv) {
        cout << t++ << endl;
    }
    print(tv);
    cout << "Pre-increment: " << endl;
    for (auto &t: tv) {
        cout << ++t << endl;
    }
    sort(tv.begin(), tv.end());
    cout << "Sorted times: " << endl;
    print(tv);
    return 0;
}
