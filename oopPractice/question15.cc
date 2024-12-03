#include <iostream>
#include <stdexcept>

class Base
{
public:
    virtual void action()
    {
        std::cout << "Base action\n";
    }
    virtual ~Base()
    {
        std::cout << "base dtor";
    };
};

class Derived : public Base
{
public:
    void action() override
    {
        std::cout << "Derived action\n";
        throw std::runtime_error("Exception in Derived action");
    }
};

int main()
{
    try
    {
        Base *b = new Derived();
        b->action();
        delete b;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught in main: " << e.what() << std::endl;
    }
}
