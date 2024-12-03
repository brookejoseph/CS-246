#include <iostream>
#include <memory>
#include <string>

class Test
{
public:
    Test() { std::cout << "Test constructed\n"; }
    ~Test() { std::cout << "Test destroyed\n"; }
};

int main()
{
    std::shared_ptr<Test> sp = std::make_shared<Test>();
    std::cout << "count before " << sp.use_count() << std::endl;
    sp.reset();
    std::cout << "count after " << sp.use_count() << std::endl;

    std::cout << "After reset\n";
    return 0;
}
