#include <iostream>
using namespace std;

class Calculate
{

public:
      void Calculator(int a, int b)
    {

        cout<<"Division :"<<a/b<<endl;
    }

       void Calculator(int a, int b,int c)
    {

        cout<<"substraction :"<<a-b-c<<endl;
    }

        void Calculator(int a, int b,int c,int d)
    {

        cout<<"Multiplication :"<<a*b*c*d<<endl;
    }

        void Calculator(int a, int b,int c,int d,int e)
    {

        cout<<"Addition :"<<a+b+c+d+e<<endl;
    }

};



int main()
{

    Calculate obj;

    obj.Calculator(10,2);
    obj.Calculator(200,40,20);
    obj.Calculator(2,4,5,6);
    obj.Calculator(10,20,30,40,50);

    return 0;
}
