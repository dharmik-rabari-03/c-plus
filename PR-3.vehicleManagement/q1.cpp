#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    Vehicle()
    {
        vehicleID = 0;
        year = 0;
    }

    Vehicle(int id, string manu, string mod, int yr)
    {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = yr;
        totalVehicles++;
    }

    virtual ~Vehicle() {}

    void setVehicleID(int id)
    {
        if (id > 0)
            vehicleID = id;
    }

    int getVehicleID()
    {
        return vehicleID;
    }

    void setManufacturer(string m)
    {
        manufacturer = m;
    }

    string getManufacturer()
    {
        return manufacturer;
    }

    virtual void display() const
    {
        cout << "ID             : " << vehicleID << endl;
        cout << "Manufacturer   : " << manufacturer << endl;
        cout << "Model          : " << model << endl;
        cout << "Year           : " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle
{
protected:
    string fuelType;

public:
    Car() : Vehicle() {}

    Car(int id, string manu, string mod, int yr, string fuel)
        : Vehicle(id, manu, mod, yr), fuelType(fuel) {}

    void display() const override
    {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType<<endl;
    }
};

class ElectricCar : public Car
{
protected:
    int batteryCapacity;

public:
    ElectricCar(int id, string manu, string mod, int yr, string fuel, int battery)
        : Car(id, manu, mod, yr, fuel), batteryCapacity(battery) {}

    void display() const override
    {
        Car::display();
        cout << ", Battery: " << batteryCapacity << " kWh";
    }
};

class SportsCar : public ElectricCar
{
    int topSpeed;

public:
    SportsCar(int id, string manu, string mod, int yr, string fuel, int battery, int speed)
        : ElectricCar(id, manu, mod, yr, fuel, battery), topSpeed(speed) {}

    void display() const override
    {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h"<<endl;
    }
};

class Sedan : public Car
{
public:
    Sedan(int id, string manu, string mod, int yr, string fuel)
        : Car(id, manu, mod, yr, fuel) {}

    void display() const override
    {
        cout << "[Sedan] "<<endl;
        Car::display();
    }
};

class SUV : public Car
{
public:
    SUV(int id, string manu, string mod, int yr, string fuel)
        : Car(id, manu, mod, yr, fuel) {}

    void display() const override
    {
        cout << "[SUV] "<<endl;
        Car::display();
    }
};

class Aircraft
{
protected:
    int flightRange;

public:
    Aircraft(int range = 0)
    {
        flightRange = range;
    }
};

class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar(int id, string manu, string mod, int yr, string fuel, int range)
        : Car(id, manu, mod, yr, fuel), Aircraft(range) {}

    void display() const
    {
        cout << "[FlyingCar] ID: " << vehicleID<<endl;
          cout   << ", Manufacturer: " << manufacturer<<endl;
          cout   << ", Model: " << model<<endl;
          cout   << ", Year: " << year<<endl;
           cout  << ", Fuel: " << fuelType<<endl;
           cout  << ", Flight Range: " << flightRange << " km"<<endl;
    }
};

class VehicleRegistry
{
    Vehicle *vehicles[50];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;
    }

    void addVehicle(Vehicle *v)
    {
        if (count < 50)
        {
            vehicles[count++] = v;
            cout << "Vehicle added successfully!"<<endl;
        }
        else
        {
            cout << "Registry is full!"<<endl;
        }
    }

    void displayAll() const
    {
        if (count == 0)
        {
            cout << "No vehicles found."<<endl;
            return;
        }

        for (int i = 0; i < count; i++)
        {
            vehicles[i]->display();
            cout << endl;
        }
    }

    void searchByID(int id) const
    {
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                vehicles[i]->display();
                cout << endl;
                return;
            }
        }
        cout << "Vehicle not found!"<<endl;
    }
};

int main()
{
    VehicleRegistry registry;
    int choice;

    do
    {
        cout << "\n===== Vehicle Registry System ====="<<endl;
        cout << "1. Add Sedan"<<endl;
        cout << "2. Add SUV"<<endl;
        cout << "3. Add Sports Car"<<endl;
        cout << "4. Add Flying Car"<<endl;
        cout << "5. View All Vehicles"<<endl;
        cout << "6. Search by ID"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        int id, year, battery, speed, range;
        string manu, model, fuel;

        switch (choice)
        {
        case 1:
            cout << "\n====== Add Sedan =====\n";
            cout << "Enter Vehicle ID        : ";
            cin >> id;
            cout << "Enter Manufacturer      : ";
            cin >> manu;
            cout << "Enter Model             : ";
            cin >> model;
            cout << "Enter Year              : ";
            cin >> year;
            cout << "Enter Fuel Type         : ";
            cin >> fuel;

            registry.addVehicle(new Sedan(id, manu, model, year, fuel));
            break;

        case 2:
            cout << "\n====== Add SUV =====\n";
            cout << "Enter Vehicle ID        : ";
            cin >> id;
            cout << "Enter Manufacturer      : ";
            cin >> manu;
            cout << "Enter Model             : ";
            cin >> model;
            cout << "Enter Year              : ";
            cin >> year;
            cout << "Enter Fuel Type         : ";
            cin >> fuel;

            registry.addVehicle(new SUV(id, manu, model, year, fuel));
            break;

        case 3:
            cout << "\n======= Add Sports Car ======\n";
            cout << "Enter Vehicle ID        : ";
            cin >> id;
            cout << "Enter Manufacturer      : ";
            cin >> manu;
            cout << "Enter Model             : ";
            cin >> model;
            cout << "Enter Year              : ";
            cin >> year;
            cout << "Enter Fuel Type         : ";
            cin >> fuel;
            cout << "Enter Battery Capacity  : ";
            cin >> battery;
            cout << "Enter Top Speed         : ";
            cin >> speed;

            registry.addVehicle(
                new SportsCar(id, manu, model, year, fuel, battery, speed));
            break;

        case 4:
            cout << "\n======= Add Flying Car =======\n";
            cout << "Enter Vehicle ID        : ";
            cin >> id;
            cout << "Enter Manufacturer      : ";
            cin >> manu;
            cout << "Enter Model             : ";
            cin >> model;
            cout << "Enter Year              : ";
            cin >> year;
            cout << "Enter Fuel Type         : ";
            cin >> fuel;
            cout << "Enter Flight Range      : ";
            cin >> range;

            registry.addVehicle(
                (Vehicle *)new FlyingCar(id, manu, model, year, fuel, range));
            break;

        case 5:
            cout << "\n======= All Registered Vehicles ========\n";
            registry.displayAll();
            break;

        case 6:
            cout << "\n======= Search Vehicle ========\n";
            cout << "Enter Vehicle ID        : ";
            cin >> id;
            registry.searchByID(id);
            break;

        case 7:
            cout << "\nExiting Vehicle Registry System...\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 7);

    cout << "Total Vehicles Created: " << Vehicle::totalVehicles << endl;
    return 0;
}
