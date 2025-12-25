#include <iostream>

using namespace std;

class Parent
{
protected:
    char name[50] = "bob";

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

    Parent p1;


    return 0;
}




// #include <iostream>

// using namespace std;

// class Parent
// {

// public:
//     void getParentName()
//     {

//         cout << "the parent name is " << "alice" << endl;
//     };
// };

// class Child : public Parent

// {

// public:
//     void parentName()
//     {

//         getParentName();
//     }
// };

// int main()
// {
//     Child c1;

//     c1.parentName();

//     return 0;
// }