#include <iostream>
#include <string>
#include <vector>

using namespace std;
// animals

class Animal
{
public:
    virtual string sound() = 0;
    virtual ~Animal();
};

class AnimalFactory
{
public:
    virtual Animal *createAnimal() = 0;
    virtual ~AnimalFactory();
};

class dog : public Animal
{
    string sound() override
    {
        return "bark";
    };
};

class cat : public Animal
{
    string sound() override
    {
        return "meow";
    };
};

class DogFactory : public AnimalFactory
{
public:
    Animal *createAnimal() override
    {
        return new dog();
    };
};

class CatFactory : public AnimalFactory
{
public:
    Animal *createAnimal() override
    {
        return new cat();
    };
};
