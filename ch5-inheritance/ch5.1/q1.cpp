#include <iostream>
using namespace std;

class x
{
protected:
    int a, b, c;
};

class y : public x
{
public:
    void setdata()
    {

        cout << "Enter three numbers: ";
        cin >> a >> b >> c;
    }

    void getdata()
    {
        int sum;

        sum = (a * a * a) + (b * b * b) + (c * c * c);

        cout << "Sum of cubes = " << sum << endl;
    }
};

int main()
{

    y obj;
    obj.setdata();
    obj.getdata();

    return 0;
}