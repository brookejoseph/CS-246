#include <iostream>
using namespace std;

int main()
{
    int a = 65;
    char *c = reinterpret_cast<char *>(&a);
    cout << *c << endl;
    return 0;
}
