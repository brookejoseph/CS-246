#include <iostream>
#include <string>
using namespace std;

/*
3. Write a class `DynamicArray` that dynamically allocates memory for an array of integers using a constructor.
 Implement a destructor that frees the allocated memory. Add methods to set and get values in the array.
 */

class LList
{
public:
    LList();
    LList(int val);
    LList *add_node(int val);
    LList *remove_node(int val);

private:
    int current_node;
    LList *Next;
};

LList::LList()
{
    this->current_node = 0;
    LList->Next = nullptr;
};

LList::LList(int val)
{
    this->current_node = val;
    LList->Next = nullptr;
};

LList *LList::add_node(int val)
{
    LList *new_node = new LList();
    new_node->current_node = val;
    new_node->Next = nullptr;

    LList *copied_list = new LList();
    LList *current = this;
    LList *temp = copied_list;

    while (current != nullptr)
    {
        temp->current_node = current->current_node;
        if (current->Next != nullptr)
        {
            temp->Next = new LList();
            temp = temp->Next;
        }
        else
        {
            temp->Next = nullptr;
        }
        current = current->Next;
    }
    temp->Next = new_node;

    return copied_list;
}
