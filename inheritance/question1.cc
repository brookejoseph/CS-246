#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Animal
{
public:
    virtual void sound()
    {
        std::cout << "This animal makes a sound." << std::endl;
    }
};

class Dog : public Animal
{
public:
    void sound() override
    {
        std::cout << "This dog barks." << std::endl;
    }
};

int main()
{
    Dog animal;
    animal.sound();

    Animal doggie = Dog();
    doggie.sound();
}
