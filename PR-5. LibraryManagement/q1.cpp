
#include <iostream>
#include <string>
using namespace std;

#define MAX_ITEMS 10

class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a)
    {
        title = t;
        author = a;
        dueDate = "Not Issued";
    }

    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getDueDate() { return dueDate; }

    void setDueDate(string d) { dueDate = d; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem
{
    int pages;

public:
    Book(string t, string a, int p) : LibraryItem(t, a)
    {
        pages = p;
    }

    void checkOut() override
    {
        setDueDate("15 Days");
        cout << "Book issued successfully.\n";
    }

    void returnItem() override
    {
        setDueDate("Not Issued");
        cout << "Book returned successfully.\n";
    }

    void displayDetails() override
    {
        cout << "\n--- Book Details ---\n";
        cout << "Title  : " << getTitle() << endl;
        cout << "Author : " << getAuthor() << endl;
        cout << "Pages  : " << pages << endl;
        cout << "Status : " << getDueDate() << endl;
    }
};

class DVD : public LibraryItem
{
    int duration;

public:
    DVD(string t, string a, int d) : LibraryItem(t, a)
    {
        duration = d;
    }

    void checkOut() override
    {
        setDueDate("7 Days");
        cout << "DVD issued successfully.\n";
    }

    void returnItem() override
    {
        setDueDate("Not Issued");
        cout << "DVD returned successfully.\n";
    }

    void displayDetails() override
    {
        cout << "\n--- DVD Details ---\n";
        cout << "Title    : " << getTitle() << endl;
        cout << "Author   : " << getAuthor() << endl;
        cout << "Duration : " << duration << " minutes\n";
        cout << "Status   : " << getDueDate() << endl;
    }
};

class Magazine : public LibraryItem
{
    int issueNumber;

public:
    Magazine(string t, string a, int i) : LibraryItem(t, a)
    {
        issueNumber = i;
    }

    void checkOut() override
    {
        setDueDate("5 Days");
        cout << "Magazine issued successfully.\n";
    }

    void returnItem() override
    {
        setDueDate("Not Issued");
        cout << "Magazine returned successfully.\n";
    }

    void displayDetails() override
    {
        cout << "\n--- Magazine Details ---\n";
        cout << "Title     : " << getTitle() << endl;
        cout << "Publisher : " << getAuthor() << endl;
        cout << "Issue No. : " << issueNumber << endl;
        cout << "Status   : " << getDueDate() << endl;
    }
};

int main()
{
    LibraryItem* items[MAX_ITEMS];
    int count = 0;
    int choice;

    do
    {
        cout << "\n===== LIBRARY MENU =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Issue Item\n";
        cout << "6. Return Item\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            string title, author;
            int pages;

            cout << "\n[Add Book]\n";
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Author Name: ";
            getline(cin, author);
            cout << "Enter Number of Pages: ";
            cin >> pages;

            items[count++] = new Book(title, author, pages);
            cout << "Book added successfully.\n";
        }
        else if (choice == 2)
        {
            string title, author;
            int duration;

            cout << "\n[Add DVD]\n";
            cout << "Enter DVD Title: ";
            getline(cin, title);
            cout << "Enter Director Name: ";
            getline(cin, author);
            cout << "Enter Duration (minutes): ";
            cin >> duration;

            items[count++] = new DVD(title, author, duration);
            cout << "DVD added successfully.\n";
        }
        else if (choice == 3)
        {
            string title, author;
            int issue;

            cout << "\n[Add Magazine]\n";
            cout << "Enter Magazine Title: ";
            getline(cin, title);
            cout << "Enter Publisher Name: ";
            getline(cin, author);
            cout << "Enter Issue Number: ";
            cin >> issue;

            items[count++] = new Magazine(title, author, issue);
            cout << "Magazine added successfully.\n";
        }
        else if (choice == 4)
        {
            cout << "\n[Library Items]\n";
            for (int i = 0; i < count; i++)
            {
                cout << "\nItem Number: " << i << endl;
                items[i]->displayDetails();
            }
        }
        else if (choice == 5)
        {
            int index;
            cout << "Enter Item Number to Issue: ";
            cin >> index;
            items[index]->checkOut();
        }
        else if (choice == 6)
        {
            int index;
            cout << "Enter Item Number to Return: ";
            cin >> index;
            items[index]->returnItem();
        }

    } while (choice != 0);

    for (int i = 0; i < count; i++)
        delete items[i];

    cout << "\nThank you for using Library Management System.\n";
    return 0;
}
