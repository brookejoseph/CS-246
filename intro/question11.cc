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
    Derived d;
    Base b = static_cast<Base>(d);
    b.display();

    return 0;
}
