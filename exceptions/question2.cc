#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

int main()
{
    try
    {
        cout << "first try block" << endl;
        try
        {
            cout << "second try block" << endl;
            throw domain_error("An error occurred");
        }
        catch (const runtime_error &e)
        {
            cout << "within the runtime error block" << endl;
            throw e;
        }
        catch (const logic_error &e)
        {
            cout << "within the domain error block" << endl;
            throw e;
        }
    }
    catch (const logic_error &e)
    {
        cout << "catching the error within the outer block" << endl;
    }

    catch (...)
    {
        cout << "hello world" << endl;
    }
    return 0;
}
