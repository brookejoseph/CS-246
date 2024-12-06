#include <iostream>
class Base
{
public:
    virtual void display() const
    {
        std::cout << "Base display\n";
    }
};

class Derived : public Base
{
public:
    void display() const override
    {
        std::cout << "Derived display\n";
    }
};

int main()
{
    Base b;
    Derived *d = dynamic_cast<Derived *>(&b);

    if (d)
    {
        d->display();
    }
    else
    {
        std::cout << "Invalid cast\n";
    }

    return 0;
}
