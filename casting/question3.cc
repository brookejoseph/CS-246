#include <iostream>
using namespace std;

class Base
{
public:
    virtual ~Base() {}
};

class Derived : public Base
{
};

int main()
{
    Base *b = new Base();
    Derived *d = dynamic_cast<Derived *>(b);
    if (d)
    {
        cout << "Cast successful" << endl;
    }
    else
    {
        cout << "Cast failed" << endl;
    }
    delete b;
}
