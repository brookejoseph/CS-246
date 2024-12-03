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
    std::shared_ptr<Test> sp1 = std::make_shared<Test>();
    {
        std::shared_ptr<Test> sp2 = sp1;
        std::cout << "Reference count: " << sp1.use_count() << "\n";
    }
    std::cout << "Reference count: " << sp1.use_count() << "\n";
    return 0;
}
