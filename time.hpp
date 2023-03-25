#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

enum timeFormat{
    LT,
    UK
};

// Nr. 1
class Time{
    private:
    int hours;
    int minutes;
    int seconds;

    public:
    Time();
    Time(int hr, int min, int sec);
    ~Time();

    void setHours(int number);
    void setMinutes(int number);
    void setSeconds(int number);

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    std::string showTimeLT() const;
    std::string showTimeUK() const;

    void addSeconds(int number);

    friend Time operator+(const Time& time1, const Time& time2);
    friend Time operator+(const Time& time, const int& seconds);
    friend Time operator+(const int& seconds, const Time& time);
    Time& operator+=(const Time& time);
    Time& operator+=(const int& seconds);
    friend bool operator<(const Time& lhs, const Time& rhs);
    friend bool operator>(const Time& lhs, const Time& rhs);
    friend bool operator<=(const Time& lhs, const Time& rhs);
    friend bool operator>=(const Time& lhs, const Time& rhs);
    friend bool operator==(const Time& lhs, const Time& rhs);
    friend bool operator!=(const Time& lhs, const Time& rhs);
    std::ostream& operator<<(std::ostream& os);
    friend std::ostream& operator<<(std::ostream& os, const Time& time);
    friend std::istream& operator>>(std::istream& is, Time& time);
    Time& operator++();
    Time operator++(int);
    Time& operator--();
    Time operator--(int);
};

#endif
