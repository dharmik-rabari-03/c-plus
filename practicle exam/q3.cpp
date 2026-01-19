#include <iostream>
using namespace std;

class Device
{
protected:
    string brand;
    int power;
};

class Laptop : public Device
{
public:
    void setData(string b, int p)
    {
        brand = b;
        power = p;
    }

    void display()
    {

        cout << "Laptop :"  << brand << " "<<power << endl;
    }
};

class SmartPhone : public Device
{
public:
    void setData(string b, int p)
    {
        brand = b;
        power = p;
    }

    void display()
    {
        cout << "SmartPhone :"<< brand <<" "<< power << endl;
    }
};

int main()
{

    Laptop l;
    SmartPhone s;

    l.setData("Asus", 65);
    l.display();

    s.setData("Iphone", 20);
    s.display();

    return 0;
}