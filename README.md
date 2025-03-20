# Rule of Three

We will work with a class with dynamic memory.

What considerations do we need to have when writing a class with dynamic memory?

What happens if we forget to do it?

## A class without the Rule of Three

```c++
class Person {
private:
    char* _name;
    unsigned short int _age;
public:
    Person(const char* name, unsigned short int age);
    string GetName()const;
    unsigned short int GetAge()const;
    bool IsMinor()const;
};

```
> What is this class missing?
> 

Let's run a main...

```c++

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

```

Compiling and running...

```shell
root@dc14b070ab1c:/development/unitec/master-class-alpha/rule-of-three# make
g++ -g -std=c++20 -Wall -c main.cpp
g++ -g -std=c++20 -Wall -c person.cpp
g++  main.o person.o -o cmake-build-debug/memory-tests
root@dc14b070ab1c:/development/unitec/master-class-alpha/rule-of-three# ./cmake-build-debug/memory-tests

Juan Angel
17
Minor

Juan Angel
17
Minor

Function Call ------
Print All
Juan Angel
17
```
Anything strange?

### Memory Check


```shell
root@dc14b070ab1c:/development/unitec/master-class-alpha/rule-of-three# valgrind --leak-check=full ./cmake-build-debug/memory-tests
==80== Memcheck, a memory error detector
==80== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==80== Using Valgrind-3.23.0 and LibVEX; rerun with -h for copyright info
==80== Command: ./cmake-build-debug/memory-tests
==80==
Juan Angel
17
Minor

Juan Angel
17
Minor

Function Call ------
Print All
Juan Angel
17

==80==
==80== HEAP SUMMARY:
==80==     in use at exit: 23 bytes in 2 blocks
==80==   total heap usage: 4 allocs, 2 frees, 74,775 bytes allocated
==80==
==80== 11 bytes in 1 blocks are definitely lost in loss record 1 of 2
==80==    at 0x488724C: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-arm64-linux.so)
==80==    by 0x109FCB: Person::Person(char const*, unsigned short) (person.cpp:13)
==80==    by 0x1099A3: main (main.cpp:13)
==80==
==80== 12 bytes in 1 blocks are definitely lost in loss record 2 of 2
==80==    at 0x488724C: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-arm64-linux.so)
==80==    by 0x109FCB: Person::Person(char const*, unsigned short) (person.cpp:13)
==80==    by 0x109A77: main (main.cpp:19)
==80==
==80== LEAK SUMMARY:
==80==    definitely lost: 23 bytes in 2 blocks
==80==    indirectly lost: 0 bytes in 0 blocks
==80==      possibly lost: 0 bytes in 0 blocks
==80==    still reachable: 0 bytes in 0 blocks
==80==         suppressed: 0 bytes in 0 blocks
==80==
==80== For lists of detected and suppressed errors, rerun with: -s
==80== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
```

## Part 1 of the Rule of Three

Adding a destructor to Person

The updated `person.h`
```c++
class Person {
private:
    char* _name;
    unsigned short int _age;
public:
    Person(const char* name, unsigned short int age);
    ~Person();
    string GetName()const;
    unsigned short int GetAge()const;
    bool IsMinor()const;


};

```

Compiling and running...

```shell
root@dc14b070ab1c:/development/unitec/master-class-alpha/rule-of-three# make
g++ -g -std=c++20 -Wall -c main.cpp
g++ -g -std=c++20 -Wall -c person.cpp
g++  main.o person.o -o cmake-build-debug/memory-tests
root@dc14b070ab1c:/development/unitec/master-class-alpha/rule-of-three# ./cmake-build-debug/memory-tests
Juan Angel
17
Minor

Juan Angel
17
Minor

Function Call ------
Print All
Juan Angel
17

free(): double free detected in tcache 2
Aborted
```
Anything strange? What happened?


### Memory Check


```shell
root@dc14b070ab1c:/development/unitec/master-class-alpha/rule-of-three# valgrind --leak-check=full ./cmake-build-debug/memory-tests
==93== Memcheck, a memory error detector
==93== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==93== Using Valgrind-3.23.0 and LibVEX; rerun with -h for copyright info
==93== Command: ./cmake-build-debug/memory-tests
==93==
Juan Angel
17
Minor

Juan Angel
17
Minor

Function Call ------
Print All
Juan Angel
17

==93== Invalid free() / delete / delete[] / realloc()
==93==    at 0x488AD60: operator delete[](void*) (in /usr/libexec/valgrind/vgpreload_memcheck-arm64-linux.so)
==93==    by 0x10A083: Person::~Person() (person.cpp:18)
==93==    by 0x109BE3: main (main.cpp:30)
==93==  Address 0x4e03080 is 0 bytes inside a block of size 11 free'd
==93==    at 0x488AD60: operator delete[](void*) (in /usr/libexec/valgrind/vgpreload_memcheck-arm64-linux.so)
==93==    by 0x10A083: Person::~Person() (person.cpp:18)
==93==    by 0x109BC3: main (main.cpp:27)
==93==  Block was alloc'd at
==93==    at 0x488724C: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-arm64-linux.so)
==93==    by 0x10A033: Person::Person(char const*, unsigned short) (person.cpp:13)
==93==    by 0x1099E3: main (main.cpp:13)
==93==
==93== Invalid free() / delete / delete[] / realloc()
==93==    at 0x488AD60: operator delete[](void*) (in /usr/libexec/valgrind/vgpreload_memcheck-arm64-linux.so)
==93==    by 0x10A083: Person::~Person() (person.cpp:18)
==93==    by 0x109BEB: main (main.cpp:30)
==93==  Address 0x4e03080 is 0 bytes inside a block of size 11 free'd
==93==    at 0x488AD60: operator delete[](void*) (in /usr/libexec/valgrind/vgpreload_memcheck-arm64-linux.so)
==93==    by 0x10A083: Person::~Person() (person.cpp:18)
==93==    by 0x109BC3: main (main.cpp:27)
==93==  Block was alloc'd at
==93==    at 0x488724C: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-arm64-linux.so)
==93==    by 0x10A033: Person::Person(char const*, unsigned short) (person.cpp:13)
==93==    by 0x1099E3: main (main.cpp:13)
==93==
==93==
==93== HEAP SUMMARY:
==93==     in use at exit: 12 bytes in 1 blocks
==93==   total heap usage: 4 allocs, 5 frees, 74,775 bytes allocated
==93==
==93== 12 bytes in 1 blocks are definitely lost in loss record 1 of 1
==93==    at 0x488724C: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-arm64-linux.so)
==93==    by 0x10A033: Person::Person(char const*, unsigned short) (person.cpp:13)
==93==    by 0x109AB7: main (main.cpp:19)
==93==
==93== LEAK SUMMARY:
==93==    definitely lost: 12 bytes in 1 blocks
==93==    indirectly lost: 0 bytes in 0 blocks
==93==      possibly lost: 0 bytes in 0 blocks
==93==    still reachable: 0 bytes in 0 blocks
==93==         suppressed: 0 bytes in 0 blocks
==93==
==93== For lists of detected and suppressed errors, rerun with: -s
==93== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)
```
