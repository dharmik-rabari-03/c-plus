#include <iostream>
using namespace std;

class Person
{
    string Name;
public:

    void setName(string n)
    {
        Name = n;
    }

    void getName()
    {
        cout << "Name : " << Name << endl;
    }
};

int main()
{
    Person s1;
    s1.setName("Dharmik");
    s1.getName();

    Person s2;
    s2.setName("Prince");
    s2.getName();

    return 0;
}