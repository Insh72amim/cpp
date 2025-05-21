#include <iostream>

using namespace std;

template <class T>
class Myvector
{
public:
    int size;
    T *arr;

    Myvector(int sz)
    {
        size = sz;
        arr = new T[size];
    }

    void printarr()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    T dotproduct(Myvector &v)
    {
        T res = 0;
        for (int i = 0; i < size; i++)
            res += arr[i] * v.arr[i];
        return res;
    }
};

int main()
{
    Myvector<double> h(4);
    h.arr[0] = 1.3;
    h.arr[1] = 2.45;
    h.arr[2] = 7.34;
    h.arr[3] = 8.98;
    h.printarr();

    Myvector<double> c(4);
    c.arr[0] = 5.89;
    c.arr[1] = 6.76;
    c.arr[2] = 2.34;
    c.arr[3] = 4.11;
    c.printarr();

    cout << h.dotproduct(c) << endl;

    return 0;
}