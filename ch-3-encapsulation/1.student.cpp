#include <iostream>
using namespace std;

class Student
{

private:
    int stu_id;
    string stu_name;
    int stu_age;
    string stu_course;
    string stu_city;
    string stu_email;
    string stu_college;

public:
    void setdata(int id, string name, int age, string course, string city, string email, string college)
    {

        stu_id = id;
        stu_name = name;
        stu_age = age;
        stu_course = course;
        stu_city = city;
        stu_email = email;
        stu_college = college;
    }

    void getdata(int i)
    {

        cout << "\n\nrecord of student " << i + 1 << endl;
        cout << "\nID: " << stu_id << endl;
        cout << "NAME: " << stu_name << endl;
        cout << "AGE: " << stu_age << endl;
        cout << "COURSE: " << stu_course << endl;
        cout << "CITY: " << stu_city << endl;
        cout << "EMAIL: " << stu_email << endl;
        cout << "COLLEGE: " << stu_college << endl;
    }
};

int main()
{

    Student s[5];

    for (int i = 0; i < 5; i++)
    {

        int id, age;
        string name, course, city, email, college;

        cout << "Enter Detail Of student " << i + 1 << endl;

        cout << "ID: ";
        cin >> id;

        cout << "AGE: ";
        cin >> age;

        cout << "NAME: ";
        cin >> name;

        cout << "COURSE: ";
        cin >> course;

        cout << "CITY: ";
        cin >> city;

        cout << "EMAIL: ";
        cin >> email;

        cout << "COLLEGE: ";
        cin >> college;

        s[i].setdata(id, name, age, course, city, email, college);
    }

    for (int i = 0; i < 5; i++)
    {
        s[i].getdata(i);
    }

    return 0;
}
