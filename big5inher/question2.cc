#include <iostream>
#include <vector>

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

class Intermediate : public Base
{
protected:
    int *intermediateData;

public:
    Intermediate(const std::vector<int> &d, int value)
        : Base(d), intermediateData(new int(value)) {}

    ~Intermediate() override
    {
        delete intermediateData;
    }

    void print() const override
    {
        Base::print();
        std::cout << "Intermediate data: " << *intermediateData << "\n";
    }
};

class Derived : public Intermediate
{
    std::string name;

public:
    Derived(const std::vector<int> &d, int value, const std::string &n)
        : Intermediate(d, value), name(n) {}

    void print() const override
    {
        Intermediate::print();
        std::cout << "Name: " << name << "\n";
    }
};
