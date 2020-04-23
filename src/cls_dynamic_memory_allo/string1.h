//string1.h -- fixed and augmented string class defination

#ifndef STRING1_H_
#define STRING1_H_

#include <iostream>
using std::istream;
using std::ostream;

class myString
{
private:
    char *str;
    int len;
    static int num_strings;
public:
    static const int CINLIM = 80;

    //不允许隐式转换，但仍可以显示转换
    explicit myString(const char *s);
    myString();
    myString(const myString &);
    ~myString();
    int length() const { return len; }

    myString &operator=(const myString &);
    myString &operator=(const char *);
    char &operator[](int i);
    const char &operator[](int i) const;

    friend bool operator<(const myString &st1, const myString &st2);
    friend bool operator>(const myString &st1, const myString &st2);
    friend bool operator==(const myString &st1, const myString &st2);
    friend ostream &operator<<(ostream &os, const myString &st);
    friend istream &operator>>(istream &is, myString &st);

    static int HowMany();
};
#endif
