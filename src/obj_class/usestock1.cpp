// usestok1.cpp -- using the Stock class
// compile with stock10.cpp
#include "stock10.h"
#include <iostream>

int main()
{
    {   //这里加大括号是为了能够在程序结束之前进行析构，便于我们观察
        using std::cout;
        cout << "Using constructors to create new objects\n";
        Stock stock1("NanoSmart", 12, 20.0); // syntax 1
        stock1.show();
        //初始化，下面的语句有两种方式来执行，一种和上面一样，一种创建临时对象，并复制（两种都可以）
        Stock stock2 = Stock("Boffo Objects", 2, 2.0); // syntax 2
        stock2.show();
        cout << "Assigning stock1 to stock2:\n";
        stock2 = stock1;    //object assignment
        cout << "Listing stock1 and stock2:\n";
        stock1.show();
        stock2.show();
        cout << "Using a constructor to reset an object\n";
        stock1 = Stock("Nifty Foods", 10, 50.0); //赋值， stock1 已经存在，因此创建temp object再复制进去
        cout << "Revised stock1:\n";
        stock1.show();
        cout << "Done\n";
        //自动变量被放在栈里面，先进后出，因此会先析构 stock2
    }
    std::cin.get();
    return 0;
}

/*
Using constructors to create new objects
Constructor using NanoSmart called
Company: NanoSmart Shares: 12
    Share Price: $20.00 Total Worth: $240.00
Constructor using Boffo Objects called
*****Bye, Boffo Objects!*****                         //addition line
Company: Boffo Objects Shares: 2
    Share Price: $2.00 Total Worth: $4.00
Assigning stock1 to stock2:
Listing stock1 and stock2:
Company: NanoSmart Shares: 12
    Share Price: $20.00 Total Worth: $240.00
Company: NanoSmart Shares: 12
    Share Price: $20.00 Total Worth: $240.00
Using a constructor to reset an object
Constructor using Nifty Foods called
Bye, Nifty Foods!
Revised stock1:
Company: Nifty Foods Shares: 10
    Share Price: $50.00 Total Worth: $500.00
Done
Bye, NanoSmart!
Bye, Nifty Foods!
*/

/* NOTE:
When you assign one object to another of the same class, by default
C++ copies the contents of each data member of the source object to
the corresponding data member of the target object.
*/
