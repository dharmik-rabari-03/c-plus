#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int rollNumber;

public:
    Student(string n, int r)
    {
        name = n;
        rollNumber = r;
    }

    void display()
    {
        cout << "Name: " << name << ", Roll No: " << rollNumber << endl;
    }
};

int main()
{
    Student students[2]{
        Student("dharmik   ", 101),
        Student("Ankit  ", 102),
    };

    for (int i = 0; i < 2; i++)
    {
        students[i].display();
    }

    return 0;
}