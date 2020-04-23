//arfupt.cpp  --  an array of function pointers

#include <iostream>

//various notations, same siganatures
const double * f1(const double ar[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);

int main()
{
    using namespace std;

    double av[3] = {1000, 2000, 3000};

    //pointer to a function
    const double * (*p1)(const double *, int) = f1;
    auto p2 = f2;  //C++11 automatatic type deduction
    //pre-C++11 can use the following code instead
    //const double * (*p2)(const double *, int) = f2;
    cout << "Using pointers to functions:\n";
    cout << " Address   Value\n";
    //(*p1)(av, 3)和p2(av, 3)都将调用指向的函数（即f1()和f2()）
    //但由于f1,f2的返回值为指向double的指针，因此如果要查看其内容，还需要再用 *
    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << ": " << *p2(av, 3) << endl;

    //pa an array of pointers to functions
    //auto doesn't work with list initialization
    const double *(*pa[3])(const double *, int) = {f1, f2, f3};
    //but it does work for initializing to a single value
    //pb a pointer to first element of pa
    auto pb = pa;
    //pre-C++ can use the following code instead
    //const double *(**pb)(const double *, int) = pa;
    cout << "\nUsing an array of pointers to functions:\n";
    cout << "Address   Value\n";
    for (int i = 0; i < 3; i++)
        cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
    cout << "\nUsing a pointer to a pointer to a function:\n";
    cout << "Address   Value\n";
    for (int i = 0; i < 3; i++)
        cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;

    //what about a pointer to an array of function pointers
    cout << "\nUsing pointers to an array of pointers:\n";
    cout << "Address   Value\n";
    //easy way to declare pc
    auto pc = &pa;
    //pre C++11 can use the following code instead
    //const double * (*(*pc)[3])(const double *, int) = &pa;
    cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
    //hard way to declare pd
    const double *(*(*pd)[3])(const double *, int) = &pa;
    //store return value in pdb
    const double *pdb = (*pd)[1](av, 3);
    cout << pdb << ": " << *pdb << endl;
    //alternative notation
    cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;

    double temp;
    cin >> temp;
    return 0;
}

//some rather dull function

//返回值全为 double 类型的指针
const double * f1(const double * ar, int n)
{
    return ar;
}
const double * f2(const double ar[], int n)
{
    return ar + 1;
}
const double * f3(const double ar[], int n)
{
    return ar + 2;
}
