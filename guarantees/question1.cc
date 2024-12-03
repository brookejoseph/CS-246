

using namespace std;

#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>

struct impl
{
    std::vector<int> data;
};

class MyClass
{
    unique_ptr<impl> pImpl{new impl};

public:
    void modify()
    {
        auto temp = make_unique<impl>(*pImpl);
        temp->data.push_back(42);
        temp->data.push_back(99);
        swap(temp, pImpl);
    };

    void print() const
    {
        for (int val : pImpl->data)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    MyClass obj;
    try
    {
        obj.modify();
    }
    catch (...)
    {
        std::cout << "Exception caught, data may be in an inconsistent state.\n";
    }
    obj.print();
    return 0;
}
