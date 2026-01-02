#include <iostream>
using namespace std;

class P
{
protected:
    float celsius;

public:
    void gettemp()
    {
        cout << "Enter temprature in celsius :" << endl;
        cin >> celsius;
    }
};

class Q : public P
{

protected:
    float fahrenheit;

public:
    void ToFehrainheat()
    {
        fahrenheit = (celsius * 9 / 5) + 32;
        cout << "Temperature in Fahrenheit: " << fahrenheit << endl;
    }
};

class R : public Q
{

protected:
    float kelvin;

public:
    void Tokelvin()
    {
        kelvin = (fahrenheit - 32) * 5 / 9 + 273.15;
        cout << "Temperature in Kelvin: " << kelvin << endl;
    }
};

int main()
{

    R obj;

    obj.gettemp();
    obj.ToFehrainheat();
    obj.Tokelvin();

    return 0;
}