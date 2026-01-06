#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Train
{

private:
    int train_number;
    string train_name;
    string source;
    string destination;
    string train_time;

public:
    Train()
    {

        train_number = 0;
        train_name = "not set";
        source = "not set";
        destination = "not set";
        train_time = "not set";
    }

    Train(int num, string name, string source, string destination, string time)
    {

        train_number = num;
        train_name = name;
        this->source = source;
        this->destination = destination;
        train_time = time;
    }

    Train(const Train &t)
    {

        train_number = t.train_number;
        train_name = t.train_name;
        source = t.source;
        destination = t.destination;
        train_time = t.train_time;
    }

    int getTrain() const
    {
        return train_number;
    }

    void display() const
    {
        cout << "\nTrain Number : " << train_number
             << "\nTrain Name   :" << train_name
             << "\nSource       :" << source
             << "\nDestination  : " << destination
             << "\nTrain Time   :" << train_time<<endl;
    }
};

class RailwaySystem
{

private:
    vector<Train> trains;

public:
    void addTrain()
    {

        int t_number;
        string t_name;
        string t_source;
        string t_destination;
        string t_time;

        cout << "\nEnter train number  : ";
        cin >> t_number;
        cin.ignore();

        cout << "Enter train  Name : ";
        getline(cin, t_name);

        cout << "Enter train  source : ";
        getline(cin, t_source);

        cout << "Enter train  destination : ";
        getline(cin, t_destination);

        cout << "Enter train  time : ";
        getline(cin, t_time);

        Train t(t_number, t_name, t_source, t_destination, t_time);
        trains.push_back(t);

        cout << "Train added successfully\n";
    }

    void displayAllData() const
    {

        cout << "\n=== All Train Details ===\n"
             << endl;

        if (trains.empty())
        {
            cout << "\n no train details\n"
                 << endl;
            return;
        }

        else
        {
            for (int i = 0; i < trains.size(); i++)
            {
                trains[i].display();
            }
        }
    }

    void searchByNumber(int number) const
    {
        for (int i = 0; i < trains.size(); i++)
        {
            if (trains[i].getTrain() == number)
            {
                cout << "\n Train Found:\n";
                trains[i].display();
                return;
            }
        }
        cout << "\nTrain not found :\n";
    }
};

int main()
{

    RailwaySystem manager;

    int choice;
    do{
        cout<< "\n\n --- Railway Management System ---"<< endl;
        cout<< "1. Add Train "<< endl;
        cout<< "2. Display All Train "<< endl;
        cout<< "3. Search Train number"<< endl;
        cout<< "4. Exit"<<endl;

    
        cout<< "Enter your choice : ";
        cin >> choice;

        
        switch (choice)
        {
        case 1:
            manager.addTrain();
            break;
        

            case 2:
            manager.displayAllData();
            break;

            case 3:
            int number;
            cout << "Enter number to search :";
            cin >> number;
            manager.searchByNumber(number);
            break;

        
            case 4:
            cout << " Exiting program...\n";
            break;

            default:
            cout << " Invalid choice. Try again.\n";

    
        }

    }

    while (choice != 4);

    return 0;
}