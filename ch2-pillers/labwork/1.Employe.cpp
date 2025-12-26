#include <iostream>
using namespace std;

class Employee
{

public:
    int emp_id;
    string emp_name;
    int emp_age;
    string emp_role;
    int emp_salary;
    string emp_city;
    int emp_experience;
    string emp_company_name;

    void setData(int id, string name, int age, string role, int salary, string city, int experience, string company)
    {
        emp_id = id;
        emp_name = name;
        emp_age = age;
        emp_role = role;
        emp_salary = salary;
        emp_city = city;
        emp_experience = experience;
        emp_company_name = company;
    }

    void getData(int i)
    {
        cout << "\n\nRecord of employee " << i + 1 << endl;

        cout<<"ID          :"<<emp_id<<endl;
        cout<<"NAME        :"<<emp_name<<endl;
        cout<<"AGE         :"<<emp_age<<endl;
        cout<<"ROLE        :"<<emp_role<<endl;
        cout<<"SALARY      :"<<emp_salary<<endl;
        cout<<"CITY        :"<<emp_city<<endl;
        cout<<"EXPERIENCE  :"<<emp_experience<<endl;
        cout<<"COMPANY NAME:"<<emp_company_name<<endl;
    }
};

int main()
{
    Employee e[5];


    int id,age,salary,experience;
    string name,role,city,company;


    for (int i = 0; i <5; i++)
    {
        cout<<"\n\nDetail of Employee "<<i+1<<endl;

        cout<<"id: ";
        cin>>id;

        cout<<"name: ";
        cin>>name;


        cout<<"age: ";
        cin>>age;


        cout<<"role: ";
        cin>>role;


        cout<<"salary: ";
        cin>>salary;


        cout<<"city: ";
        cin>>city;

        cout<<"experience: ";
        cin>>experience;

        cout<<"company name: ";
        cin>>company;

        e[i].setData(id,name,age,role,salary,city,experience,company);
    }

    for (int i = 0; i <5; i++)
    {
        e[i].getData(i);
    }
    
    


    return 0;
}
