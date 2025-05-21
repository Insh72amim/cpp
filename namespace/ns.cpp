#include <iostream>
using namespace std;

namespace first
{
    int var = 5;
}

namespace second
{
    double var = 3.1416;
}

namespace myNamespace
{
    int a, b;
}

namespace something
{
    template <class T>
    T add(T a, T b)
    {
        return a + b;
    }

    class Employee
    {
        int age;
        string name;
        string role;

    public:
        Employee(string name, int age, string role)
        {
            this->age = age;
            this->name = name;
            this->role = role;
        }

        void whoareyou()
        {
            cout << "Hi, This employee is " << this->name << " who is of age " << this->age << " and work as  a  " << this->role << endl;
        }
    };
}

int main()
{
    cout << first::var << endl;
    cout << second::var << endl;
    cout << myNamespace::a << " " << myNamespace::b << endl;

    something::Employee amim("amim", 23, "sde");
    amim.whoareyou();

    return 0;
}