#include <iostream>
#include <memory>

class Test
{
public:
    Test() { std::cout << "Test constructed\n"; }
    ~Test() { std::cout << "Test destroyed\n"; }
};

int main()
{
    std::unique_ptr<Test> ptr1 = std::make_unique<Test>();
    std::unique_ptr<Test> ptr2 = std::move(ptr1);
    std::cout << "Ptr1 is " << (ptr1 ? "not null" : "null") << "\n";
    std::cout << "Ptr2 is " << (ptr2 ? "not null" : "null") << "\n";
    return 0;
}
