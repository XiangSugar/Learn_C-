// usestck0.cpp -- the client program
// compile with stock00.cpp
#include "stock00.h"
#include <iostream>

int main()
{
    Stock fluffy_the_cat;   // use the defult constructor implicitly
    //Stock grament_1("Furry Mason", 50, 2.5);          //隐式调用
    //Stock grament_2 = Stock("Furry Mason", 50, 2.5);  //显示调用
    //Stock *pstock = new Stock("Electroshock Games", 18, 19.0);
    fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(300000, 40.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(300000, 0.125);
    fluffy_the_cat.show();
    return 0;
}

/*
Company: NanoSmart Shares: 20
    Share Price: $12.5 Total Worth: $250
Company: NanoSmart Shares: 35
    Share Price: $18.125 Total Worth: $634.375
You can’t sell more than you have! Transaction is aborted.
Company: NanoSmart Shares: 35
    Share Price: $18.125 Total Worth: $634.375
Company: NanoSmart Shares: 300035
    Share Price: $40.125 Total Worth: $1.20389e+007
Company: NanoSmart Shares: 35
    Share Price: $0.125 Total Worth: $4.375
*/
