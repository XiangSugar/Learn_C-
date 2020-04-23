// namespace_1.cpp

#include <iostream>

namespace Jill {
    double bucket(double n) {  return n; }
    double fetch;
    struct Hill {int a; double b;};
}
char fetch;
int main()
{
    using namespace std;   // using 编译指令
    using Jill::fetch;     // put fetch into local namespace  (using 申明)
    //double fetch;        // Error! Already have a local fetch
    cin >> fetch;          // read a value into Jill::fetch
    cin >> ::fetch;        // read a value into global fetch ...
}
