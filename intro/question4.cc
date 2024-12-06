#include <iostream>
class Base
{
public:
    int x = 10;

    virtual void display() const
    {
        std::cout << "Base: " << x << '\n';
    }
};

class Derived : public Base
{
public:
    int x = 20;

    void display() const override
    {
        std::cout << "Derived: " << x << '\n';
    }
};

int main()
{
    Derived d;
    Base &b = d;

    b.display();
    std::cout << b.x << '\n';
    return 0;
}
