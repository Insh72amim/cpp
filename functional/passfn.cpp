#include <iostream>
#include <functional>

using namespace std;

class Something
{
public:
    void sayHello()
    {
        cout << "Hello\n";
    }
};

void print_num(int i)
{
    std::cout << i << '\n';
}

int main()
{
    Something *s = new Something();
    s->sayHello();

    function<void(int)> f_display = print_num;
    f_display(-9);
}