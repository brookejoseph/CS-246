#include <iostream>

using namespace std;
class Base
{
public:
    ~Base()
    {
        std::cout << "Base destructor\n";
    }
};

class Derived : public Base
{
public:
    ~Derived()
    {
        std::cout << "Derived destructor\n";
    }
};

int main()
{
    Base *b = new Derived();
    delete b;
    return 0;
}