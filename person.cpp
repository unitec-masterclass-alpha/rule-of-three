//
// Created by Arias Arevalo, Carlos on 3/20/25.
//

#include "person.h"

#include <cstring>
#include <string>

using std::string;

Person::Person(const char *name, unsigned short int age): _age(age) {
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
}

string Person::GetName() const {
        return _name;
}

unsigned short int Person::GetAge() const {
        return _age;
}

bool Person::IsMinor() const {
        return _age < 18;
}
