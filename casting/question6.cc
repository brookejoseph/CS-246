#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    ~Animal() = default;
    void speak() const
    {
        cout << "hello from animal" << endl;
    }
};

class Dog : public Animal
{
    int val;

public:
    Dog(int val) : val(val) {};
    void speak() { cout << "Woof!" << endl; }
    void wagTail() { cout << "Wagging tail!" << val << endl; }
};

int main()
{
    Animal *a = new Animal();
    Dog *ptr = static_cast<Dog *>(a);

    int k = 'K';
    cout << "k printed " << k << endl;

    char f = static_cast<char>(k);
    cout << "f printed " << f << endl;

    ptr->speak();
    ptr->wagTail();
}
