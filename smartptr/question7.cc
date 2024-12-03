#include <iostream>
#include <memory>

class A;
class B;

class A
{
public:
    A() { std::cout << "A ctor"; };
    std::shared_ptr<B> b;
    ~A() { std::cout << "A destroyed\n"; }
};

class B
{
public:
    B() { std::cout << "B ctor"; };
    std::shared_ptr<A> a;
    ~B() { std::cout << "B destroyed\n"; }
};

int main()
{
    {
        std::shared_ptr<A> objA = std::make_shared<A>();
        std::shared_ptr<B> objB = std::make_shared<B>();
        objA->b = objB;
        objB->a = objA;
    }
    std::cout << "End of main\n";
    return 0;
}
