#include <iostream>
#include <memory>

class C
{
public:
    C() { std::cout << "C constructed" << std::endl; }
    ~C() { std::cout << "C destroyed" << std::endl; }
    int getValue() const { return 42; }
};

std::unique_ptr<C> f()
{
    return std::make_unique<C>();
}

int main()
{
    std::cout << "Value: " << f()->getValue() << std::endl;
    return 0;
}
