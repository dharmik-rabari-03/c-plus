#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{

private:
    int Roll;
    float Gpa;
    string Name;

public:
    // default Constructor

    Student()
    {
        Roll = 0;
        Gpa = 0.00;
        Name = "Not Set";

        cout << "Defualt constructor is called" << endl;
    }

    // parameterized Constructor

    Student(int r, float g, string n)
    {

        Roll = r;
        Gpa = g;
        Name = n;

        cout << "parameterized Constructor Called" << endl;
    }

    // copy constructor

    Student(const Student &s)
    {

        Roll = s.Roll;
        Gpa = s.Gpa;
        Name = s.Name;

        cout << "Copy Constructor Called" << endl;
    }

    // getter methods

    int GetRoll() const
    {
        return Roll;
    }
    float GetGpa() const
    {
        return Gpa;
    }

    string GetName() const
    {
        return Name;
    }

    void display() const
    {
        cout << "Name :" << Name << "Roll no :" << Roll << "Gpa :" << Gpa << endl;
    }

    ~Student()
    {
        cout << "Destructure called" << endl;
    }
};

class StudentRecordManagement
{

private:
    vector<Student> Students;

public:
    void AddStudent(const Student &s)
    {
        Students.push_back(s);
        cout << "student Data added";
    }

    void DisplayAllData()
    {
        cout << "all student detail are" << endl;

        if (Students.empty())
        {
           cout<<"No Record Available"<<endl;
        }
        else{
            for (int i = 0; i < Students.size(); i++)
            {
                Students[i].display();
            }
            
        }
        
    }
};

int main()
{

    Student s1(1,7.7,"Dharmik");
    Student s2(2,8.7,"Ankit");
    Student s3(3,9.7,"Prince");

    StudentRecordManagement Manager;

    Manager.AddStudent(s1);
    Manager.AddStudent(s2);
    Manager.AddStudent(s3);

    Manager.DisplayAllData();
    
    return 0;
}