#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string model;
    int year;
    int speed;

public:
    void set(string m, int y, int s)
    {
        model = m;
        year = y;
        speed = s;
    }

    void display()
    {

        cout << "model  :" << model << endl;
        cout << "year  :" << year << endl;
        cout << "model  :" << model << endl;
    }
};

int main()
{

    Car C;
    C.set("swift",2022,100);
    C.display();

return 0;
}