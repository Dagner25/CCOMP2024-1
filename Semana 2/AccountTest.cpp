#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

int main() {
    Account myAccount1{"Juan Perez"};
    cout << "Initial account name is: " << myAccount1.getName();

    cout << "\nPlease enter the account name: ";
    string theName;
    getline(cin, theName);
    myAccount1.setName(theName);

    cout << "Name in object myAccount1 is: " <<
            myAccount1.getName() << endl;

    Account account2{"fabio coila"};
    cout << "El primer nombre de la cuenta es: " << account2.getName();

    cout << "\nIngresa un nombre por favor: ";
    string nombre;
    getline(cin, nombre);
    account2.setName(nombre);

    cout << "El nombre de account2 es: " <<
            account2.getName() << endl;
    
    return 0;
}