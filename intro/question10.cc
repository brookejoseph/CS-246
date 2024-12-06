#include <iostream>
class Base
{
public:
    virtual ~Base() = default;
};

class Derived1 : public Base
{
public:
    void display() const
    {
        std::cout << "Derived1 display\n";
    }
};

class Derived2 : public Base
{
public:
    void display() const
    {
        std::cout << "Derived2 display\n";
    }
};

int main()
{
    Base *b = new Derived1();
    Derived1 *d2 = dynamic_cast<Derived1 *>(b);

    if (d2)
    {
        d2->display();
    }
    else
    {
        std::cout << "Invalid cast\n";
    }

    delete b;
    return 0;
}
