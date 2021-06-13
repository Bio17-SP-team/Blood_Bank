#include "Donor.h"
#include <iostream>
#include <ctime>
using namespace std;



Donor::Donor() {
}

void Donor::HomePage() {
    cout << "test";
}

void Donor::Login(vector<Donor>& d) {
    string username, userpass;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> userpass;

    for (int i = 0; i < d.size(); i++) {
        if (username == d[i].name && userpass == d[i].password) {
            d[i].HomePage();
        }
    }
}

void Donor::Register(vector<Donor>& d) {

    User::Register();

    cout << "Enter your age: " << endl;
    cin >> age;
    cout << "Do you suffer from any disease from the following:" << endl << "Blood Pressure Disorders, Thyroid Disease, Diabetes, Cancer, Heart Disorders, Hepatitis)" << endl;
    int dChoice;
    cout << "1- Yes" << endl << "2- No " << endl;
    cin >> dChoice;
    while (dChoice < 1 || dChoice > 2)
    {
        cout << "Invalid Input!" << endl;
        cout << "Try Again" << endl;
        cin >> dChoice;
    }

    if (dChoice == 1) {
        illnesses = true;
    }

    else if (dChoice == 2) {
        illnesses = false;
    }

    cout << "Do you suffer from any other disease or Do you take any kind of medications?" << endl;
    cin >> others;

    cout << "Do you have any past donations? " << endl;
    cout << "1- You have a past donation. Press Y" << endl;
    cout << "2- You do not have a past donation. Press N " << endl;
    bool donationStatus;
    char c;
    cin >> c;
    if (c == 'y' || c == 'Y') {

        cout << "Enter the date of your latest donation if any exists" << endl;

        cin >> date;
        donationStatus = true;

    }
    else if (c == 'n' || c == 'N') {

        donationStatus = false;

    }
    else {

        cout << "Invalid Input";

    }


    cout << "Registration is done successfully" << endl;
}
