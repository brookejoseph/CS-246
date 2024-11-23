#include <iostream>

class B
{
protected:
    int baseValue;

public:
    // Default Constructor
    B() : baseValue(0) {};

    // Destructor
    virtual ~B() {};

    // Copy Constructor
    B(const B &other) : baseValue(other.baseValue) {};

    // Copy Assignment Operator
    B &operator=(const B &other)
    {
        if (this != &other)
        {
            baseValue = other.baseValue;
        }
        return *this;
    };

    // Move Constructor
    B(B &&other) noexcept : baseValue(other.baseValue)
    {
        other.baseValue = 0;
    };

    // Move Assignment Operator
    B &operator=(B &&other) noexcept
    {
        if (this != &other)
        {
            baseValue = other.baseValue;
            other.baseValue = 0;
        };
        return *this;
    };
};

class A : public B
{
private:
    int derivedValue;

public:
    // Default Constructor
    A() : B(), derivedValue(0) {}

    // Destructor
    ~A() override {}

    // Copy Constructor
    A(const A &other) : B(other), derivedValue(other.derivedValue) {}

    // Copy Assignment Operator
    A &operator=(const A &other)
    {
        if (this != &other)
        {
            B::operator=(other); // Call base class copy assignment
            derivedValue = other.derivedValue;
        }
        return *this;
    }

    // Move Constructor
    A(A &&other) noexcept : B(std::move(other)), derivedValue(other.derivedValue)
    {
        other.derivedValue = 0;
        std::cout << "Move Constructor of A\n";
    }

    // Move Assignment Operator
    A &operator=(A &&other) noexcept
    {
        if (this != &other)
        {
            B::operator=(std::move(other)); // Call base class move assignment
            derivedValue = other.derivedValue;
            other.derivedValue = 0;
        }
        return *this;
    }
};
