#include <iostream>
#include <stdexcept>
#include <memory>

using namespace std;

struct impl
{
    int x;
    int y;
};

class MyClass
{
    unique_ptr<impl> pImpl{new impl};

public:
    MyClass()
    {
        pImpl->x = 0;
        pImpl->y = 0;
    }

    void update(int newX, int newY)
    {
        auto temp = make_unique<impl>(*pImpl);

        temp->x = newX;
        if (newX == -1)
            throw std::runtime_error("Invalid value for x");
        temp->y = newY;

        std::swap(temp, pImpl);
    }

    void print() const
    {
        std::cout << "x: " << pImpl->x << ", y: " << pImpl->y << std::endl;
    }
};

int main()
{
    MyClass obj;
    try
    {
        obj.update(10, 20);
        obj.update(-1, 30); // This will throw
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    obj.print();
    return 0;
}
