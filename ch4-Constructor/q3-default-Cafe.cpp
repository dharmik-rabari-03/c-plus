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
    Cafe()
    {
        cafe_name = "Not Set";
        cafe_type = "Not Set";
        cafe_rating = 0;
        cafe_location = "Not set";
        cafe_establish_year = 0;
        cafe_staff_quantity = 0;
    }

    void SetData()
    {

       

        cout << "\nNAME         :";
        getline(cin, cafe_name);

        cout << "Cafe Type      :";
        getline(cin, cafe_type);

        cout << "Rating         :";
        cin >> cafe_rating;
        cin.ignore();

        cout << "Location       :";
        getline(cin, cafe_location);

        cout << "establish year :";
        cin >> cafe_establish_year;
        cin.ignore();

        cout << "Staff Quantity :";
        cin >> cafe_staff_quantity;
        cin.ignore();
    }

    void DisplayData()
    {

       

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

  

    for (int i = 0; i < n; i++)
    {
        Cafe C;
        cout<<"\nEnter detail of Cafe"<<endl;
        C.SetData();

        cout<<"\n\nDetail of cafe"<<endl;
        C.DisplayData();
        
    }
    

    return 0;
}