#include <iostream>
#include <array>
#include <string>

const int Seasions = 4;
const std::array<std::string, Seasions> Snames =
    {"Spring", "Summer", "Fall", "Winnter"};

void fill(std::array<double, Seasions> *pa);
void show(std::array<double, Seasions> da);

int main()
{
    std::array<double, Seasions> expenses;
    fill(&expenses);
    show(expenses);

    double temp;
    std::cin >> temp;
    return 0;
}

void fill(std::array<double, Seasions> * pa)
{
    using namespace std;
    for (int i = 0; i < Seasions; i++)
    {
        cout << "Enter" << Snames[i] << "expenses: ";
        cin >> (*pa)[i];
    }
}

void show(std::array<double, Seasions> da)
{
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasions; i++)
    {
        cout << Snames[i] << ": $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses: $" << total << endl;
}
