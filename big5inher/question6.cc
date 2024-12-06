#include <iostream>
#include <string>
#include <memory>

class SharedResource
{
    std::shared_ptr<std::string> resource;

public:
    SharedResource(const std::string &res)
        : resource(std::make_shared<std::string>(res)) {}

    void print() const
    {
        std::cout << "Shared resource: " << *resource << "\n";
    }
};

class Base
{
protected:
    SharedResource baseResource;

public:
    Base(const std::string &res) : baseResource(res) {}
    virtual ~Base() = default;

    virtual void print() const
    {
        baseResource.print();
    }
};

class Derived : public Base
{
    std::string derivedName;

public:
    Derived(const std::string &res, const std::string &name)
        : Base(res), derivedName(name) {}

    void print() const override
    {
        Base::print();
        std::cout << "Derived name: " << derivedName << "\n";
    }
};
