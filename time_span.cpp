#include "time_span.h"
#include <cmath>
#include <iostream>
using namespace std;

TimeSpan::TimeSpan() {
    this->seconds_ = 0;

}
TimeSpan::TimeSpan(int seconds) {
    this->seconds_ = seconds;

}
TimeSpan::TimeSpan(double seconds) {
    this->seconds_ = std::round(seconds);

}
TimeSpan::TimeSpan(float seconds) {
    this->seconds_ = std::round(seconds);

}
TimeSpan::TimeSpan(int minutes, int seconds) {
    this->seconds_ = ConvertToSeconds(0, minutes, seconds);

}
TimeSpan::TimeSpan(float minutes, float seconds) {
    this->seconds_ = ConvertToSeconds(0.0, minutes, seconds);

}
TimeSpan::TimeSpan(double minutes, double seconds) {
    this->seconds_ = ConvertToSeconds(0.0, minutes, seconds);

}
TimeSpan::TimeSpan(int hours, int minutes, int seconds) {
    this->seconds_ = ConvertToSeconds(hours, minutes, seconds);

}
TimeSpan::TimeSpan(double hours, double minutes, double seconds) {
    this->seconds_ = ConvertToSeconds(hours, minutes, seconds);

}
TimeSpan::TimeSpan(const TimeSpan& ts1) {
    this->seconds_ = ts1.GetTotalSeconds();

}

//getters
int TimeSpan::hours() const {
    return this->seconds_ / 3600;
} // returns the number of hours as an int
int TimeSpan::minutes() const {
    return ((seconds_ % 3600) / 60);
}// returns the number of minutes as an int
int TimeSpan::seconds() const {
    return seconds_ % 60;
} // returns the number of Seconds as an int
int TimeSpan::GetTotalSeconds() const {
    return this->seconds_;
}


//setter
void TimeSpan::set_time(int hours, int minutes, int seconds) {
    this->seconds_ = ConvertToSeconds(hours, minutes, seconds);
}

//operators
TimeSpan TimeSpan::operator+(const TimeSpan& ts2) {
    return TimeSpan(0, 0, GetTotalSeconds() + ts2.GetTotalSeconds());
} // addition
TimeSpan TimeSpan::operator-(const TimeSpan& ts2) {
    return TimeSpan(0, 0, GetTotalSeconds() - ts2.GetTotalSeconds());

} // subtraction
TimeSpan TimeSpan::operator-() const {
    return TimeSpan(0, 0, -GetTotalSeconds());
} // unary negation

//comparison operators
bool TimeSpan::operator<=(const TimeSpan& ts2) const {
    if (this->GetTotalSeconds() <= ts2.GetTotalSeconds()) {
        return true;
    }
    else return false;
}
bool TimeSpan::operator<(const TimeSpan& ts2) const {
    if (this->GetTotalSeconds() < ts2.GetTotalSeconds()) {
        return true;
    }
    else return false;
}
bool TimeSpan::operator>(const TimeSpan& ts2) const {
    if (this->GetTotalSeconds() > ts2.GetTotalSeconds()) {
        return true;
    }
    else return false;
}
bool TimeSpan::operator>=(const TimeSpan& ts2) const {
    if (this->GetTotalSeconds() >= ts2.GetTotalSeconds()) {
        return true;
    }
    else return false;
}
bool TimeSpan::operator==(const TimeSpan& ts2) const {
    if (this->GetTotalSeconds() == ts2.GetTotalSeconds()) {
        return true;
    }
    else return false;
}
bool TimeSpan::operator!=(const TimeSpan& ts2) const {
    if (this->GetTotalSeconds() != ts2.GetTotalSeconds()) {
        return true;
    }
    else return false;
}

// assignment operators
TimeSpan TimeSpan::operator+=(const TimeSpan& ts2)
{
    this->seconds_ += ts2.GetTotalSeconds();
    return *this;
}
TimeSpan TimeSpan::operator-=(const TimeSpan& ts2)
{
    this->seconds_ -= ts2.GetTotalSeconds();
    return *this;
}
TimeSpan TimeSpan::operator=(const TimeSpan& ts2) {
    this->seconds_ = ts2.GetTotalSeconds();
    return *this;
}


std::ostream& operator<<(std::ostream& stream, const TimeSpan& ts2) {
    return stream << "Hours: " << ts2.hours() << ", Minutes: " <<  ts2.minutes() << ", Seconds: "<< ts2.seconds() << endl;
}

std::istream& operator>>(std::istream& stream, TimeSpan& ts2)
{
    int hr, min, s;
    if (stream >> hr && stream >> min && stream >> s) {
        ts2.set_time(hr, min, s);
    }
    return stream;
}

int TimeSpan::ConvertToSeconds(double hours, double minutes, double seconds) {
    return hours * 3600 + minutes * 60 + seconds;
}
int TimeSpan::ConvertToSeconds(int hours, int minutes, int seconds) {
    return hours * 3600 + minutes * 60 + seconds;
}