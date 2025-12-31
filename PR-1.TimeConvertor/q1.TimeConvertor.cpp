#include <iostream>
using namespace std;

class TimeConverter
{
private:
    int hours;
    int minutes;
    int seconds;

public:

    void secondsToHours(int seconds)
    {
        hours = seconds / 3600;
        minutes = (seconds % 3600) / 60;
        seconds = seconds % 60;

        cout << "HH:MM:SS => " << hours << ":" << minutes << ":" << seconds << endl;
    }

    void hoursToSeconds(int hours, int minutes, int seconds)
    {
        int totalSeconds = (hours * 3600) + (minutes * 60) + seconds;
        cout << "Total Seconds => " << totalSeconds << endl;
    }
};

int main()
{
    TimeConverter timeconvert;
    int choice;

    cout << "1. Seconds to HH:MM:SS" << endl;
    cout << "2. HH:MM:SS to Seconds" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int totalSeconds;
        cout << "Enter total seconds: ";
        cin >> totalSeconds;

        timeconvert.secondsToHours(totalSeconds);
    }

    else if (choice == 2)
    {
        int hh, mm, ss;
        cout << "Enter hours: ";
        cin >> hh;
        cout << "Enter minutes: ";
        cin >> mm;
        cout << "Enter seconds: ";
        cin >> ss;

        timeconvert.hoursToSeconds(hh, mm, ss);
    }

    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}