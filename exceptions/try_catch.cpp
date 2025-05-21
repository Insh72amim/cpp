#include <iostream>

using namespace std;

int main()
{
    try
    {
        int *myarray = new int[1000];
    }
    catch (bad_alloc &)
    {
        cout << "Error allocating memory." << endl;
    }
    return 0;
}