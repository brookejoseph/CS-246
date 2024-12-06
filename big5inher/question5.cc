#include <iostream>
#include <memory>

class A
{
    std::unique_ptr<int> aData;

public:
    A(int value) : aData(std::make_unique<int>(value)) {}
    virtual ~A() = default;

    virtual void print() const
    {
        std::cout << "A data: " << *aData << "\n";
    }
};

class B
{
    std::unique_ptr<int> bData;

public:
    B(int value) : bData(std::make_unique<int>(value)) {}
    virtual ~B() = default;

    virtual void print() const
    {
        std::cout << "B data: " << *bData << "\n";
    }
};

class Derived : public A, public B
{
    std::unique_ptr<int> derivedData;

public:
    Derived(int aVal, int bVal, int dVal)
        : A(aVal), B(bVal), derivedData(std::make_unique<int>(dVal)) {}

    void print() const override
    {
        A::print();
        B::print();
        std::cout << "Derived data: " << *derivedData << "\n";
    }
};
