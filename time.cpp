#include "time.hpp"

// 4 mod 2 = 0, time class

inline void Time::setHours(int number){
    if(number>23 || number<0) throw std::invalid_argument("Invalid number of hours inputted.");
    hours = number;
}

inline void Time::setMinutes(int number){    
    if(number>59 || number<0) throw std::invalid_argument("Invalid number of minutes inputted.");
    minutes = number;
}

inline void Time::setSeconds(int number){
    if(number>59 || number<0) throw std::invalid_argument("Invalid number of seconds inputted.");
    seconds = number;
}

inline int Time::getHours() const{
    return this->hours;
}

inline int Time::getMinutes() const{
    return this->minutes;
}

inline int Time::getSeconds() const{
    return seconds;
}

std::string Time::showTimeLT() const{
    std::string res, hr, min, sec;
    hr = std::to_string(hours);
    min = std::to_string(minutes);
    sec = std::to_string(seconds);
    if(hours>=0 && hours<=9){
        hr = "0"+hr;
    }
    if(minutes>=0 && minutes<=9){
        min = "0"+min;
    }
    if(seconds>=0 && seconds<=9){
        sec = "0"+sec;
    }
    res = hr+":"+min+":"+sec;
    return res;
}

std::string Time::showTimeUK() const{
    std::string res, min;
    min = std::to_string(minutes);
    if(minutes>=0 && minutes<=9){
        min = "0"+min;
    }
    if(hours>=12 && hours<=24){
        int uk = hours-12;
        if(uk==0) uk = 12;
        res = std::to_string(uk)+":"+min+" PM";
    }
    else{
        int uk = hours;
        if(hours==0) uk = 12;
        res = std::to_string(uk)+":"+min+" AM";
    }
    return res;
}

void Time::addSeconds(int number){
    if(number<0) throw std::invalid_argument("addSeconds(int): Negative number imputted.");
    int total = hours*3600+minutes*60+seconds+number;

    minutes = total/60;
    seconds = total%60;
    hours = minutes/60;
    minutes %= 60;

    if(hours>=24){
        hours -= (hours/24)*24;
    }
}

void Time::reduceSeconds(int number){
    if(number<0) throw std::invalid_argument("reduceSeconds(int): Negative number imputted.");
    int total = hours*3600+minutes*60+seconds-number;

    if(total<0)
        total = (total%86400 + 86400)%86400;
        
    minutes = total/60;
    seconds = total%60;
    hours = minutes/60;
    minutes %= 60;

    if(hours>=24){
        hours -= (hours/24)*24;
    }
}

Time operator+(const Time& time1, const Time& time2){
    Time newTime = time1;
    newTime.addSeconds(time2.getHours()*3600 + time2.getMinutes()*60 + time2.getSeconds());
    return newTime;
}

Time operator+(const Time& time, const int& seconds){
    Time newTime = time;
    if(seconds<0)
        newTime.reduceSeconds(-1*seconds);
    else
        newTime.addSeconds(seconds);
    return newTime;
}

Time operator+(const int& seconds, const Time& time){
    Time newTime = time;
    if(seconds<0)
        newTime.reduceSeconds(-1*seconds);
    else
        newTime.addSeconds(seconds);
    return newTime;
}

Time& Time::operator+=(const Time& time){
    this->addSeconds(time.getHours()*3600 + time.getMinutes()*60 + time.getSeconds());
    return *this;
}

Time& Time::operator+=(const int& seconds){
    if(seconds<0)
        this->reduceSeconds(-1*seconds);
    else
        this->addSeconds(seconds);
    return *this;
}

bool operator<(const Time& lhs, const Time& rhs){
    int lhsSeconds = lhs.getHours()*3600 + lhs.getMinutes()*60 + lhs.getSeconds(),
    rhsSeconds = rhs.getHours()*3600 + rhs.getMinutes()*60 + rhs.getSeconds();

    return lhsSeconds < rhsSeconds;
}

bool operator>(const Time& lhs, const Time& rhs){
    return rhs < lhs;
}

bool operator<=(const Time& lhs, const Time& rhs){
    return !(lhs > rhs);
}

bool operator>=(const Time& lhs, const Time& rhs){
    return !(lhs < rhs);
}

bool operator==(const Time& lhs, const Time& rhs){
    int lhsSeconds = lhs.getHours()*3600 + lhs.getMinutes()*60 + lhs.getSeconds(),
    rhsSeconds = rhs.getHours()*3600 + rhs.getMinutes()*60 + rhs.getSeconds();

    return lhsSeconds == rhsSeconds;
}

bool operator!=(const Time& lhs, const Time& rhs){
    return !(lhs == rhs);
}

std::ostream& Time::operator<<(std::ostream& os){
    os << this->showTimeLT();
    return os;
}

std::ostream& operator<<(std::ostream& os, const Time& time){
    os << time.showTimeLT();
    return os;
}

std::istream& operator>>(std::istream& is, Time& time){
    int hours, minutes, seconds;
    is >> hours >> minutes >> seconds; // LT format
    time.setSeconds(seconds);
    time.setMinutes(minutes);
    time.setHours(hours);
    // if ( )
    //   is.setstate(std::ios::failbit);        // validate hours/minutes/seconds   
    return is;
}

Time& Time::operator++(){
    setSeconds(getSeconds()+1);
    return *this;
}

Time Time::operator++(int){
    Time old = *this;
    operator++();
    return old;
}

Time& Time::operator--(){
    setSeconds(getSeconds()-1);
    return *this;
}

Time Time::operator--(int){
    Time old = *this;
    operator--();
    return old;
}

Time::Time(){
    this->setHours(0);
    this->setMinutes(0);
    this->setSeconds(0);
}

Time::Time(int hr, int min = 0, int sec = 0){
    this->setHours(hr);    
    this->setMinutes(min);
    this->setSeconds(sec);
}

Time::~Time(){
    // Uzkomentavau, nes trukde 2 uzd.
    //printf("\nClass \"Time\" terminated.");
}