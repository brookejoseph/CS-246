#include <iostream>
#include <utility>

using namespace std;

class Animal
{
public:
    virtual void sound() = 0;
};

class dog : public Animal
{
    void sound()
    {
        cout << "bark" << endl;
    };
};

int main()
{
    Animal *n = new dog();
};