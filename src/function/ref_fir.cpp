//firstref.cpp -- defining and using a reference
#include <iostream>
int main()
{
    using namespace std;
    int rats = 101;
    //必须在申明引用变量时对其初始化
    //一旦与某个变量相关联，就将一直效忠于它
    int & rodents = rats;  //rodent is a reference
    //等价于 int * const pr = &art;  //其中 *pr 和 rodent 扮演的角色相同
    cout << "rats = " << rats;
    cout << ",  rodents = " << rodents <<endl;
    rodents++;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    //some implementations require type casting the following
    //address to type unsigned
    cout << "rats address = " << &rats << endl;
    cout << "rodents address = " << &rodents << endl;

    return 0;
}
//如果看到有关临时变量的警告，请不要忽略
