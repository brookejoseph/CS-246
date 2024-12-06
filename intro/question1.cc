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
    Derived *derived = dynamic_cast<Derived *>(base);

    if (derived)
    {
        cout << "valid cast" << endl;
    }
    else
    {
        std::cout << "Invalid cast\n";
    }

    delete base;
    return 0;
}
