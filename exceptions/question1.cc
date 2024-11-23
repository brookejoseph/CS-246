#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

int main()
{
    int hello = 0;
    try
    {
        throw logic_error("An error occurred");
    }
    catch (const logic_error &e)
    {
        if (hello == 2)
        {
            cout << "done trying" << endl;
        }
        else
        {
            cout << e.what() << endl;
            cout << "returning in the outer catch block" << endl;
            hello++;
            throw;
        }
    }
    catch (...)
    {
        cout << "catch all block" << endl;
    }
    return 0;
};