#include <iostream>
using namespace std;

class customer
{
private:
    int cust_id;
    string cust_name;
    int cust_age;
    string cust_city;
    string cust_mobile_number;
    int cust_simcard_validity;
    string cust_telecom_brand_name;

public:
    void setdata(int id, string name, int age, string city, string number, int validity, string telecom)
    {

        cust_id = id;
        cust_name = name;
        cust_age = age;
        cust_city = city;
        cust_mobile_number = number;
        cust_simcard_validity = validity;
        cust_telecom_brand_name = telecom;
    }

    void getdata(int i)
    {

        cout << "\n\nRecord of customer " << i + 1 << endl;

        cout << "ID      : " << cust_id << endl;
        cout << "NAME    : " << cust_name << endl;
        cout << "AGE     : " << cust_age << endl;
        cout << "CITY    : " << cust_city << endl;
        cout << "NUMBER  : " << cust_mobile_number << endl;
        cout << "VALIDITY: " << cust_simcard_validity << endl;
        cout << "TELECOM : " << cust_telecom_brand_name << endl;
    }
};

int main()
{

    customer c[5];

    for (int i = 0; i < 5; i++)
    {
        int id, age, validity;
        string name, city, number, telecom;

        cout << "Enter Detail Of Customer " << i + 1 << endl;

        cout << "id:";
        cin >> id;

        cout << "name:";
        cin >> name;

        cout << "age:";
        cin >> age;

        cout << "city:";
        cin >> city;

        cout << "number:";
        cin >> number;

        cout << "validity:";
        cin >> validity;

        cout << "telecom:";
        cin >> telecom;

        c[i].setdata(id, name, age, city, number, validity, telecom);
    }

    for (int i = 0; i < 5; i++)
    {
        c[i].getdata(i);
    }

    return 0;
}