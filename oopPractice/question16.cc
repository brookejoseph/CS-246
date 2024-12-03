#include <iostream>
#include <stdexcept>

class Base
{
public:
    virtual void process()
    {
        std::cout << "Base processing\n";

    }; // Pure virtual function
    virtual ~Base() {}
};

class Derived : public Base
{
public:
    void process() override
    {
        std::cout << "Derived processing\n";
        throw std::runtime_error("Exception in Derived process");
    }
};

int main()
{
    try
    {
        Base d = Derived();
        d.process();
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught in main: " << e.what() << std::endl;
    }
}
