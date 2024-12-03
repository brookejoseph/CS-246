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
    std::unique_ptr<Test> ptr = std::make_unique<Test>();
    return 0;
}
