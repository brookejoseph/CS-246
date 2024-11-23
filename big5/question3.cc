#include <iostream>
#include <cstring> // For strcpy, strlen

class B
{
protected:
    char *name;

public:
    B() : name(nullptr)
    {
        std::cout << "Default Constructor of B\n";
    }

    virtual ~B()
    {
        delete[] name;
        std::cout << "Destructor of B\n";
    }

    B(const B &other)
    {
        if (other.name)
        {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        else
        {
            name = nullptr;
        }
        std::cout << "Copy Constructor of B\n";
    }

    // Copy Assignment Operator
    B &operator=(const B &other)
    {
        if (this != &other)
        {
            delete[] name; // Clean up current resource
            if (other.name)
            {
                name = new char[strlen(other.name) + 1];
                strcpy(name, other.name);
            }
            else
            {
                name = nullptr;
            }
        }
        std::cout << "Copy Assignment Operator of B\n";
        return *this;
    }

    // Move Constructor
    B(B &&other) noexcept : name(other.name)
    {
        other.name = nullptr;
        std::cout << "Move Constructor of B\n";
    }

    // Move Assignment Operator
    B &operator=(B &&other) noexcept
    {
        if (this != &other)
        {
            delete[] name;     // Clean up current resource
            name = other.name; // Take ownership of other's resource
            other.name = nullptr;
        }
        std::cout << "Move Assignment Operator of B\n";
        return *this;
    }
};

class A : public B
{
private:
    int *data;
    size_t size;

public:
    // Default Constructor
    A() : B(), data(nullptr), size(0)
    {
        std::cout << "Default Constructor of A\n";
    }

    // Destructor
    ~A() override
    {
        delete[] data;
        std::cout << "Destructor of A\n";
    }

    // Copy Constructor
    A(const A &other) : B(other), size(other.size)
    {
        if (other.data)
        {
            data = new int[other.size];
            std::copy(other.data, other.data + other.size, data);
        }
        else
        {
            data = nullptr;
        }
        std::cout << "Copy Constructor of A\n";
    }

    // Copy Assignment Operator
    A &operator=(const A &other)
    {
        if (this != &other)
        {
            B::operator=(other); // Call base class copy assignment operator
            delete[] data;       // Clean up current resource
            size = other.size;
            if (other.data)
            {
                data = new int[other.size];
                std::copy(other.data, other.data + other.size, data);
            }
            else
            {
                data = nullptr;
            }
        }
        std::cout << "Copy Assignment Operator of A\n";
        return *this;
    }

    // Move Constructor
    A(A &&other) noexcept : B(std::move(other)), data(other.data), size(other.size)
    {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move Constructor of A\n";
    }

    // Move Assignment Operator
    A &operator=(A &&other) noexcept
    {
        if (this != &other)
        {
            B::operator=(std::move(other)); // Call base class move assignment operator
            delete[] data;                  // Clean up current resource
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        std::cout << "Move Assignment Operator of A\n";
        return *this;
    }
};

int main()
{
    A obj1;

    A obj2 = obj1;

    obj1 = obj2;

    A obj3 = std::move(obj1);

    obj3 = std::move(obj2);

    return 0;
}
