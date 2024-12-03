#include <iostream>
#include <stdexcept>
#include <memory>
#include <fstream>

using namespace std;

#include <iostream>
#include <memory>
#include <stdexcept>

class Resource
{
    std::unique_ptr<int> data;

public:
    void allocate()
    {
        data = std::make_unique<int>(42);
    }

    void modify(int value)
    {
        *data = value;
    }
};

int main()
{
    Resource res;
    try
    {
        res.allocate();
        res.modify(99); // May throw
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
