#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    int employee_id;
    string name;
    int age;
    double salary;

public:
    void setEmployee(int id, string n, int a, double s)
    {
        employee_id = id;
        name = n;
        age = a;
        salary = s;
    }

    virtual void display()
    {
        cout << "Employee ID : " << employee_id << endl;
        cout << "Name        : " << name << endl;
        cout << "Age         : " << age << endl;
        cout << "Salary      : " << salary << endl;
    }

    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee
{
private:
    double bonus;

public:
    FullTimeEmployee(int id, string n, int a, double s, double b)
    {
        setEmployee(id, n, a, s);
        bonus = b;
    }

    void display() override
    {
        Employee::display();
        cout << "Bonus       : " << bonus << endl;
    }
};

class PartTimeEmployee : public Employee
{
private:
    float hours_worked;

public:
    PartTimeEmployee(int id, string n, int a, double s, int h)
    {
        setEmployee(id, n, a, s);
        hours_worked = h;
    }

    void display() override
    {
        cout << "\n part time employees";
        Employee::display();
        cout << "Hours Worked: " << hours_worked << endl;
    }
};

int main()
{
    const int max = 10;
    Employee *emp[max];
    int count = 0;
    int Choice;

    do
    {
        cout << "\n ===== Menu =====\n";
        cout << "1. Add Full Time Employee \n";
        cout << "2. Add Part Time Employee \n";
        cout << "3. Display Employee \n";
        cout << "4. Delete Employee \n";
        cout << "5. Exit \n";
        cout << " Enter Choice: ";
        cin >> Choice;

        if (Choice == 1)
        {
            int id, age;
            double salary, bonus;
            string name;

            cout << "Enter Id :";
            cin >> id;

            cout << "Enter Name :";
            cin >> name;

            cout << "Enter Age :";
            cin >> age;

            cout << "Enter Salary :";
            cin >> salary;

            cout << "Enter Bonus :";
            cin >> bonus;

            emp[count++] = new FullTimeEmployee(id, name, age, salary, bonus);
        }
        else if (Choice == 2)
        {
            int id, age;
            double salary;
            string name;
            float hours;

            cout << "Enter Id :";
            cin >> id;

            cout << "Enter Name :";
            cin >> name;

            cout << "Enter Age :";
            cin >> age;

            cout << "Enter Salary :";
            cin >> salary;

            cout << "Enter hours :";
            cin >> hours;

            emp[count++] = new PartTimeEmployee(id, name, age, salary, hours);
        }
        else if (Choice == 3)
        {
            for (int i = 0; i < count; i++)
            {
                emp[i]->display();
            }
        }
        else if (Choice == 4)
        {
            int index;
            cout << "Enter index to delete: ";
            cin >> index;

            delete emp[index];
            for (int i = index; i < count - 1; i++)
            {
                emp[i] = emp[i + 1];
            }
        }

        else if (Choice == 5)
        {
            for (int i = 0; i < count; i++)
            {
                delete emp[i];
            }
            cout << "Memory cleared. Exit.\n";
        }
        else
        {
            cout << "Invalid Choice\n";
        }
    } while (Choice != 5);

    return 0;
}
