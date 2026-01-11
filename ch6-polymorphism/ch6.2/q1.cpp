#include <iostream>
using namespace std;

class Number
{
private:
    int Value;

public:
    Number(int n)
    {
        Value = n;
    }

    bool operator<(Number obj)
    {

        return Value < obj.Value;
    }

    void display()
    {
        cout << Value;
    }
};
int main()
{

    Number n1(20);
    Number n2(40);

    if (n1 < n2)
    {
        cout << "Second object Contain Higher Value :";
        n2.display();
    }
    else
    {
        cout << "First object Contain Higher Value :";
        n1.display();
    }

    return 0;
}