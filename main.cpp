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
    cout << (juan.IsMinor() ? "Minor" : "Adult") << endl;
    cout << endl;

    Person john("Jonathaniel", 0);
    john = juan;
    cout << john.GetName() << endl;
    cout << john.GetAge() << endl;
    cout << (john.IsMinor() ? "Minor": "Adult") << endl;
    cout << endl;

    cout << "Function Call ------" << endl;
    PrintAll(juan);
    cout << endl;
    return 0;
}
void PrintAll(Person person) {
    cout << "Print All" << endl;
    cout << person.GetName() << endl;
    cout << person.GetAge() << endl;
}
