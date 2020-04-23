// bank.cpp -- using the Queue interface
// compile with queue.cpp
#include "queue.h"
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <iostream>

const int MIN_PER_HR = 60;
bool newcustomer(double x); // is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    // setting things up
    std::srand(std::time(0)); //random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Please enter the max length of the queue: ";
    int maxlen;
    cin >> maxlen;
    Queue line(maxlen);
    cout << "Please enter the simulation time(hours): ";
    int hours;
    cin >> hours;
    long cycle_limit = hours * MIN_PER_HR;
    cout << "Enter the average number of customers per hour: ";
    double perhour; // average # of arrival per hour
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;          //new customer data
    long turnaways = 0; // turned away by full queue
    long customers = 0; //joined the queue
    long served = 0;    //served during the simulation
    long sum_line = 0;  //cumulative line length
    int wait_time = 0;  //time until autoteller is free
    long line_wait = 0; //cumulative time in line

    for (int cycle = 0; cycle < cycle_limit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (line.isfull())
                turnaways++;
            else
            {
                temp.set(cycle);
                line.enqueue(temp);
                customers++;
            }
        }
        if (wait_time <= 0 && !line.isempty())
        {
            line.dequeue(temp);
            wait_time = temp.ptime();
            served++;
            line_wait += cycle - temp.when();
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.queuecount();
    }

    //result reporting
    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl;
        cout << " customers served: " << served << endl;
        cout << "turnaways : " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cycle_limit << endl;
        cout << " average wait time: "
             << (double) line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";

    return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
