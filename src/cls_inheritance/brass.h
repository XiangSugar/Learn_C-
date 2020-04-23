// brass.h -- bank account class

#ifndef BRASS_H_
#define BRASS_H_

#include <string>

class Brass
{
private:
    std::string fullName;
    long  acctNum;
    double balance;
public:
    Brass(const std::string &s = "Nullbody", long an = -1,
          double bl = 0.0);
    void Deposit(double atm);
    double Balance() const;

    //编译器对虚方法使用动态联编

    virtual void Withdraw(double atm);
    virtual void ViewAcct() const;
    //虚析构函数将调用相应对象类型的析构函数
    virtual ~Brass() {};
};

class BrassPlus : public Brass
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string &s = "NullBody", long an = -1,
              double bl = 0.0, double ml = 500,
              double r = 0.11125);
    BrassPlus(const Brass &ba, double ml = 500, double r = 0.11125);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) { maxLoan = m; };
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
};

#endif
