#include <iostream>
#include <memory>

using namespace std;
struct CustomDeleter
{
    CustomDeleter()
    {
        cout << "within the strucut" << endl;
    };
    void operator()(int *p) const
    {
        std::cout << "Deleting: " << *p << '\n';
        delete p;
    }
};

int main()
{
    std::shared_ptr<int> sp(new int(100), CustomDeleter());
    std::cout << "Shared Pointer Value: " << *sp << '\n';
    return 0;
}
