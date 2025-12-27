#include <iostream>
using namespace std;

class Vehicle
{

private:
    int vehicle_id;
    string owner_name;
    string vehicle_type;
    string brand;
    int registration_year;
    string fuel_type;

    static int totalcount;

public:
    void setData(int id, string name, string type, string brand, int year, string fuelType)
    {

        vehicle_id = id;
        owner_name = name;
        vehicle_type = type;
        this->brand = brand;
        registration_year = year;
        fuel_type = fuelType;

        totalcount++;
    }

    void getData(int i)
    {

        cout << "\n\nVehicle Detail  :" << i+1<<endl;

        cout <<"ID               :"<< vehicle_id << endl;
        cout <<"OWNER NAME       :"<< owner_name << endl;
        cout <<"VEHICLE TYPE     :" <<vehicle_type << endl;
        cout << "BRAND           :"<<brand << endl;
        cout <<"REGISTRATION YEAR:" <<registration_year << endl;
        cout <<"FUEL TYPE        :" <<fuel_type << endl;
    }

    static void total()
    {
        cout <<"\nTotal vehicle :"<< totalcount << endl;
    }
};

int Vehicle::totalcount = 0;

int main()
{

    int n;
    cout << "Enter total Index Of Vehicle : " << endl;
    cin >> n;

    Vehicle v[n];

    for (int i = 0; i < n; i++)
    {

        int id, year;
        string name,type,brand,fuelType;

        cout <<"\n\nEnter Detail of Vehicle :"<<i+1<<endl;

        cout << "ID               : ";
        cin >> id;
        cin.ignore();

        cout << "Owner Name       : ";
        getline(cin, name);

        cout << "Vehicle Type     : ";
        getline(cin, type);

        cout << "Brand            : ";
        getline(cin, brand);

        cout << "Registration Year: ";
        cin >> year;
        cin.ignore();

        cout << "Fuel Type        : ";
        getline(cin, fuelType);

        v[i].setData(id,name,type,brand,year,fuelType);
    }

    for (int i = 0; i < n; i++)
    {
      v[i].getData(i);
    }


    Vehicle::total();
    

    return 0;
}