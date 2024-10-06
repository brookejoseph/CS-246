#include <iostream>
#include <string>
using namespace std;
#include <iostream>
using namespace std;

class Rectangle
{
public:
    int area();
    int perimeter();
    Rectangle();             // Default constructor
    Rectangle(int w, int h); // Parameterized constructor

private:
    int width;
    int height;
};

Rectangle::Rectangle()
{
    this->width = 0;
    this->height = 0;
}

Rectangle::Rectangle(int w, int h) : width(w), height(h) {}

int Rectangle::area()
{
    return this->height * this->width;
}

int Rectangle::perimeter()
{
    return 2 * (this->height + this->width);
}

int main()
{
    Rectangle r1;
    cout << "r1 area: " << r1.area() << endl;
    cout << "r1 perimeter: " << r1.perimeter() << endl;

    Rectangle r2(4, 5);
    cout << "r2 area: " << r2.area() << endl;
    cout << "r2 perimeter: " << r2.perimeter() << endl;

    return 0;
}
