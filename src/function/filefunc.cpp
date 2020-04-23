//filefunc.cpp -- function with ostream & parameter

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream &os, double fo, const double fe[], int n);
const int LIMIT = 5;

int main()
{
    ofstream fout;
    const char *fn = "ep-data.txt";
    fout.open(fn);
    if (!fout.is_open())
    {
        cout << "Can't open " << fn << ". Bye\n";
        exit(EXIT_FAILURE);  // EXIT_FAILURE = 1
    }
    double objective;
    //输入物镜焦距
    cout << "Enter the focal length of your "
            "telescope objective in mm: ";
    cin >> objective;
    //用于存储目镜焦距
    double eps[LIMIT];
    cout << "Enter the focal length, in mm, of " << LIMIT
         << " eyepieces:\n";
    for(int i = 0; i < LIMIT; i++)
    {
        cout << "Eyepiece #" << i + 1 << ": ";
        cin >> eps[i];
    }
    //写入到文件
    file_it(fout, objective, eps, LIMIT);
    //输出到屏幕
    file_it(cout, objective, eps, LIMIT);

    cout << "Done\n";

    return 0;
}

void file_it(ostream & os, double fo, const double fe[], int n)
{
    ios_base::fmtflags initial;  //int
    //还函数返回调用它之前有效的所有格式化设置，并赋值给 initial
    initial = os.setf(ios::fixed);
    os.precision(0);
    os << "Focal length of objective: " << fo << " mm\n";
    //显示小数点的模式。即使小数部分为零
    os.setf(ios::showpoint);
    //指定显示几位小数
    os.precision(1);
    //设置下一次输出操作使用的字段宽度
    //这种设置方式只在显示下一个值时才有效
    //之后将恢复到默认设置
    os.width(12);
    os << "f.1. eyepiece";
    os.width(15);
    os << "magnification" << endl;
    for (int i = 0; i < n; i++)
    {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int(fo / fe[i] + 0.5) << endl;
    }
    os.setf(initial);  //restore initial formatting state
}
