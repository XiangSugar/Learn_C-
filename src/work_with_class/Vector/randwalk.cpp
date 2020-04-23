// randwalk.cpp
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "vect.h"

int main()
{
    using namespace VECTOR;
    using std::cin;
    using std::cout;
    using std::endl;

    srand(time(0));
    double dis_step;
    double target_dis;
    double direction;
    long steps;
    Vector result(0.0, 0.0);
    Vector step;

    cout << "Enter the target distance:(q to quit) " << endl;
    while(cin >> target_dis)
    {
        cout << "Enter the distance of each step: ";
        cin >> dis_step;
        while(result.magval() < target_dis)
        {
            direction = rand() % 360;
            step.reset(dis_step, direction, Vector::POL);
            result = result + step;
            steps++;
        }

        cout << "After " << steps << " steps, the subject has the following location:"
             << endl;
        cout << result << endl;
        result.polar_mode();
        cout << "or in the pol mode: " << result << endl;
        cout << "Anverage outward distance per step = "
             << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter the target distance:(q to quit) " << endl;
    }
    cout << "Bye!" << endl;
    cin.clear();
    while(cin.get() != '\n')
        continue;

    return 0;
}
