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

Person::~Person() {
        delete[] _name;
}

const Person & Person::operator=(const Person &other) {
        if (this != &other) {
                delete[] _name;
                _name = new char[strlen(other._name) + 1];
                strcpy(_name, other._name);
                _age = other._age;
        }
        return *this;
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
