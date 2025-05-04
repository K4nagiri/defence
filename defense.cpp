#include <iostream>
#include <fstream>
#include <windows.h>
#include <limits>
#include "include/header.h"

using namespace std;

// Filenames for storing master password and credentials
const string MasterFile = "master.txt";
const string AccountFile = "account.txt";

// Function to verify the master password
bool AccountManager::VerifyMasterPassword() {
    ifstream fin(MasterFile);
    string savedPassword;

    system ("cls");
    // If the master file doesn't exist, create one with default password
    if (!fin) {
        ofstream fout(MasterFile);
        savedPassword = "password123";
        fout << "password123"; // Default password
        fout.close();
        cout<<"Defaul password: "<< savedPassword <<endl;
    } else {
        getline(fin, savedPassword); // Read the saved master password
        fin.close();
    }



    // Prompt user for the master password
    string input;
    cout << "Enter master password: ";
    cin >> input;

    // Check and respond accordingly
    if (input == savedPassword) {
        return true;
    } else {
        cout << "Access Denied." << endl;
        Sleep(1200);
        return false;
    }
}

// Function to change the master password
void AccountManager::ChangeMasterPassword() {

    string option;
    while (true) {
        system("cls");
        cout << "1. Enter new master password\n2. Go Back\nChoose: ";
        cin>>option;

        if (option == "2") {
            system("cls");
            return; // User wants to go back
        } else if (option == "1") {


            if (!VerifyMasterPassword()) {
                system("cls");
                return;
            }
            cin.ignore();

            string newPass;
            cout << "Enter new master password: ";
            getline(cin, newPass);

            ofstream fout(MasterFile);
            fout << newPass;
            fout.close();

            system("cls");
            cout << "Master password changed successfully.\n";
            Sleep(1200);
            system("cls");
            return;
        } else {
            cout << "Invalid option.\n";
            Sleep(1200);
        }
    }
}

// Function to add a new email-password credential
void AccountManager::AddAccount() {
    string email, password;
    string option;

    while (true) {
        system("cls");
        cout << "1. Add an Account\n2. Go Back\nChoose: ";
        cin>>option;

        if (option == "2") {
            system("cls");
            return; // User wants to go back
            }
        else if (option == "1") {
             cin.ignore();// Clear leftover newline from previous input

            cout << "\nEnter email: ";
            getline(cin, email);

            cout << "Enter password: ";
            getline(cin, password);

            ofstream fout(AccountFile, ios::app);
            fout << email << "," << password << endl;
            fout.close();

            cout << "Account added." << endl;
            Sleep(1200);
            system("cls");
        }
    }
}

// Function to display all stored Accounts
void AccountManager::ViewAccount() {
    string choice;

    while (true) {
        system("cls");

        // First, display all accounts with line numbers
        ifstream fin(AccountFile);
        string email, password;
        int lineNumber = 1;

        cout << "Stored Accounts:"<<endl;
        // Store line offsets for reference (not kept in memory, just display)
        while (fin >> email >> password) {
            cout << lineNumber << ". Email: " << email << " | Password: " << password << endl;
            lineNumber++;
        }
        fin.close();

        cout << "\nOptions:\n1. Delete an account\n2. Back\nChoose: ";
        cin >> choice;

        if (choice == "1") {
            int deleteLine;
            cout << "\nEnter the entry number to delete: ";
            cin >> deleteLine;

            if (cin.fail()) {
                cin.clear(); // reset error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                cout << "Invalid input. Please enter a number.\n";
                Sleep(1200);
                continue; // restart the loop
            }


            ifstream fin2(AccountFile);
            ofstream temp("temp.txt");

            int currentLine = 1;
            bool deleted = false;
            while (fin2 >> email >> password) {
                if (currentLine != deleteLine) {
                    temp << email << " " << password << endl;
                } else {
                    deleted = true;
                }
                currentLine++;
            }

            fin2.close();
            temp.close();

            if (deleted) {
                remove(AccountFile.c_str());
                rename("temp.txt", AccountFile.c_str());
                cout << "Entry deleted successfully."<<endl;
            } else {
                remove("temp.txt");
                cout << "Invalid entry number."<<endl;
            }

            Sleep(1200);
        } else if (choice == "2") {
            system("cls");
            break;
        } else {
            cout << "Invalid option."<<endl;
            Sleep(1200);
        }
    }
}


void AccountManager::AccountManage(){
    // Check if master password is correct
    if (!VerifyMasterPassword()) {
        return ; // Exit if authentication fails
    }
    system("cls");

    string choice;
    // Main menu loop
    do {
        // Show menu options
        cout << "1. Add Accounts\n2. View Accounts\n3. Change Master Password\n4. Exit\nChoose: ";
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
        }
        else{
            system("cls");
            cout<<"Invalid Option"<<endl;
            Sleep(1200);
            system("cls");
        }

    } while (choice != "4"); // Loop until user chooses to exit
}

double Calculator::Addition(double a, double b){
    return a+b;
}

double Calculator::Subtraction(double a, double b){
    return a-b;
}

double Calculator::Multiplication(double a, double b){
    return a*b;
}

double Calculator::Division(double a, double b){
    return a/b;
}

void Calculator::Calculate(){

    double num1, num2, result;
    char operation;
    char again;

    while(true){
        system("cls");
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter operator (+, -, *, /): ";
        cin >> operation;

        cout << "Enter second number: ";
        cin >> num2;

        // Using if-else statements for operation choice
        if (operation == '+') {
            cout<<"Result: " << Addition(num1, num2) <<endl;
        }
        else if (operation == '-') {
            cout<<"Result: " << Subtraction(num1, num2) <<endl;
        }
        else if (operation == '*') {
            cout<<"Result: " << Multiplication(num1, num2) <<endl;
        }
        else if (operation == '/') {
            cout<<"Result: " << Division(num1, num2) <<endl;
        }
        else {
            cout << "Error: Invalid operator!" << endl;
        }

        // Ask user whether to continue
        while (true) {
            cout << "\nDo you want to perform another calculation? (y/n): ";
            cin >> again;

            if (again == 'y' || again == 'Y') {
                break; // Breaks inner loop and continues outer loop
            }
            else if (again == 'n' || again == 'N') {
                cout << "Thank you for using the calculator!" << endl;
                return; // Exits the function
            }
            else {
                cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            }
        }
    }
}

