#include <iostream>

using namespace std;

namespace Jill {
    double bucket(double n) {return n;}
    double fetch;
    struct Hill {int a; int b;};
}

char fetch;                       //global namespace

int main()
{
    using namespace Jill;         //import all namespace names
    Hill Thrill;                  //create a type Jill::Hill structure
    double water = bucket(2);     //use Jill::bucket();
    double fetch;                 //not an error; hides Jill::fetch
    cin >> fetch;                 //read a value into the local fetch
    cin >> ::fetch;               //read a value into global fetch
    cin >> Jill::fetch;           //read a value into Jill::fetch

    return 0;
}

int foom()
{
    //Hill top;     error
    Jill::Hill crest;
    return 0;
}
