#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void makeSound() = 0;
    virtual void move() = 0;
};

class Lion : public Animal
{
public:
    void makeSound()
    {
        cout << "lion sound" << endl;
    }
    void move()
    {
        cout << "lion move" << endl;
    }
};

class Fish : public Animal
{
public:
    void makeSound()
    {
        cout << "Fish sound" << endl;
    }
    void move()
    {
        cout << "Fish move" << endl;
    }
};

int main()
{

    Lion l;
    Fish f;

    l.makeSound();
    l.move();

    f.makeSound();
    f.move();

    return 0;
}