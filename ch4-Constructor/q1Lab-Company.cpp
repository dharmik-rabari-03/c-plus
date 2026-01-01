#include <iostream>
using namespace std;

class DiamondCompany
{
private:
    int comp_id;
    string comp_name;
    int comp_staff_quantity;
    int comp_revenue;
    int comp_import_raw_diamonds;
    int comp_export_diamonds;
    string comp_ceo;

public:
    DiamondCompany(int id, string name, int staff, int revenue,
                   int import_dia, int export_dia, string ceo)
    {

        comp_id = id;
        comp_name = name;
        comp_staff_quantity = staff;
        comp_revenue = revenue;
        comp_import_raw_diamonds = import_dia;
        comp_export_diamonds = export_dia;
        comp_ceo = ceo;
    }

    void getdata(int i)
    {
        cout << "\nCompany " << i + 1 << " Details\n";
        cout << "ID                   :" << comp_id << endl;
        cout << "Name                 :" << comp_name << endl;
        cout << "Staff Quantity       :" << comp_staff_quantity << endl;
        cout << "Revenue (per year)   :" << comp_revenue << endl;
        cout << "Imported Raw Diamonds: " << comp_import_raw_diamonds << endl;
        cout << "Exported Diamonds    :" << comp_export_diamonds << endl;
        cout << "CEO Name             :" << comp_ceo << endl;
    }

    ~DiamondCompany()
    {
        cout << "Destructor Called " << endl;
    }
};

int main()
{

    int n;
    cout << "\nEnter number of companies: ";
    cin >> n;

    DiamondCompany *Company[n];

    for (int i = 0; i < n; i++)
    {
        int id, staff, revenue, import_dia, export_dia;
        string name, ceo;

        cout << "\n\nEnter Detail Of Company" << i + 1 << endl;

        cout << "id                         :";
        cin >> id;
        cin.ignore();

        cout << "Enter Company Name         :";
        getline(cin, name);

        cout << "Enter Staff Quantity       :";
        cin >> staff;
        cin.ignore();

        cout << "Enter Revenue              :";
        cin >> revenue;
        cin.ignore();

        cout << "Enter Imported Raw Diamonds:";
        cin >> import_dia;
        cin.ignore();

        cout << "Enter Exported Diamonds    :";
        cin >> export_dia;
        cin.ignore();

        cout << "Enter CEO Name             :";
        getline(cin, ceo);

        DiamondCompany Company(id, name, staff, revenue, import_dia, export_dia, ceo);

        Company.getdata(i);
    }

    return 0;
}