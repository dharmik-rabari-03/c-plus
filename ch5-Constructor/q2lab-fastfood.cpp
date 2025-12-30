#include <iostream>
using namespace std;

class Cafe
{
private:
    string cafe_name;
    string cafe_type;
    int cafe_rating;
    string cafe_location;
    int cafe_establish_year;
    int cafe_staff_quantity;

public:
    Cafe(string name, string type, int rating, string location, int year, int quantity)
    {

        cafe_name = name;
        cafe_type = type;
        cafe_rating = rating;
        cafe_location = location;
        cafe_establish_year = year;
        cafe_staff_quantity = quantity;
    }

    void DisplayData(int i)
    {
        cout << "\n\nDetail Of Cafe :" << i + 1 << endl;

        cout << "Name           :" << cafe_name << endl;
        cout << "Type           :" << cafe_type << endl;
        cout << "Rating         :" << cafe_rating << endl;
        cout << "Location       :" << cafe_location << endl;
        cout << "establish year :" << cafe_establish_year << endl;
        cout << "Staff Quantity :" << cafe_staff_quantity << endl;
    }
};

int main()
{

    int n;
    cout << "\nEnter number of Cafe :";
    cin >> n;
    cin.ignore();

    Cafe *c[n];

    for (int i = 0; i < n; i++)
    {

        string name, type, location;
        int rating, year, quantity;

        cout << "\n\nEnter Detail Of Cafe " << i + 1 << ":" << endl;

        cout << "\nNAME         :";
        getline(cin, name);

        cout << "Cafe Type      :";
        getline(cin, type);

        cout << "Rating         :";
        cin >> rating;
        cin.ignore();

        cout << "Location       :";
        getline(cin, location);

        cout << "establish year :";
        cin >> year;
        cin.ignore();

        cout << "Staff Quantity :";
        cin >> quantity;
        cin.ignore();

        c[i] = new Cafe(name, type, rating, location, year, quantity);
    }

    for (int i = 0; i < n; i++)
    {
        c[i]->DisplayData(i);
    }

    return 0;
}
