// newplace.cpp -- using placement new (定位 new 运算符)

#include <iostream>
#include <new> // for placement new

const int BUF = 512;
const int N = 5;
char buffer[BUF]; // chunk of memory

int main()
{
    using namespace std;

    double *pd1, *pd2;
    int i;
    cout << "Calling new and placement new:\n";
    pd1 = new double[N];          // use heap
    pd2 = new (buffer) double[N]; // use buffer array
    for (i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 20.0 * i;
    cout << "Memory addresses:\n"
         << "  heap: " << pd1 << "  static: " << (void *)buffer << endl;
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    cout << "\nCalling new and placement new a second time:\n";
    double *pd3, *pd4;
    pd3 = new double[N];          // find new address
    pd4 = new (buffer) double[N]; // overwrite old data
    for (i = 0; i < N; i++)
        pd4[i] = pd3[i] = 1000 + 40.0 * i;
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd3[i] << " at " << &pd3[i] << "; ";
        cout << pd4[i] << " at " << &pd4[i] << endl;
    }
    cout << "\nCalling new and placement new a third time:\n";
    delete[] pd1;
    pd1 = new double[N];
    pd2 = new (buffer + N * sizeof(double)) double[N];
    for (i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 60.0 * i;
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }
    delete[] pd1;
    delete[] pd3;
    cin.get();
    return 0;
}

/*
Calling new and placement new:
Memory addresses:
  heap: 0x731750  static: 0x408040
Memory contents:
1000 at 0x731750; 1000 at 0x408040
1020 at 0x731758; 1020 at 0x408048
1040 at 0x731760; 1040 at 0x408050
1060 at 0x731768; 1060 at 0x408058
1080 at 0x731770; 1080 at 0x408060

Calling new and placement new a second time:
Memory contents:
1000 at 0x731ac0; 1000 at 0x408040
1040 at 0x731ac8; 1040 at 0x408048
1080 at 0x731ad0; 1080 at 0x408050
1120 at 0x731ad8; 1120 at 0x408058
1160 at 0x731ae0; 1160 at 0x408060

Calling new and placement new a third time:
Memory contents:
1000 at 0x731750; 1000 at 0x408068
1060 at 0x731758; 1060 at 0x408070
1120 at 0x731760; 1120 at 0x408078
1180 at 0x731768; 1180 at 0x408080
1240 at 0x731770; 1240 at 0x408088
*/
