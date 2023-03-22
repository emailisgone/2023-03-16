#include "time.hpp"

// 4 mod 2 = 0, time class

void Time::setHours(int number){
    if(number>23 || number<0) throw std::invalid_argument("Invalid number of hours inputted.");
    this->hours = number;
}

void Time::setMinutes(int number){    
    if(number>59 || number<0) throw std::invalid_argument("Invalid number of minutes inputted.");
    this->minutes = number;
}

void Time::setSeconds(int number){
    if(number>59 || number<0) throw std::invalid_argument("Invalid number of seconds inputted.");
    this->seconds = number;
}

int Time::getHours(){
    return this->hours;
}

int Time::getMinutes(){
    return this->minutes;
}

int Time::getSeconds(){
    return seconds;
}

std::string Time::showTimeLT(){
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

std::string Time::showTimeUK(){
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
    int total = hours*3600+minutes*60+seconds+number;

    minutes = total/60;
    seconds = total%60;
    hours = minutes/60;
    minutes %= 60;

    if(hours>=24){
        hours -= (hours/24)*24;
    }
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