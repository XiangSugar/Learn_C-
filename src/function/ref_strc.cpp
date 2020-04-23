//ref_strc.cpp -- using structure references

#include <iostream>
#include <string>

struct free_throws
{
    std::string name;
    int made;
    int attempts;
    float percent;
};

void display(const free_throws &ft);
void set_pc(free_throws &ft);
free_throws &accumulate(free_throws &target, const free_throws &source);

int main()
{
    free_throws one = {"Ifelsa Branch", 13, 14};
    free_throws two = {"Andor Knott", 10, 16};
    free_throws three = {"Minnie", 7, 9};
    free_throws four = {"Whily Looper", 5, 9};
    free_throws five = {"Long Long", 6, 14};
    free_throws team = {"Throwgoods", 0, 0};

    free_throws dup;

    set_pc(one);
    display(one);
    accumulate(team, one);
    display(team);
    display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    display(team);

    //返回引用与传统返回机制的不同之处在于
    //直接将 team 赋值给 dup，而不是先创建临时变量存储 team 的内容
    //然后再将临时变量赋值给 dup，效率更高
    dup = accumulate(team, five);

    std::cout << "Display team:\n";
    display(team);
    std::cout << "\nDisplay dup after assignment:\n";
    display(dup);
    set_pc(four);

    //该语句合法
    //赋值语句中，左边必须是可以修改的左值，也就是说左边的子表达式必须标识一个可以修改的内存块
    //而这里，函数返回指向 dup 的引用，其标识的确实是这样一个内存块
    //如果 accumulate 函数原型中在最前面加了 const，则不能再这样使用，此时返回的是不可修改的左值
    //const free_throws & accumulate(*, *) {}
    accumulate(dup, five) = four;
    std::cout << "\nDisplay dup after ill-advised assignment:\n";
    display(dup);

    return 0;
}

//不需要改变变量的值，故用 const
void display(const free_throws &ft)
{
    using namespace std;
    cout << "Name: " << ft.name << '\n';
    cout << "  Made: " << ft.made << '\t';
    cout << "Attempts: " << ft.attempts << '\t';
    cout << "Percent: " << ft.percent << '\n';
}

void set_pc(free_throws &ft)
{
    if (ft.attempts != 0)
        ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
    else
        ft.percent = 0;
}

//该函数返回一个 free_throws 引用
//返回引用的函数，实际上是被引用变量的别名
//accumulate() 相当于 target
free_throws &accumulate(free_throws &target, const free_throws &source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);
    return target;
}

/*------------------------------------------------------
Name: Ifelsa Branch
  Made: 13      Attempts: 14    Percent: 92.8571
Name: Throwgoods
  Made: 13      Attempts: 14    Percent: 92.8571
Name: Throwgoods
  Made: 23      Attempts: 30    Percent: 76.6667
Name: Throwgoods
  Made: 35      Attempts: 48    Percent: 72.9167
Display team:
Name: Throwgoods
  Made: 41      Attempts: 62    Percent: 66.129

Display dup after assignment:
Name: Throwgoods
  Made: 41      Attempts: 62    Percent: 66.129

Display dup after ill-advised assignment:
Name: Whily Looper
  Made: 5       Attempts: 9     Percent: 55.5556
------------------------------------------------------*/

/*

返回引用时，应避免返回函数终止时不再存在的内存单元引用。eg:
const free_throws & clone2(free_throws & ft)
{
    free_throws newguy;
    newguy = ft;
    return newguy;
}

正确的做法是：
1. 返回一个作为参数传递给函数的引用，正如上面的 accumulatea 函数那样
2. 用 new 来分配新的存储空间

*/
