#include <iostream>
using namespace std;

class student
{

public:
    void name()
    {
        cout << "ragiya" << endl;
    }
};

class teacher : public student
{
public:
    void name()
    {
        cout << "dharmik" << endl;
    }
};

int main()
{

    teacher s1;
    s1.name();

    return 0;
}