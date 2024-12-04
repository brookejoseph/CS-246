#include <iostream>
#include <utility>

class Base
{
public:
    Base() = default;

    // Prevent copying
    Base(const Base &) = delete;
    Base &operator=(const Base &) = delete;

    // Allow moving
    Base(Base &&) = default;
    Base &operator=(Base &&) = default;

    virtual ~Base() = default;
    virtual void display() const
    {
        std::cout << "Base\n";
    }
};

class Derived : public Base
{
public:
    void display() const override
    {
        std::cout << "Derived\n";
    }
};

void passByValue(Base b)
{
    b.display();
}

int main()
{
    Derived f;
    Base b = Derived();

    return 0;
}
