#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

int main() {
    Account myAccount1{"Juan Perez", 50};
    cout << "Initial account1 name is: " << myAccount1.getName();
    cout << "\nInitial account1 balance is: " << myAccount1.getBalance();

    cout << "\n\nPlease enter the account name: ";
    string theName;
    getline(cin, theName);
    myAccount1.setName(theName);
    cout << "Please enter the deposit amount: ";
    int depositAmount;
    cin >> depositAmount;
    myAccount1.deposit(depositAmount);

    cout << "\n\nInitial account1 name is: " << myAccount1.getName();
    cout << "\nInitial account1 balance is: " << myAccount1.getBalance();

    cout << "\nPlease enter a withdraw amount: ";
    int withdrawAmount;
    cin >> withdrawAmount;
    myAccount1.withdraw(withdrawAmount);
    cout << "\n\nInitial account1 name is: " << myAccount1.getName();
    cout << "\nInitial account1 balance is: " << myAccount1.getBalance();


    Account myAccount2{"Jose Perez", -10};
    cout << "\n\nInitial account2 name is: " << myAccount2.getName();
    cout << "\nInitial account2 balance is: " << myAccount2.getBalance();

    cout << "\nIngresa un nombre por favor: ";
    string nombre;
    cin.ignore();
    getline(cin, nombre);
    myAccount2.setName(nombre);
    cout << "Please enter the deposit amount: ";
    cin >> depositAmount;
    myAccount2.deposit(depositAmount);

    cout << "\n\nAccount2 name is: " << myAccount2.getName();
    cout << "\nAccount2 balance is: " << myAccount2.getBalance();
    
    cout << "\nPlease enter a withdraw amount: ";
    cin >> withdrawAmount;
    myAccount2.withdraw(withdrawAmount);
    cout << "\n\nAccount1 name is: " << myAccount2.getName();
    cout << "\nAccount1 balance is: " << myAccount2.getBalance();

    return 0;
}