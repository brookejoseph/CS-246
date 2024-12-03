#include <iostream>
#include <stdexcept>

class A
{
public:
    A() { std::cout << "A constructed\n"; }
    ~A() { std::cout << "A destroyed\n"; }
};

class B
{
public:
    B() { std::cout << "B constructed\n"; }
    ~B() { std::cout << "B destroyed\n"; }
};

void innerFunction()
{
    A a;
    std::cout << "Inner function: Throwing exception...\n";
    throw std::runtime_error("Exception from innerFunction");
}

void outerFunction()
{
    B b;
    innerFunction();
}

int main()
{
    try
    {
        outerFunction();
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << "\n";
    }
    return 0;
}
