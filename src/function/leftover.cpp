// leftover.cpp -- overloading the left() function

// left.cpp -- string function with a defualt argument

#include <iostream>

unsigned long left(unsigned long num, unsigned ct);
char *left(const char *str, int n = 1);

int main() {
    using namespace std;
    const char *trip = "Hawaii!!";    //test value
    unsigned long n = 12345678; // test value
    int i;
    char *temp;

    for (i = 1; i < 10; i++)
    {
        cout << left(n, i) << endl;
        temp = left(trip, i);
        cout << temp << endl;
        delete[] temp;
    }

    return 0;
}

unsigned long left(unsigned long num, unsigned ct)
{
    unsigned digits = 1;
    unsigned long n = num;

    if (ct == 0 || num == 0)
        return 0;
    while (n /= 10)
        digits++;
    if (digits > ct)
    {
        ct = digits - ct;
        while (ct--)
            num /= 10;
        return num;
    }
    else            //if ct >= digits, return the hole number
        return num;
}

//This function returns a pointer to a new string
//consisting of the first n characters in the str string
char *left(const char *str, int n) {
    int m = 0;
    while (m < n && str[m])
        m++;
    char *p = new char[m+1];
    int i;
    for (i = 0; i < n; i++)
        p[i] = str[i];
    //while (i <= m)
        //p[i++] = '\0';
    p[i] = '\0';
    return p;
}

/*
函数重载何时使用：
仅当函数基本上执行相同的任务，但使用不同形式的数据时，才应采用函数重载
*/
