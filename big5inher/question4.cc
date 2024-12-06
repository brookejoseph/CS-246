#include <iostream>
#include <vector>

class Component
{
    int *value;

public:
    Component(int v) : value(new int(v)) {}
    ~Component() { delete value; }

    Component(const Component &other) : value(new int(*other.value)) {}
    Component &operator=(const Component &other)
    {
        if (this == &other)
            return *this;
        delete value;
        value = new int(*other.value);
        return *this;
    }

    void print() const
    {
        std::cout << "Component value: " << *value << "\n";
    }
};

class Base
{
protected:
    std::vector<int> data;

public:
    Base(const std::vector<int> &d) : data(d) {}
    virtual ~Base() = default;

    virtual void print() const
    {
        for (int val : data)
        {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
};

class Derived : public Base
{
    Component component;

public:
    Derived(const std::vector<int> &d, int v)
        : Base(d), component(v) {}

    void print() const override
    {
        Base::print();
        component.print();
    }
};
