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

```

Compiling and running...

```shell

```
