#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter first numbers: ";
    cin >> a;

    cout << "Enter second numbers: ";
    cin >> b;

    try
    {
        if (b == 0)
            throw "Cannot divide by zero";

        cout << "Result = " << a / b << endl;
    }
    catch (const char *msg)
    {
        cout << "Exception: " << msg << endl;
    }

    return 0;
}
