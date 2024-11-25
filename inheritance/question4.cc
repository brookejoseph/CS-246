#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Product
{
    string name;
    int price;

public:
    virtual void displayDetails() {};
    virtual int calculatePrice(int discount) {};

    virtual ~Product() {};
    Product(string &name, int &price) : name{name}, price{price} {};
    Product(Product &other) : name(other.name), price(other.price) {};
    Product(Product &&other) : name(other.name), price(other.price)
    {
        other.name = "";
        other.price = 0;
    }
    Product &operator=(const Product &other)
    {
        if (this == &other)
        {
            return *this;
        };
        name = other.name;
        price = other.price;

        return *this;
    };
    Product &operator=(Product &&other)
    {
        if (this == &other)
        {
            return *this;
        };

        name = other.name;
        other.name = "";

        price = other.price;
        other.price = 0;

        return *this;
    };
};

class Electronic : public Product
{
    int warranty;

public:
    void displayDetails() override
    {
        cout << "Electronic with a warranty of" << warranty << "months" << endl;
    };
    int calculatePrice(int discount) override
    {
        return 55 - discount + warranty;
    };

    Electronic(int &warranty, string &name, int &price) : Product(name, price), warranty{warranty} {};
    ~Electronic();

    Electronic(Electronic &other) : Product(other), warranty(other.warranty) {};
    Electronic(Electronic &&other) : Product(move(other)), warranty(other.warranty)
    {
        other.warranty = 0;
    };

    Electronic &operator=(Electronic &other)
    {
        if (this == &other)
        {
            return *this;
        };
        warranty = other.warranty;
        Product::operator=(other);
        return *this;
    }
    Electronic &operator=(Electronic &&other)
    {
        if (this == &other)
        {
            return *this;
        };
        warranty = other.warranty;
        other.warranty = 0;
        Product::operator=(move(other));
        return *this;
    };
};

class Inventory : public Product
{
    vector<Product *> p;

public:
    void displayDetails() override
    {
        for (auto i : p)
        {
            i->displayDetails();
        };
    };
    int calculatePrice(int discount) override
    {
        int val;
        for (auto i : p)
        {
            val += i->calculatePrice(discount);
        }
        return val;
    };

    Inventory(vector<Product *> val, string &name, int &price) : Product(name, price), p{val} {};
    ~Inventory()
    {
        for (auto i : p)
        {
            delete i;
        };
    };
};