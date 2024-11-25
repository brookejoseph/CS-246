#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Animal
{
    int age;

public:
    virtual void speak() {};
    Animal(int age) : age{age} {};
    virtual ~Animal() {};
    Animal(Animal &other) : age{other.age} {};
    Animal(Animal &&other) : age{other.age}
    {
        other.age = 0;
    };

    Animal &operator=(Animal &other)
    {
        if (this == &other)
        {
            return *this;
        };
        age = other.age;
        return *this;
    };
    Animal &operator=(Animal &&other)
    {
        if (this == &other)
        {
            return *this;
        };

        age = other.age;
        other.age = 0;
        return *this;
    };
};

class Special : public Animal
{
    string name;
    string sound;

public:
    void speak() override
    {
        cout << name << "makes a" << sound << "sound" << endl;
    };
    Special(string &name, string &sound, int &age) : Animal(age), name{name}, sound{sound} {};
    ~Special() {};
    Special(Special &other) : Animal(other), name(other.name), sound{other.sound} {};
    Special(Special &&other) : Animal(move(other)), name(other.name), sound{other.sound}
    {
        other.name = "";
        other.sound = "";
    };

    Special &operator=(Special &other)
    {
        if (this == &other)
        {
            return *this;
        };
        name = other.name;
        sound = other.sound;
        Animal::operator=(other);
    };

    Special &operator=(Special &&other)
    {
        if (this == &other)
        {
            return *this;
        };

        name = other.name;
        sound = other.sound;

        other.sound = "";
        other.name = "";
        Animal::operator=(other);
    };
};
