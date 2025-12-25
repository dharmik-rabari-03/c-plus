#include <iostream>
using namespace std;

class Student
{
private:
    int marks = 80;

public:
    void setmark(int n)
    {
        marks = n;
    }

    void getmark()
    {
        cout << "Mark : " << marks << endl;
    }
};
int main()
{

    Student s1;

    s1.setmark(60);
    s1.getmark();

    Student s2;

    s2.setmark(70);
    s2.getmark();

    return 0;
}