#include <iostream>
#include <string>
using namespace std;

class Shape
{
public:
    virtual void update();
};

class BasicShape : public Shape
{
public:
    void update() override
    {
        cout << "this is the basic shape" << endl;
    };
};

class ShapeDec : public Shape
{
protected:
    Shape *next;

public:
    ShapeDec(Shape *val) : next{val} {};
    virtual ~ShapeDec() { delete next; };
    void update() override
    {
        next->update();
    };
};

class Shadows : public ShapeDec
{
    Shadows(Shape *currentVal) : ShapeDec(currentVal) {};
    void update() override
    {
        next->update();
    };
};
