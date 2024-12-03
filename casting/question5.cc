#include <iostream>
using namespace std;

void modify(const int *x)
{
    int *y = const_cast<int *>(x);
    *y = 42;
    cout << "y: " << *y << endl;
    cout << "x: " << *x << endl;
}

int main()
{
    const int a = 10;
    modify(&a);
    cout << a << endl;
    return 0;
}
