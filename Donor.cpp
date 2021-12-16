#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Donor.h"
using namespace std;

Donor::Donor() {
    date.day = 1;
    date.month = 1;
    date.year = 2021;
    others = "not found";
}

void Donor::HomePage(Blood_Bank& b) {
    int c;
    cout << "1- Update your data" << endl << "2- Donation Request" << endl << "3- Log out" << endl;
    cin >> c;

    while (c < 1 || c > 3)
    {
        cout << "Invalid Input!" << endl;
        cout << "Try Again" << endl;
        cin >> c;
    }

    if (c == 1) {
        Update(b);
    }

    else if (c == 2) {
        DonationReq(b);
    }

    else if (c == 3) {
        Logout();
    }
}

void Donor::Login(vector<Donor>& d, Blood_Bank& b) {
    string username, userpass;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> userpass;
    bool flag = 0;

    for (int i = 0; i < d.size(); i++) {
        if (username == d[i].name && userpass == d[i].password) {
            flag = 1;
            d[i].HomePage(b);

        }
    }
    if (flag == 0) {
        cout << "Invalid username or password! " << endl;
        Login(d, b);
    }
}

void Donor::Register() {

    User::Register();
    setIllness();
    setOthers();
    setDonationdate();
    cout << "Registration is done successfully" << endl;
}


void Donor::DonationReq(Blood_Bank& b) {
    cout << "Enter how many months have passed since your last donation: ";
    int lDonationMonth;
    cin >> lDonationMonth;

    while (lDonationMonth < 0) {
        cout << "Invalid Input!" << endl;
        cout << "Try Again" << endl;
        cin >> lDonationMonth;
    }

    if (age < 17 || age > 60) {
        cout << "Your age is not suitable to be a donor" << endl;
        cout << "Your request is rejected" << endl;

    }
    else {
        if (illnesses == 1 || lDonationMonth <= 3) {
            cout << "Your request is rejected" << endl;
        }

        else {
            cout << "Your request is accepted" << endl;

            time_t now = time(0);
            tm* ltm = localtime(&now);
            date.year = 1900 + ltm->tm_year;
            date.month = 1 + ltm->tm_mon;
            date.day = ltm->tm_mday;
            b.donationlist.push(ID);
        }
    }
    HomePage(b);

}


void Donor::Update(Blood_Bank& b) {

    cout << "Choose the attribute you want to update" << endl;
    cout << "1- Update your ID" << endl;
    cout << "2- Update your name" << endl;
    cout << "3- Update your password" << endl;
    cout << "4- Update your mail" << endl;
    cout << "5- Update your age" << endl;
    cout << "6- Update your gender" << endl;
    cout << "7- Update your blood type" << endl;
    cout << "8- Update your disease infection" << endl;
    cout << "9- Update your other disease and medications" << endl;
    cout << "10- Update the latest donation' date" << endl;


    int updateChoice;
    cin >> updateChoice;

    if (updateChoice == 1) {
        setId();
    }

    else if (updateChoice == 2) {
        setName();
    }

    else if (updateChoice == 3) {
        setPass();
    }

    else if (updateChoice == 4) {
        setMail();
    }

    else if (updateChoice == 5) {
        setAge();
        if (age < 17 || age > 60) {
            cout << "Your age is not suitable to be a donor" << endl;
        }

    }

    else if (updateChoice == 6) {
        setGender();

    }

    else if (updateChoice == 7) {
        setBloodtype();
    }

    else if (updateChoice == 8) {
        setIllness();
    }

    else if (updateChoice == 9) {
        setOthers();
    }


    else if (updateChoice == 10) {
        setDonationdate();
    }
    cout << "Updates are done successfully" << endl;
    cout << "Do you want to update anything else? If yes press y and if not press any other key: ";
    string cont;
    cin >> cont;
    if (cont == "y" || cont == "y") {
        Update(b);
    }
    HomePage(b);
}


void Donor::Delete(vector<Donor>& d) {

    int takenID;

    cout << "Enter your birth ID: ";
    cin >> takenID;

    vector <Donor> ::iterator it;

    for (it = d.begin(); it != d.end(); it++)
    {
        if (takenID == it->ID) {

            d.erase(it);
            cout << "Account deleted successfully\n" << endl;
            break;

        }
    }
}


void Donor::setIllness() {
    cout << "Do you suffer from any disease from the following:" << endl << "Blood Pressure Disorders, Thyroid Disease, Diabetes, Cancer, Heart Disorders, Hepatitis)" << endl;
    int dChoice;
    cout << "1- Yes" << endl << "2- No " << endl;
    cin >> dChoice;
    while (dChoice < 1 || dChoice > 2) {
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
}

void Donor::setOthers() {
    int choice;
    cout << "Do you suffer from any other disease or take any kind of medications?" << endl;
    cout << "1- Yes" << endl << "2- No " << endl;
    cin >> choice;
    while (choice < 1 || choice > 2) {
        cout << "Invalid Input!" << endl;
        cout << "Try Again" << endl;
        cin >> choice;
    }
    if (choice == 1) {
        cout << "Enter the disease/ medicine: " << endl;
        cin >> others;
    }
}

void Donor::setDonationdate()
{
    cout << "Do you have any past donations? " << endl;
    cout << "1- You have a past donation. Press Y" << endl;
    cout << "2- You do not have a past donation. Press N " << endl;
    string c;
    cin >> c;
    if (c == "y" || c == "Y") {
        cout << "Enter the date of your latest donation if any exists" << endl;
        cout << "Day: " << endl;
        cin >> date.day;
        cout << "Month: " << endl;
        cin >> date.month;
        cout << "Year: " << endl;
        cin >> date.year;
    }
    else if (c == "n" || c == "N") {
    }
    else {
        cout << "Invalid Input" << endl;
        setDonationdate();
    }
}

