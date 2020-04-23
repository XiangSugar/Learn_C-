// vegnews.cpp -- using new and delete with classes
// compile with strngbad.cpp
#include <iostream>
using std::cout;
#include "strngbad.h"
void callme1(StringBad &);
void callme2(StringBad);
// pass by reference
// pass by value
int main()
{
    using std::endl;
    {
        cout << "Starting an inner block.\n";
        StringBad headline1("AAAAAAAAAA");
        StringBad headline2("BBBBBBBBBB");
        StringBad sports("CCCCCCCCCC");
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);     //使用复制构造函数
        cout << "headline2: " << headline2 << endl;
        cout << "Initialize one object to another:\n";
        StringBad sailor = sports;  //调用复制构造函数
        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to another:\n";
        StringBad knot;     //will creat new object using defualt constructor
        knot = headline1;   //使用重载的赋值运算符
        cout << "knot: " << knot << endl;
        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";
    return 0;
}
void callme1(StringBad &rsb)
{
    cout << "String passed by reference:\n";
    cout << "   \"" << rsb << "\"\n";
}
void callme2(StringBad sb)
{
    cout << "String passed by value:\n";
    cout << "   \"" << sb << "\"\n";
}

/*
1. 当使用一个对象来初始化另一个对象时，编译器将自动生成默认构造函数来完成这一操作
StringBad::StringBad(const StringBad & obj)
2. 注意赋值运算符的重载写法
*/
