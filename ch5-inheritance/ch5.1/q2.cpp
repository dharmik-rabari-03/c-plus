#include <iostream>
using namespace std;

class p
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

class q : public p
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

class r : public q
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

    r obj;

    obj.gettemp();
    obj.ToFehrainheat();
    obj.Tokelvin();

    return 0;
}