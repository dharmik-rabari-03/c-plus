#include <iostream>
using namespace std;

class X
{
protected:
    int a, b, c;
};

class Y : public X
{
public:
    void setData()
    {
        cout << "Enter three numbers: ";
        cin >> a >> b >> c;
    }

    void getData()
    {
        int sum;
        sum = (a * a * a) + (b * b * b) + (c * c * c);
        cout << "Sum of cubes = " << sum << endl;
    }
};

int main()
{
    Y obj;
    obj.setData();
    obj.getData();
    return 0;
}
