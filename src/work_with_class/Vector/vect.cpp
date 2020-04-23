//#include<iostream>
#include<cmath>
#include "vect.h"

namespace VECTOR
{
    const double Rad_to_deg = 45.0 / std::atan(1.0);
    void Vector::set_mag()
    {
        mag_ = sqrt((x_ * x_) + (y_ * y_));
    }
    void Vector::set_ang()
    {
        if (x_ == 0 && y_ == 0)
            ang_ == 0.0;
        else
            ang_ = atan2(y_, x_);
    }
    void Vector::set_x()
    {
        x_ = mag_ * cos(ang_);
    }
    void Vector::set_y()
    {
        y_ = mag_ * sin(ang_);
    }

    Vector::Vector()
    {
        mode_ = RECT;
        x_ = 0;
        y_ = 0;
        mag_ = 0;
        ang_ = 0;
    }
    Vector::Vector(double n1, double n2, Mode form)
    {
        if (RECT == form)
        {
            mode_ = form;
            x_ = n1;
            y_ = n2;
            set_mag();
            set_ang();
        }
        else if (POL == form)
        {
            mode_ = form;
            mag_ = n1;
            ang_ = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            std::cout << "Incorrct 3rd argument to Vector() -- ";
            std::cout << "vector set to 0.\n";
            x_ = y_ = mag_ = ang_ = 0;
            mode_ = RECT;
        }
    }
    void Vector::reset(double n1, double n2, Mode form)
    {
        if (RECT == form)
        {
            mode_ = form;
            x_ = n1;
            y_ = n2;
            set_mag();
            set_ang();
        }
        else if(POL == form)
        {
            mode_ = form;
            mag_ = n1;
            ang_ = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            std::cout << "Incorrct 3rd argument to Vector() -- ";
            std::cout << "vector set to 0.\n";
            x_ = y_ = mag_ = ang_ = 0;
            mode_ = RECT;
        }
    }
    Vector::~Vector(){};

    void Vector::polar_mode()
    {
        mode_ = POL;
    }
    void Vector::rect_mode()
    {
        mode_ = RECT;
    }
    Vector Vector::operator+(const Vector &b) const
    {
        return Vector(x_ + b.x_, y_ + b.y_);
    }
    Vector Vector::operator-(const Vector &b) const
    {
        return Vector(x_ - b.x_, y_ - b.y_);
    }
    Vector Vector::operator-() const
    {
        return Vector(-x_, -y_);
    }
    Vector Vector::operator*(double n) const
    {
        return Vector(n * x_, n * y_);
    }
    Vector operator*(double n, const Vector &a)
    {
        return a * n;
    }
    std::ostream &operator<<(std::ostream &os, const Vector &v)
    {
        if (Vector::RECT == v.mode_)
            os << "(x, y) = (" << v.x_ << ", " << v.y_ << ")" << std::endl;
        else if (Vector::POL == v.mode_)
            os << "(m, a) = (" << v.mag_ << ","
               << v.ang_ * Rad_to_deg << ")" << std::endl;
        else
            std::cout << "Vector object mode is ivalid!\n";
        return os;
    }
}
