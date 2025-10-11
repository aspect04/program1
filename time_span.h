#ifndef TIME_SPAN_H
#define TIME_SPAN_H
#include <string>
#include <cmath>


class TimeSpan {

    public:
        TimeSpan();
        TimeSpan(int seconds);
        TimeSpan(double seconds);
        TimeSpan(float seconds);

        TimeSpan(int minutes, int seconds);

        TimeSpan(float minutes, float seconds);

        TimeSpan(double minutes, double seconds);

        TimeSpan(int hours, int minutes, int seconds);
        TimeSpan(double hours, double minutes, double seconds);

        TimeSpan(const TimeSpan& ts1);


        //getters
        int hours() const; // returns the number of hours as an int
        int minutes() const; // returns the number of minutes as an int
        int seconds() const; // returns the number of Seconds as an int
        int GetTotalSeconds() const;

        //setter
        void set_time(int hours, int minutes, int seconds); //set the number of hours, minutes, seconds.

        //operators
        TimeSpan operator+(const TimeSpan& ts2); // addition
        TimeSpan operator-(const TimeSpan& ts2); // subtraction
        TimeSpan operator-() const; // unary negation

        //comparison operators
        bool operator<=(const TimeSpan& ts2) const;
        bool operator<(const TimeSpan& ts2) const;
        bool operator>(const TimeSpan& ts2) const;
        bool operator>=(const TimeSpan& ts2) const;
        bool operator==(const TimeSpan& ts2) const;
        bool operator!=(const TimeSpan& ts2) const;

        //assignment operators
        TimeSpan operator+=(const TimeSpan& ts2);
        TimeSpan operator-=(const TimeSpan& ts2);


        TimeSpan operator=(const TimeSpan& ts2);

        friend std::ostream& operator<<(std::ostream& stream, const TimeSpan& ts2);
        friend std::istream& operator>>(std::istream& stream, const TimeSpan& ts2);



    private:
        int seconds_; //60s->1min, 3600s-> 1hr

        static int ConvertToSeconds(int hours, int minutes, int seconds);
        int ConvertToSeconds(double hours, double minutes, double seconds);



};


#endif //TIME_SPAN_H