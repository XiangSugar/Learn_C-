/*----------------------------
    2019.10.14
    利用递归模拟刻画直尺的刻度
----------------------------*/

#include <iostream>

int Ruler_Length = 66;
int Divs = 10;

void subdivide(char ar[], int low, int high, int lev);

int main()
{
    using namespace std;

    char ruler[Ruler_Length];
    for (int i = 1; i < Ruler_Length-2; i++)
    {
        ruler[i] = ' ';
    }
    ruler[Ruler_Length-1] = '\0';
    ruler[Ruler_Length - 2] = '|';
    ruler[0] = '|';
    cout << ruler << endl;

    for (int i = 1; i <= Divs; i++)
    {
        subdivide(ruler, 0, Ruler_Length - 2, i);
        cout << ruler << endl;
        for (int i = 1; i < Ruler_Length-2; i++)
        {
            ruler[i] = ' ';
        }
    }
    double temp;
    cin >> temp;
    return 0;
}

void subdivide(char ar[], int low, int high, int lev)
{
    if (lev == 0)
        return;
    int mid = (low + high) / 2;
    ar[mid] = '|';
    subdivide(ar, low, mid, lev - 1);
    subdivide(ar, mid, high, lev - 1);
    return;
}

/*该程序不完善，因为递归深度需要自己事先指定，而且必须要指定为比最大深度小的值，如果Divs不合理（过大），则后面做的是无用功
eg: 上述程序当 Divs = 10 时的运行结果
|                                                               |
|                               |                               |
|               |               |               |               |
|       |       |       |       |       |       |       |       |
|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/
