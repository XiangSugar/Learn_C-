// twofile2.cpp -- variables with internal and external linkage
//compile with twofile2.cpp

#include <iostream>

extern int tom;         // tom defined elsewhere
static int dick = 10;   // overrides external dick
int harry = 200;        // external variable definition,
                        // no conflict with twofile1 harry

void remote_access() {
  using namespace std;
  cout << "remote_access() reports the following addresses:\n";
  cout << &tom << " = &tom, " << &dick << " = &dick, ";
  cout << &harry << " = &harry\n";
}

/*
main() reports the following addresses:
0x403010 = &tom, 0x403014 = &dick, 0x403018 = &harry
remote_access() reports the following addresses:
0x403010 = &tom, 0x403020 = &dick, 0x403024 = &harry
*/
