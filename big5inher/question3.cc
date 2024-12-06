#include <iostream>
#include <string>

class Base
{
protected:
    std::string baseName;

public:
    Base(const std::string &name) : baseName(name) {}
    virtual ~Base() = default;

    virtual void print() const
    {
        std::cout << "Base: " << baseName << "\n";
    }
};

class Derived : public Base
{
    int *derivedData;

public:
    Derived(const std::string &name, int value)
        : Base(name), derivedData(new int(value)) {}

    ~Derived() override
    {
        delete derivedData;
    }

    void print() const override
    {
        Base::print();
        std::cout << "Derived data: " << *derivedData << "\n";
    }
};
