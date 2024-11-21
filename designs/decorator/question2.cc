#include <iostream>
#include <string>
using namespace std;

class Pizza
{
public:
    virtual int getPrice() = 0;
    virtual string getDes() = 0;
};

class Basic : public Pizza
{
    int getPrice() override
    {
        return 5;
    };
    string getDes() override
    {
        return "chesse";
    };
};

class PizzaDec : public Pizza
{
protected:
    Pizza *thePizza;

public:
    PizzaDec(Pizza *thePizza) : thePizza{thePizza} {};
};

class addPep : public PizzaDec
{
public:
    addPep(Pizza *thePizza) : PizzaDec(thePizza) {};
    int getPrice() override
    {
        return 1;
    };

    string getDes() override
    {
        return "pepperoni";
    };
};
