#include <iostream>
using namespace std;

template <class T>
class Mypair
{
    T values[2];

public:
    Mypair(T first, T second)
    {
        values[0] = first;
        values[1] = second;
    }
};

template <typename T>
class AnotherPair
{
    T values[2];

public:
    AnotherPair(T first, T second)
    {
        values[0] = first;
        values[1] = second;
    }
};

int main()
{
    Mypair<int> *mp = new Mypair(1, 2);
}