#include <iostream>
#include <fstream>
#include <windows.h>
#include "include/header.h"


using namespace std;

// Filenames for storing master password and credentials
const string MasterFile = "master.txt";
const string AccountFile = "account.txt";

// Function to verify the master password
bool AccountManager::VerifyMasterPassword() {
    ifstream fin(MasterFile);
    string savedPassword;

    // If the master file doesn't exist, create one with default password
    if (!fin) {
        ofstream fout(MasterFile);
        fout << "password123"; // Default password
        fout.close();
        savedPassword = "password123";
        cout<<"Default Password: password123"<<endl;
    } else {
        getline(fin, savedPassword); // Read the saved master password
        fin.close();
    }

    system("cls");
    // Prompt user for the master password
    string input;
    cout << "Enter master password: ";
    cin >> input;

    // Return true if input matches saved password
    return input == savedPassword;
}

// Function to change the master password
void AccountManager::ChangeMasterPassword() {

    if (!VerifyMasterPassword()) {
        cout << "Access Denied.\n";
        Sleep(1200);
        system("cls");
        return ; // Exit if authentication fails
    }

    string newPass;
    cout << "Enter new master password: ";
    cin >> newPass;

    ofstream fout(MasterFile); // Overwrite the master password file
    fout << newPass;
    fout.close();

    system("cls");

    cout << "Master password changed successfully.\n";

    Sleep(1200);
    system("cls");
}

// Function to add a new email-password credential
void AccountManager::AddAccount() {
    string GoBack;

    system("cls");

    cin.ignore();
    string email, password;
    cout << "Enter email: ";
    getline(cin, email);
    cout << "Enter password: ";
    getline(cin, password);

    ofstream fout(AccountFile, ios::app); // Append mode to add new data
    fout << email << " " << password << endl;
    fout.close();

    cout << "Account added."<<endl;
}

// Function to display all stored Accounts
void AccountManager::ViewAccount() {
    string GoBack;

    system("cls");

    while (true) {
    ifstream fin(AccountFile);
    string email, password;

    cout << "Stored Accounts:"<<endl;
    // Read and print each email-password pair
    while (fin >> email >> password) {
        cout << "Email: " << email << " | Password: " << password << endl;
    }

    fin.close();

    cout << "1. Back" << endl;
    cin >> GoBack;
    if (GoBack == "1") {
        system("cls");
        break;
    } else {
        cout << "Invalid Option" << endl;
        Sleep(1200);
        system("cls");
    }
}
}

void AccountManager::AccountManage(){

    // Check if master password is correct
    if (!VerifyMasterPassword()) {
        cout << "Access Denied."<<endl;
        return ; // Exit if authentication fails
    }
    system("cls");

    string choice;
    // Main menu loop
    do {
        // Show menu options
        cout << "1. Add Credential\n2. View Credentials\n3. Change Master Password\n4. Exit\nChoose: ";
        cin >> choice;

        // Execute user's choice
        if(choice == "1"){
            AddAccount();
        }
        else if(choice == "2"){
            ViewAccount();
        }
        else if(choice == "3"){
            ChangeMasterPassword();
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



}
