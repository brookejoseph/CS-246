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
    Base *b = new Derived();
    cout << "pointer" << endl;
    b->display();

    Base b2 = Derived();
    cout << "normal" << endl;
    b2.display();

    Derived k;
    Base &b3 = k;
    cout << "reference" << endl;
    b3.display();
    /*
    Derived *d = dynamic_cast<Derived *>(b);

    if (d)
    {
        d->display();
    }
    else
    {
        std::cout << "Invalid cast\n";
    }*/

    delete b;
    return 0;
}
