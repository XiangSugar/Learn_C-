// mytime.h  --  Time cladd after operator overloading

#ifndef MYTIME_H_
#define MYTIME_H_

#include <iostream>

class Time
{
private:
    int hours_;
    int minutes_;
public:
    Time();
    Time(int hour, int min = 0);
    void AddMin(int min);
    void AddHour(int hour);
    void Reset(int hour = 0, int min = 0);
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(double n) const;     //运算符重载
    friend Time operator*(double m, const Time & t)    //友元函数
    {
        return t * m;   //inline defination
    }
    void Show() const;
    //friend void operator<<(ostream os, const Time & t);
    friend std::ostream & operator<<(std::ostream & os, const Time & t);

};

#endif
