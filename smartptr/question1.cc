#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>

class shared_ptr
{
    int refCount;
    T *val;

public:
    shared_ptr(T *currentVal) : val(currentVal), refCount(1) {};
    ~shared_ptr()
    {
        if ((refCount == 0) || (val == nullptr))
        {
            delete val;
        };
    };
    shared_ptr(shared_ptr &&other)
    {
        --refCount;
        refcount = other.refCount;
        val = other.val; // how do you hanlde if they are different values? maybe ask
    };
    shared_ptr(shared_ptr const &other){
        refCount} shared_ptr &
    operator=(shared_ptr &&other);
    shared_ptr &operator=(shared_ptr const &other);
};
