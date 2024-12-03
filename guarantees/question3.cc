#include <iostream>
#include <stdexcept>
#include <memory>
#include <fstream>

using namespace std;

struct impl
{
    std::ofstream file;
};
class FileHandler
{
    unique_ptr<impl> pImpl{new impl};

public:
    FileHandler(const std::string &filename)
    {
        auto temp = make_unique<impl>(*pImpl);
        (temp->file).open(filename);
        if (!(temp->file).is_open())
            throw std::runtime_error("Failed to open file");
    }

    void write(const std::string &data)
    {
        (pImpl->file) << data;
    }

    ~FileHandler()
    {
        if ((pImpl->file).is_open())
        {
            (pImpl->file).close();
        }
    }
};

int main()
{
    try
    {
        FileHandler handler("output.txt");
        handler.write("Hello, World!");
        handler.write("");
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
