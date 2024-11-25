#include <iostream>
#include <string>
using namespace std;

class Coffee
{
public:
    virtual int price() = 0;
    virtual string desc() = 0;
    virtual ~Coffee() {}
};

class BasicCoffee : public Coffee
{
public:
    int price() override { return 5; }
    string desc() override { return "Plain Coffee"; }
};

class CoffeeDec : public Coffee
{
protected:
    Coffee *next;

public:
    CoffeeDec(Coffee *next) : next(next) {}
    virtual ~CoffeeDec() { delete next; }

    int price() override { return next->price(); }
    string desc() override { return next->desc(); }
};

class WhippedCreamDecorator : public CoffeeDec
{
public:
    WhippedCreamDecorator(Coffee *next) : CoffeeDec(next) {}
    int price() override { return next->price() + 2; }
    string desc() override { return next->desc() + ", Whipped Cream"; }
};

class CaramelDecorator : public CoffeeDec
{
public:
    CaramelDecorator(Coffee *next) : CoffeeDec(next) {}
    int price() override { return next->price() + 3; }
    string desc() override { return next->desc() + ", Caramel"; }
};

class MilkDecorator : public CoffeeDec
{
public:
    MilkDecorator(Coffee *next) : CoffeeDec(next) {}
    int price() override { return next->price() + 1; }
    string desc() override { return next->desc() + ", Milk"; }
};

int main()
{
    Coffee *myCoffee = new BasicCoffee();
    myCoffee = new WhippedCreamDecorator(myCoffee);

    myCoffee = new CaramelDecorator(myCoffee);

    myCoffee = new MilkDecorator(myCoffee);

    cout << myCoffee->price() << endl;
    cout << myCoffee->desc() << endl;

    delete myCoffee;
    return 0;
}
