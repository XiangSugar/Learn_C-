// stock00.h -- stock calss interface
// version 00

#ifndef STOCH_H_
#define STOCK_H_

#include <string>

class Stock
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }

public:
    Stock(); //默认构造函数
    Stock(const std::string &co, long n,
          double pr); //定义了非默认构造函数，则程序员必须自己定义默认构造函数
    ~Stock();
    void acquire(const std::string &co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;      //const 成员函数
}; // note semicolon at the end

#endif
