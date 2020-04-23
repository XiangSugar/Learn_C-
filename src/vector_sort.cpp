// vector_sort.cpp

#include <iostream>
#include <vector>

using namespace std;
class PPoint
{
public:
    int x;
    int y;
    void show()
    {
        cout << x << " " << y << endl;
    }
};

int main()
{
    int x;
    int y;
    vector<PPoint> Center;
    //Point P[10];
    for (int i = 0; i < 5; i++)
    {
        x = i + 1;
        y = i + 2;
        PPoint p = {x, y};
        Center.push_back(p);
    }
    for (int i = 0; i < 5; i++)
    {
        Center.at(i).show();
    }
    return 0;
}
