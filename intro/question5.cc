#include <iostream>
class Base
{
public:
    void nonVirtual() const
    {
        std::cout << "Base nonVirtual\n";
    }

    virtual void virtualFunction() const
    {
        std::cout << "Base virtualFunction\n";
    }
};

class Derived : public Base
{
public:
    void nonVirtual() const
    {
        std::cout << "Derived nonVirtual\n";
    }

    void virtualFunction() const override
    {
        std::cout << "Derived virtualFunction\n";
    }
};

int main()
{
    Derived d;
    Base &b = d;

    b.nonVirtual();
    b.virtualFunction();
    return 0;
}
