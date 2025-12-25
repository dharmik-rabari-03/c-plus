#include <iostream>

using namespace std;

class Parent
{
protected:
    char name[100] = "bob";

public:
    void getParentName()
    {

        cout << "the parent name is " << "alice" << endl;
    };
};

class Child : public Parent

{

public:
    void parentName()
    {

        getParentName();
    }

    void getName()
    {
        name;
    }
};

int main()

{

    Child c1;

    c1.parentName();

    return 0;
}