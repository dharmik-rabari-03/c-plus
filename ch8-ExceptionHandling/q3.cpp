#include <iostream>
#include <string>
using namespace std;

int main()
{
    string password;
    bool Upper = false;

    cout << "Enter password: ";
    cin >> password;

    try
    {
        for (int i = 0; i < password.length(); i++)
        {
            if (password[i] >= 'A' && password[i] <= 'Z')
            {
                Upper = true;
                break;
            }
        }

        if (!Upper)
            throw password;

        cout << "Password is valid" << endl;
    }
    catch (string p)
    {
        cout << "Exception: Password must contain at least one uppercase letter" << endl;
    }

    return 0;
}
