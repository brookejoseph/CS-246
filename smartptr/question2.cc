#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

class MyClass
{
public:
    MyClass(int x) { cout << "Constructor called with value: " << x << endl; }
};

int main()
{
    unique_ptr<MyClass> ptr = make_unique<MyClass>(42);

    cout << "before the move" << endl;
    unique_ptr<MyClass> ptr2 = std::move(ptr);
    cout << "after the move" << endl;
    return 0;
}
