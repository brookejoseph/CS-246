#include <iostream>
#include <memory>

class Base
{
protected:
    int *baseData;

public:
    Base(int value) : baseData(new int(value)) {}
    virtual ~Base() { delete baseData; }

    virtual void print() const
    {
        std::cout << "Base data: " << *baseData << "\n";
    }
};

class Derived : public Base
{
    std::unique_ptr<int> derivedData;

public:
    Derived(int baseValue, int derivedValue)
        : Base(baseValue), derivedData(std::make_unique<int>(derivedValue)) {}

    void print() const override
    {
        Base::print();
        std::cout << "Derived data: " << *derivedData << "\n";
    }
};
