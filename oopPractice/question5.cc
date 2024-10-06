#include <iostream>
#include <string>
using namespace std;

/*
3. Write a class `DynamicArray` that dynamically allocates memory for an array of integers using a constructor.
 Implement a destructor that frees the allocated memory. Add methods to set and get values in the array.
 */

class DynamicArray
{
public:
    int *current_array;
    int size;
    void add_element(int val);
};

void DynamicArray::add_element(int val)
{
    int *new_array = new int[this->size + 1];
    for (int i = 0; i < this->size; i++)
    {
        new_array[i] = this->current_array[i];
    };
    new_array[this-] = val;
    delete[] this->current_array;
    this->current_array = new_array;
    ++this->size;
};
