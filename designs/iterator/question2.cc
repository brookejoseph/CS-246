#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    virtual ~Animal() = default;
    virtual void speak() const = 0;
};

class Dog : public Animal
{
    int val;

public:
    Dog(int val) : val(val) {};
    void speak() const override { cout << "Woof!" << endl; }
    void wagTail() { cout << "Wagging tail!" << val << endl; }
};

class Cat : public Animal
{
    Dog *doggy;

public:
    Cat(Dog *doggy) : doggy(doggy) {};
    void speak() const override { cout << "Meow!" << endl; }
};

int main()
{
    Dog dawg(10);
    Animal *animal = new Cat(&dawg);
    Dog *dog = dynamic_cast<Dog *>(animal); // Returns nullptr
    dog->wagTail();
}
