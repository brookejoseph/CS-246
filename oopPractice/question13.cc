#include <iostream>
#include <stdexcept>

class LoopLogger
{
    int id;

public:
    LoopLogger(int id) : id(id)
    {
        std::cout << "Start object " << id << std::endl;
    }
    ~LoopLogger()
    {
        std::cout << "End object " << id << std::endl;
    }
};

void loopFunction(int n)
{
    for (int i = 0; i < n; ++i)
    {
        LoopLogger log(i);
        if (i == 3)
        {
            throw std::runtime_error("Error at iteration " + std::to_string(i));
        }
    }
}

int main()
{
    try
    {
        loopFunction(5);
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught in main: " << e.what() << std::endl;
    }
}
