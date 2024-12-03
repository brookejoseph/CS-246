#include <iostream>
#include <stdexcept>

class Logger
{
    std::string name;

public:
    Logger(const std::string &name) : name(name)
    {
        std::cout << "Entering: " << name << std::endl;
    }
    ~Logger()
    {
        std::cout << "Exiting: " << name << std::endl;
    }
};

void deepFunction()
{
    Logger log("deepFunction");
    throw std::runtime_error("Error in deepFunction");
}

void middleFunction()
{
    Logger log("middleFunction");
    try
    {
        deepFunction();
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught in middleFunction: " << e.what() << std::endl;
        std::cout << "Rethrowing exception...\n";
        throw;
    }
}

void topFunction()
{
    Logger log("topFunction");
    middleFunction();
}

int main()
{
    try
    {
        topFunction();
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught in main: " << e.what() << std::endl;
    }
    return 0;
}
