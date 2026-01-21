#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int n, string name, double b)
    {
        accountNumber = n;
        accountHolderName = name;
        balance = b;
    }

    virtual void deposit(double amount)
    {
        balance = balance + amount;
        cout << "Amount Deposited Successfully.\n";
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance = balance - amount;
            cout << "Amount Withdrawn Successfully.\n";
        }
        else
        {
            cout << "Insufficient Balance!\n";
        }
    }

    virtual void calculateInterest() {}

    virtual void displayAccountInfo()
    {
        cout << "\n----- ACCOUNT DETAILS -----\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Holder Name    : " << accountHolderName << endl;
        cout << "Balance        : " << balance << endl;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount
{
    double interestRate;

public:
    SavingsAccount(int n, string name, double b, double rate)
        : BankAccount(n, name, b)
    {
        interestRate = rate;
    }

    void calculateInterest() override
    {
        double interest;
        interest = (balance * interestRate) / 100;
        balance = balance + interest;
        cout << "Savings Interest Added: " << interest << endl;
    }
};

class CheckingAccount : public BankAccount
{
    double overdraftLimit;

public:
    CheckingAccount(int n, string name, double b, double limit)
        : BankAccount(n, name, b)
    {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override
    {
        if (amount <= (balance + overdraftLimit))
        {
            balance = balance - amount;
            cout << "Amount Withdrawn.\n";
        }
        else
        {
            cout << "Overdraft Limit Exceeded!\n";
        }
    }
};

class FixedDepositAccount : public BankAccount
{
    int term;

public:
    FixedDepositAccount(int n, string name, double b, int t)
        : BankAccount(n, name, b)
    {
        term = t;
    }

    void calculateInterest() override
    {
        double rate = 6.5;
        double interest;
        interest = (balance * rate * term) / 100;
        balance = balance + interest;
        cout << "FD Interest Added: " << interest << endl;
    }
};

int main()
{
    BankAccount *acc = nullptr;
    int choice;

    do
    {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Create Fixed Deposit Account\n";
        cout << "4. Deposit\n";
        cout << "5. Withdraw\n";
        cout << "6. Calculate Interest\n";
        cout << "7. Display Account Info\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        int no, term;
        string name;
        double bal, rate, limit, amount;

        if (choice >= 1 && choice <= 3)
        {
            delete acc;
            acc = nullptr;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter Account Number: ";
            cin >> no;
            cin.ignore();

            cout << "Enter Holder Name: ";
            getline(cin, name);

            cout << "Enter Initial Balance: ";
            cin >> bal;

            cout << "Enter Interest Rate: ";
            cin >> rate;

            acc = new SavingsAccount(no, name, bal, rate);
            cout << "Savings Account Created.\n";
            break;

        case 2:
            cout << "Enter Account Number: ";
            cin >> no;
            cin.ignore();

            cout << "Enter Holder Name: ";
            getline(cin, name);

            cout << "Enter Initial Balance: ";
            cin >> bal;

            cout << "Enter Overdraft Limit: ";
            cin >> limit;

            acc = new CheckingAccount(no, name, bal, limit);
            cout << "Checking Account Created.\n";
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> no;
            cin.ignore();

            cout << "Enter Holder Name: ";
            getline(cin, name);

            cout << "Enter Initial Balance: ";
            cin >> bal;

            cout << "Enter Term (Years): ";
            cin >> term;

            acc = new FixedDepositAccount(no, name, bal, term);
            cout << "Fixed Deposit Account Created.\n";
            break;

        case 4:
            if (acc)
            {
                cout << "Enter Amount: ";
                cin >> amount;
                acc->deposit(amount);
            }
            else
                cout << "Create Account First!\n";
            break;

        case 5:
            if (acc)
            {
                cout << "Enter Amount: ";
                cin >> amount;
                acc->withdraw(amount);
            }
            else
                cout << "Create Account First!\n";
            break;

        case 6:
            if (acc)
                acc->calculateInterest();
            else
                cout << "Create Account First!\n";
            break;

        case 7:
            if (acc)
                acc->displayAccountInfo();
            else
                cout << "Create Account First!\n";
            break;

        case 0:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    delete acc;
    return 0;
}
