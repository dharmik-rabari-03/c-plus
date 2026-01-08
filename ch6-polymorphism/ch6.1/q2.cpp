#include <iostream>
using namespace std;

class Cricket
{

public:
    virtual int getMatchOvers()
    {

        return 0;
    }
};
class T20 : public Cricket
{

public:
    virtual int getMatchOvers() override
    {

        return 20;
    }
};

class TestMatch : public Cricket
{

public:
    virtual int getMatchOvers() override
    {

        return 90;
    }
};

int main()
{
    Cricket* obj;
    T20 t20;
    TestMatch Test;


    obj=&t20;
    cout<<"T20 Match Overs: "<<obj->getMatchOvers()<<endl;


    obj=&Test;
    cout<<"Test Match Over: "<<obj->getMatchOvers()<<endl;


    return 0;
}