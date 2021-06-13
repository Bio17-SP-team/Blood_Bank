#include "donor.h"
#include "read_write_files.cpp"
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

Donor::Donor() {
}

void Donor::Register() {

    User::Register();

    cout << "Enter your age: " << endl;
    cin >> age;
    if (age < 17 || age > 60) {
        cout << "Your age is not suitable to be a donor" << endl;
        //mainMenu();
    }

    cout << "Do you suffer from any disease from the following:" << endl << "Blood Pressure Disorders, Thyroid Disease, Diabetes, Cancer, Heart Disorders, Hepatitis)" << endl;
    cout << "1- Yes" << endl << "2- No " << endl;
    cin >> choice;
    while (choice != 1 || choice != 2)
    {
        cout << "Invalid Input!" << endl;
        cout << "Try Again" << endl;
        cin >> choice;

    }
    if (choice == 1) {
        sufferDisease = 1;
    }
    else {
        sufferDisease = 0;
    }


    cout << "Do you suffer from any other disease or take any kind of medications?" << endl;
    cout << "1- Yes" << endl << "2- No " << endl;
    cin >> choice;
    while (choice != 1 || choice != 2)
    {
        cout << "Invalid Input!" << endl;
        cout << "Try Again" << endl;
        cin >> choice;

    }
    if (choice == 1) {
        sufferDisease = 1;
    }
    else {
        sufferDisease = 0;
    }
   
    if (sufferDisease == 1) {
        cout << "Enter the disease" << endl;
        cin >> dAnswer;
        cout << "Enter the medication" << endl;
        cin >> mAnswer;
    }

    cout << "Do you have any past donations? " << endl;
    cout << "You have a past donation. Press Y" << endl;
    cout << "You do not have a past donation. Press N " << endl;
    cin >> c;
    if (c == 'y' || c == 'Y') {
        cout << "How many months since you had your latest donation if any exists" << endl;
        cin >> lDonationMonth;
        if (lDonationMonth < 0) {
            cout << "Invalid Entry" << endl;
            cin >> lDonationMonth;
        }
        donationStatus = true;
    }
    else if (c == 'n' || c == 'N') {

        donationStatus = false;

    }
    else {

        cout << "Invalid Input";

    }

    cout << "Registration is done successfully" << endl;
    //homePage();
}


void Donor::Login(/*string& username, string& tpassword, vector <Donor> donors*/) {

   
    read_write_files dw;
    vector <Donor> donors;
    dw.read_donor(donors, "donors.txt");
    vector <Donor> ::iterator it;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> tpassword;
    
   

    for (it = donors.begin(); it != donors.end(); it++)
    {
        if (username == it->name && tpassword == it->password) {

            cout << "You logged in successfully!";
            //homePage();

        }
        else {
            cout << "Invalid username or password!";
            //mainMenu();

        }

        

    }


    

    
}


