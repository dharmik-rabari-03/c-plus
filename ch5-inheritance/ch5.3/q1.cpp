int main()
{
    const int MAX = 10;
    Employee* emp[MAX];   // array of pointer objects
    int count = 0;
    int choice;

    do
    {
        cout << "\n===== Employee Management System =====" << endl;
        cout << "1. Add Full Time Employee" << endl;
        cout << "2. Add Part Time Employee" << endl;
        cout << "3. Display All Employees" << endl;
        cout << "4. Delete Last Employee" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 && count < MAX)
        {
            int id, age;
            double salary, bonus;
            string name;

            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Salary: ";
            cin >> salary;
            cout << "Enter Bonus: ";
            cin >> bonus;

            FullTimeEmployee* fte = new FullTimeEmployee();
            fte->setFullTimeEmployee(id, name, age, salary, bonus);
            emp[count++] = fte;
        }
        else if (choice == 2 && count < MAX)
        {
            int id, age;
            double salary;
            float hours;
            string name;

            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Salary: ";
            cin >> salary;
            cout << "Enter Hours Worked: ";
            cin >> hours;

            PartTimeEmployee* pte = new PartTimeEmployee();
            pte->setPartTimeEmployee(id, name, age, salary, hours);
            emp[count++] = pte;
        }
        else if (choice == 3)
        {
            for (int i = 0; i < count; i++)
            {
                emp[i]->display(); // polymorphism
            }
        }
        else if (choice == 4)
        {
            if (count > 0)
            {
                delete emp[count - 1]; // free memory
                count--;
                cout << "Employee deleted successfully." << endl;
            }
            else
            {
                cout << "No employee to delete." << endl;
            }
        }

    } while (choice != 5);

    // Free all remaining memory
    for (int i = 0; i < count; i++)
    {
        delete emp[i];
    }

    cout << "Program exited. Memory freed." << endl;
    return 0;
}
