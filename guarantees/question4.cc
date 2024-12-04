#include <iostream>
#include <stdexcept>
#include <memory>
#include <fstream>

using namespace std;

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

class K
{
public:
    K()
    {
        cout << "k ctor called" << endl;
    };
};

class F
{
public:
    F()
    {
        cout << "f ctor called" << endl;
    };
};

class B : public F
{
    int x, y;
    K k;

public:
    B(int x, int y) : x(x), y(y), k()
    {
        cout << "B ctor called" << endl;
    };
};

int main()
{
    B(9, 2);

    return 0;
}
