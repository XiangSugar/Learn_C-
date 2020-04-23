// mytime2.cpp -- implementing Time methods
#include "mytime.h"

Time::Time() { hours_ = minutes_ = 0; }

Time::Time(int hour, int min)
{
  hours_ = hour;
  if (min > 60)
  {
    hours_ += min / 60;
    minutes_ = min % 60;
  }
  else
    minutes_ = min;
}
void Time::AddMin(int min)
{
  minutes_ += min;
  hours_ += minutes_ / 60;
  minutes_ %= 60;
}

void Time::AddHour(int hour) { hours_ += hour; }

void Time::Reset(int h, int m)
{
  hours_ = h;
  minutes_ = m;
}

Time Time::operator+(const Time &t) const
{
  Time sum;  //因为sum不是const，所以返回类型也不必加const
  sum.minutes_ = minutes_ + t.minutes_;
  sum.hours_ = hours_ + t.hours_ + sum.minutes_ / 60;
  sum.minutes_ %= 60;
  return sum;
}

Time Time::operator-(const Time &t) const
{
  Time diff;
  int tot1, tot2;
  tot1 = t.minutes_ + 60 * t.hours_;
  tot2 = minutes_ + 60 * hours_;
  diff.minutes_ = (tot2 - tot1) % 60;
  diff.hours_ = (tot2 - tot1) / 60;
  return diff;
}

Time Time::operator*(double mult) const
{
  Time result;
  long totalminutes = hours_ * mult * 60 + minutes_ * mult;
  result.hours_ = totalminutes / 60;
  result.minutes_ = totalminutes % 60;
  return result;
}

/*
Time operator*(double mult, const Time & t){
  Time result;
  long totalminutes = t.hours_ * mult * 60 + t.minutes_ * mult;
  result.hours_ = totalminutes / 60;
  result.minutes_ = totalminutes % 60;
  return result;
}
*/

void Time::Show() const
{
  std::cout << hours_ << " hours_, " << minutes_ << " minutes";
}

std::ostream &operator<<(std::ostream &os, const Time &t)
{
  os << t.hours_ << "hours, " << t.minutes_ << " minutes" << std::endl;
  return os;
}
