#include <iostream>
using namespace std;

class Device
{
public:
     int calculateDiscount()
    {
        return 0;
    }

};

class Laptop:public Device{
    public:

    virtual int calculateDiscount(){
        return 2000;
    }
};

class SmartPhone:public Device{
    public:

    virtual int calculateDiscount(){
        return 900;

        
    }
};


int main()
{

    Laptop l;
    SmartPhone s;

    cout <<l.calculateDiscount()<<endl;
    cout <<s.calculateDiscount()<<endl;
    
   

    return 0;
}