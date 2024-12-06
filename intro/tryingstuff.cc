#include <iostream>

class Base
{
    int x;

public:
    Base(int value) : x(value) {}
    void print() const
    {
        std::cout << "Base: " << x << "\n";
    }
};

class Derived : public Base
{
    int y;

public:
    Derived(int x, int y) : Base(x), y(y) {}
    void print() const
    {
        Base::print();
        std::cout << "Derived: " << y << "\n";
    }
};

int main()
{
    Derived d(10, 20);
    Base b = d;

    b.print();
    return 0;
}
