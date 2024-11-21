#include <iostream>
#include <string>
using namespace std;

class Food
{
public:
    virtual string prepareFood() = 0;
    virtual double foodPrice() = 0;
    virtual ~Food() = default;
};

class FoodDec : public Food
{
private:
    Food *newFood;

public:
    string prepareFood() override
    {
        return newFood->prepareFood();
    };
    double foodPrice() override
    {
        return newFood->foodPrice();
    };
    FoodDec(Food *newFood) : newFood{newFood} {};
};

class NonVegFood : public FoodDec
{
public:
    string prepareFood()
    {
        return this->prepareFood();
    };
    double foodPrice()
    {
        return this->foodPrice();
    };
    NonVegFood(Food *newFood) : FoodDec(newFood) {};
};

class VegFood : public Food
{
public:
    string prepareFood() { return "Veg Food"; };
    double foodPrice() { return 50.0; };
};
