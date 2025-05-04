#include <iostream>
#include <fstream>
#include <windows.h>
#include <limits>
#include "include/header.h"

using namespace std;

int main() {

    AccountManager AccountManager;
    Calculator Calculator;

    string choice;
    // Main menu loop
    do {
        system("cls");
        // Show menu options
        cout << "1. Account Manager\n2. Calculator\n3. Exit\nChoose: ";
        cin >> choice;

        // Execute user's choice
        if(choice == "1"){
            AccountManager.AccountManage();
        }
        else if(choice == "2"){
            Calculator.Calculate();
        }
        else if(choice == "3"){
            cout<<"Goodbye..."<<endl;
        }
        else{
            system("cls");
            cout<<"Invalid Option"<<endl;
            Sleep(1200);
            system("cls");
        }

    } while (choice != "3"); // Loop until user chooses to exit

    return 0;
}
