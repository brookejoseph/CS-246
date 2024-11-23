#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Book
{
private:
    string author;
    int dataYear;
    int length;

public:
    Book(string author = "Bob", int dataYear = 1999, int length = 205)
    {
        this->author = author;
        this->dataYear = dataYear;
        this->length = length;
    };
    ~Book() = default;
    Book(const Book &other)
    {
        this->author = other.author;
        this->dataYear = other.dataYear;
        this->length = other.length;
    };
    Book(Book &&other)
    {
        this->author = other.author;
        this->dataYear = other.dataYear;
        this->length = other.length;

        other.author = "";
        other.dataYear = 0;
        other.length = 0;
    };

    Book &operator=(const Book &other)
    {
        if (this == &other)
        {
            return *this;
        };
        this->author = other.author;
        this->dataYear = other.dataYear;
        this->length = other.length;
        return *this;
    }
    Book &operator=(Book &&other)
    {
        if (this == &other)
        {
            return *this;
        };
        this->author = other.author;
        this->dataYear = other.dataYear;
        this->length = other.length;

        other.author = "";
        other.dataYear = 0;
        other.length = 0;

        return *this;
    }
};