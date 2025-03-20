#include "person.h"

#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

void PrintAll(Person person);

int main() {
    Person juan("Juan Angel", 17);
    cout << juan.GetName() << endl;
    cout << juan.GetAge() << endl;
    cout << endl;
    cout << (juan.IsMinor() ? "Minor" : "Adult") << endl;

    Person john("", 0);
    john = juan;
    cout << john.GetName() << endl;
    cout << john.GetAge() << endl;
    cout << endl;
    cout << (john.IsMinor() ? "Minor": "Adult") << endl;

    cout << "Function Call ------" << endl;
    PrintAll(juan);
    return 0;
}
void PrintAll(Person person) {
    cout << "Print All" << endl;
    cout << person.GetName() << endl;
    cout << person.GetAge() << endl;
}
