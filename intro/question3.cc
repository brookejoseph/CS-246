#include <iostream>
class Base
{
public:
    virtual void print(int x) const
    {
        std::cout << "Base: " << x << '\n';
    }
};

class Derived : public Base
{
public:
    void print(double x) const
    {
        std::cout << "Derived: " << x << '\n';
    }
};

int main()
{
    Derived d;
    Base &b = d;

    b.print(42);
    b.print(42.0);
    d.print(42.0);
    return 0;
}
