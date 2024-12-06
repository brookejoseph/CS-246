#include <iostream>
#include <typeinfo>

using namespace std;

class Base
{
public:
    int x = 10;
    void print() const
    {
        std::cout << "Base\n";
    }
    virtual ~Base() = default;
};

class Derived : public Base
{
public:
    int x = 20;

    void print() const
    {
        std::cout << "Derived\n";
    }
};

int main()
{
    Derived *b = new Derived();

    if (Base *d = static_cast<Base *>(b))
    {
        d->print();
        cout << "the x value: " << d->x << endl;
    }
    else
    {
        std::cout << "Invalid cast\n";
    }

    delete b;
    return 0;
}
