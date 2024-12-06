#include <iostream>

using namespace std;
class Base
{
public:
    virtual ~Base() {}
};

class Derived : public Base
{
public:
    void display() const
    {
        std::cout << "Derived display\n";
    }
};

int main()
{
    Base *base = new Base();
    Derived d = Derived();
    Base derived = static_cast<Base>(d);

    Derived *d1 = dynamic_cast<Derived *>(base);
    if (d1)
    {
        cout << "valid cast" << endl;
    }
    else
    {
        cout << "invalid cast" << endl;
    }

    delete base;
    return 0;
}
