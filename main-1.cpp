
#include <iostream>
#include <string>
using namespace std;

// Store details for three customers
string names[3] = {"Thabo", "Lerato", "Sipho"};
int accountNumbers[3] = {1001, 1002, 1003};
int pins[3] = {1111, 2222, 3333};
double balances[3] = {1500.00, 2000.00, 1000.00};

int currentUser = -1;

// Function declarations
void deposit();
void withdraw();
void sendCash();
void checkBalance();
void menu();

// Deposit function
void deposit()
{
    double amount;

    cout << "\nEnter amount to deposit: R";
    cin >> amount;

    if (amount > 0)
    {
        balances[currentUser] =
        balances[currentUser] + amount;

        cout << "Deposit successful.\n";
        cout << "New balance: R"
             << balances[currentUser] << endl;
    }
    else
    {
        cout << "Invalid amount. Amount must be more than 0.\n";
    }
}

// Withdraw function
void withdraw()
{
    double amount;

    cout << "\nEnter amount to withdraw: R";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount.\n";
    }
    else if (amount > balances[currentUser])
    {
        cout << "Not enough money in your account.\n";
    }
    else
    {
        balances[currentUser] =
        balances[currentUser] - amount;

        cout << "Withdrawal successful.\n";
        cout << "New balance: R"
             << balances[currentUser] << endl;
    }
}

// Send cash function
void sendCash()
{
    int receiverAccount;
    int receiverIndex = -1;
    double amount;

    cout << "\nEnter receiver account number: ";
    cin >> receiverAccount;

    // Search for receiver account
    for (int i = 0; i < 3; i++)
    {
        if (accountNumbers[i] == receiverAccount)
        {
            receiverIndex = i;
        }
    }

    if (receiverIndex == -1)
    {
        cout << "Account number not found.\n";
    }
    else if (receiverIndex == currentUser)
    {
        cout << "You cannot send cash to your own account.\n";
    }
    else
    {
        cout << "Enter amount to send: R";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount.\n";
        }
        else if (amount > balances[currentUser])
        {
            cout << "Not enough money to complete transfer.\n";
        }
        else
        {
            balances[currentUser] =
            balances[currentUser] - amount;

            balances[receiverIndex] =
            balances[receiverIndex] + amount;

            cout << "Cash sent successfully to "
                 << names[receiverIndex] << ".\n";

            cout << "Your new balance: R"
                 << balances[currentUser] << endl;
        }
    }
}

// Check balance function
void checkBalance()
{
    cout << "\nAccount holder: "
         << names[currentUser] << endl;

    cout << "Account number: "
         << accountNumbers[currentUser] << endl;

    cout << "Current balance: R"
         << balances[currentUser] << endl;
}

// Menu function
void menu()
{
    int enteredAccount;
    int enteredPin;
    int choice;
    bool loginSuccessful = false;

    cout << "========== GCC BANK ==========\n";

    cout << "Enter your account number: ";
    cin >> enteredAccount;

    cout << "Enter your PIN: ";
    cin >> enteredPin;

    // Check customer account details
    for (int i = 0; i < 3; i++)
    {
        if (accountNumbers[i] == enteredAccount &&
            pins[i] == enteredPin)
        {
            currentUser = i;
            loginSuccessful = true;
        }
    }

    if (loginSuccessful == false)
    {
        cout << "Incorrect account number or PIN.\n";
        return;
    }

    // Repeat menu until Exit is selected
    for (;;)
    {
        cout << "\n========== GCC BANK ==========\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Send Cash\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            deposit();
        }
        else if (choice == 2)
        {
            withdraw();
        }
        else if (choice == 3)
        {
            sendCash();
        }
        else if (choice == 4)
        {
            checkBalance();
        }
        else if (choice == 5)
        {
            cout << "Thank you for using GCC Bank. Goodbye!\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Choose from 1 to 5.\n";
        }
    }
}

// Main function
int main()
{
    menu();

    return 0;
}

