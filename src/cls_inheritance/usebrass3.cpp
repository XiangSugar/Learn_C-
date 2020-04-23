// usebrass2.cpp -- polymorphic example
// compile with brass.cpp
#include "acctabc.h"
#include <iostream>
#include <string>

const int CLIENTS = 4;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    AcctABC *p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;
    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number(long): ";
        cin >> tempnum;
        cout << "Enter opening balance(double): $";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or "
             << "2 for BrassPlus Account: ";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "Enter either 1 or 2: ";

        //只有在程序运行时才知道p_clients[i]的类型，因此采用动态联编
        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interest rate "
                 << "as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
                                         tmax, trate);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }
    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i]; // free memory
    }
    cout << "Done.\n";
    return 0;
}

/*
Enter client's name: Aa aa
Enter client's account number(long): 11111
Enter opening balance(double): $5000
Enter 1 for Brass Account or 2 for BrassPlus Account: 1
Enter client's name: Bb bb
Enter client's account number(long): 22222
Enter opening balance(double): $4000
Enter 1 for Brass Account or 2 for BrassPlus Account: 2
Enter the overdraft limit: $500
Enter the interest rate as a decimal fraction: 0.15
Enter client's name: Cc cc
Enter client's account number(long): 33333
Enter opening balance(double): $3800
Enter 1 for Brass Account or 2 for BrassPlus Account: 2
Enter the overdraft limit: $300
Enter the interest rate as a decimal fraction: 0.12
Enter client's name: Dd dd
Enter client's account number(long): 44444
Enter opening balance(double): $100
Enter 1 for Brass Account or 2 for BrassPlus Account: 1

Client: Aa aa
Account Number: 11111
Balance: $5000.00

Client: Bb bb
Account Number: 22222
Balance: $4000.00
Maximum loan: $500.00
Owed to bank: $0.00
Loan Rate: 15.000%

Client: Cc cc
Account Number: 33333
Balance: $3800.00
Maximum loan: $300.00
Owed to bank: $0.00
Loan Rate: 12.000%

Client: Dd dd
Account Number: 44444
Balance: $100.00

Done.
*/
