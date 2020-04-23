// vect.h -- Vector class woth <<, mode state
#ifndef VECT_H_
#define VECT_H_
#include <iostream>

namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode
        {
            RECT,
            POL
        };
    private:
        double x_;
        double y_;
        double mag_;
        double ang_;
        Mode mode_;

        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const { return x_;}
        double yval() const { return y_;}
        double magval() const { return mag_;}
        double angval() const { return ang_;}
        void polar_mode();
        void rect_mode();

        Vector operator+(const Vector &b) const;
        Vector operator-(const Vector &b) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        friend Vector operator*(double n, const Vector &a);
        friend std::ostream &operator<<(std::ostream &os, const Vector &v);

    };
}   //end namespace VECTOR
#endif
