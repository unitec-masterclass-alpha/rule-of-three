#include "person.h"

#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;



int main() {
    Person juan("Juan Angel", 17);
    cout << juan.GetName() << endl;
    cout << juan.GetAge() << endl;
    cout << endl;
    cout << (juan.IsMinor() ? "Minor" : "Adult") << endl;
    return 0;
}