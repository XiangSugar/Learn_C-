//left.cpp -- string function with a defualt argument

#include <iostream>
const int ArSize = 80;

char *left(const char *str, int n = 1);

int main()
{
    using namespace std;
    char sample[ArSize];
    cout << "Enter a string: \n";
    cin.get(sample, ArSize);

    char *ps = left(sample, 4);
    cout << ps << endl;
    delete[] ps;
    ps = left(sample);
    cout << ps << endl;
    delete[] ps;

    return 0;
}

char * left(const char * str, int n)
{
    int m = 0;
    while (m < n && str[m])
        m++;
    char *p = new char[m+1];
    int i;
    for (i = 0; i < n; i++)
        p[i] = str[i];

    while (i <= m)
        p[i++] = '\0';
    //p[i] = '\0';
    return p;
}
