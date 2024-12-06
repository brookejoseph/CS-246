#include <iostream>

using namespace std;

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

    // reference
    Derived k;
    Base &b = k;
    cout << "ref b.display ";
    b.display();

    Derived &d = dynamic_cast<Derived &>(b);
    d.display();

    // pointers
    Base *b2 = new Derived();
    cout << "pointer b.display ";
    b2->display();

    Derived *d2 = dynamic_cast<Derived *>(b2);
    d2->display();

    return 0;
}
