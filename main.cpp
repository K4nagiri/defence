#include <iostream>
#include <fstream>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <limits>
#include "include/header.h"

using namespace std;

int main() {

    Login Login;
    AccountManager AccountManager;
    Calculator Calculator;

    if(!Login.VerifyLogin()){
        return 0;
    }

    string choice;
    // Main menu loop
    do {
        system("cls");
        // Show menu options
        cout << "1. Account Manager\n2. Calculator\n3. Change Login email and password\n4. Exit\nChoose: ";
        cin >> choice;

        // Execute user's choice
        if(choice == "1"){
            AccountManager.AccountManage();
        }
        else if(choice == "2"){
            Calculator.Calculate();
        }
        else if(choice == "3"){
            Login.ChangeLogin();
        }
        else if(choice == "4"){
            cout<<"Goodbye..."<<endl;
        }
        else{
            system("cls");
            cout<<"Invalid Option"<<endl;
            Sleep(1200);
            system("cls");
        }

    } while (choice != "4"); // Loop until user chooses to exit

    return 0;
}
