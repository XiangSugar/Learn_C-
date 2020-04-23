//ref_sec.cpp  --  defining and using a reference

#include <iostream>
int main()
{
    using namespace std;
    int rats = 101;
    int &rodents = rats;

    cout << "rats = " << rats;
    cout << ",  rodents = " << rodents << endl;

    cout << "rats address = " << &rats << endl;
    cout << "rodents address = " << &rodents << endl;

    int bunnies = 50;

    rodents = bunnies; //can we change the reference? In fact we can't.
                       //等价于 rats = bunnies;
                       //仅仅只是改变了 rodents 引用的变量（rats）的值，
                       //但并不能让 rodents 变为 bunnies 的引用
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ",  rodents = " << rodents << endl;

    cout << "bunnies address = " << &bunnies << endl;
    cout << "rodents address = " << &rodents << endl;

    return 0;
}

/*-------------------------------------

ats = 101,  rodents = 101
rats address = 0x61fe0c
rodents address = 0x61fe0c
bunnies = 50, rats = 50,  rodents = 50
bunnies address = 0x61fe08
rodents address = 0x61fe0c

-------------------------------------*/
