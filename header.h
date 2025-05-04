#ifndef HEADER_H
#define HEADER_H

class AccountManager{
public:

    bool VerifyMasterPassword();
    void ChangeMasterPassword();
    void AddAccount();
    void ViewAccount();
    void AccountManage();

};

class Calculator{
public:

    double Addition(double a, double b);
    double Subtraction(double a, double b);
    double Multiplication(double a, double b);
    double Division(double a, double b);
    void Calculate();
};





#endif // HEADER_H
