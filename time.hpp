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

    int getHours();
    int getMinutes();
    int getSeconds();

    std::string showTimeLT();
    std::string showTimeUK();

    void addSeconds(int number);
};

#endif
