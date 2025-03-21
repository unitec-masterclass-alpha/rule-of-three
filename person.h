//
// Created by Arias Arevalo, Carlos on 3/20/25.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>

using std::string;

class Person {
private:
    char* _name;
    unsigned short int _age;
public:
    Person(const char* name, unsigned short int age);
    ~Person();
    const Person& operator=(const Person& other);
    string GetName()const;
    unsigned short int GetAge()const;
    bool IsMinor()const;


};



#endif //PERSON_H
