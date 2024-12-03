#include <iostream>

class Base
{
public:
    virtual void show() {};
    virtual void show2(int x) = 0; // Pure virtual method
};

class Derived : public Base
{
    void show2(int y)
    {
        std::cout << "y:" << y;
    };
};

int main()
{
    // Derived d; // Uncommenting this will cause a compilation error: Derived is abstract
    Base *b = new Derived(); // Compilation error: cannot instantiate abstract class
    return 0;
}
