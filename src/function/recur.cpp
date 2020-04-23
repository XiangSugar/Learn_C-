/*------------------
    2019.10.14
    递归的简单实例
//----------------*/

#include <iostream>

void countdown(int n);

int main()
{
    countdown(4);
    double temp;
    // char test[5] = {'1', '2', '3', '4', '\0'};
    // std::cout << test << std::endl;
    std::cin >> temp;
    return 0;
}

void countdown(int n)
{
    using namespace std;
    cout << "Counting down ... " << n << "(n at " << &n << ")" << endl;
    if (n >0)
        countdown(n - 1);
    cout << n << ": Kaboom!" << "         (n at " << &n << ")" << endl;
}
