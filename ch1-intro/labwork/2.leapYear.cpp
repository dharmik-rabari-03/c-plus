#include <iostream>
using namespace std;

int main() {
    int start, end;
    cout << "Enter the Start Year: ";
    cin >> start;
    cout << "Enter the Last Year: ";
    cin >> end;

    int leapYears[100]; 
    int count = 0;

    for (int year = start; year <= end; year++) {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0) ) {
            leapYears[count] = year;
            count++;
        }
    }

    cout << "\nThe Leap Years is: ";
    for (int i = 0; i < count; i++) {
        cout << leapYears[i] << " ";
    }

    return 0;
}

