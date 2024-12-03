#include <iostream>
using namespace std;

class Base
{
public:
    virtual void print() { cout << "Base" << endl; }
};

class Derived : public Base
{
public:
    void print() override { cout << "Derived" << endl; }
};

int main()
{
    Base *b = new Derived();
    Derived *d = static_cast<Derived *>(b);
    d->print();
    delete b;
}
