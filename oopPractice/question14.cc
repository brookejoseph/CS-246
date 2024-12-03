#include <iostream>
#include <stdexcept>

class Base
{
public:
    Base() { std::cout << "Base Constructor\n"; }
    virtual ~Base() { std::cout << "Base Destructor\n"; }
};

class Derived : public Base
{
public:
    Derived() { std::cout << "Derived Constructor\n"; }
    ~Derived()
    {
        std::cout << "Derived Destructor\n";
        // throw std::runtime_error("Error in Derived Destructor");
    }
};

int main()
{
    Derived f;
    try
    {
        Derived d;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught in main: " << e.what() << std::endl;
    }
}
