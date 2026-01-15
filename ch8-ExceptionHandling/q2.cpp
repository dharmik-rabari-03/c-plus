#include <iostream>
using namespace std;

int main()
{
    int age;

    cout << "Enter your age: ";
    cin >> age;

    try
    {
        if (age < 18)
            throw age;

        cout << "You are eligible to vote" << endl;
    }
    catch (int a)
    {
        cout << "Exception: Age must be 18 or above to vote" << endl;
    }

    return 0;
}
