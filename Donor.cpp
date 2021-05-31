#include "Donor.h"
#include <iostream>
#include "BloodBankSystem.cpp"

using namespace std;

void Donor::Register() {

    cout << "Enter your birth ID: " << endl;
    cin >> ID;

    cout << "Enter your name: " << endl;
    cin >> name;

    cout << "Enter a password (At least 8 characters):" << endl;
    cin >> password;
    while (password.length() < 8) {
        cout << "Invalid!" << endl;
        cout << "Try Again" << endl;
        cin >> password;
    }

    cout << "Enter your age: " << endl;
    cin >> age;
    if (age < 17 || age > 60) {
        cout << "Your age is not suitable to be a donor" << endl;
        mainMenu();
    }
    
    cout << "Enter your mail:" << endl;
    cin >> mail;

    cout << "Choose your gender: " << endl;
    int gchoice;
    cout << "1- Female" << endl;
    cout << "2- Male" << endl;
    cin >> gchoice;
    while (gchoice != 1 || gchoice != 2)
    {
        cout << "Invalid Input!" << endl;
        cout << "Try Again" << endl;
        cin >> gchoice;

    }

    cout << "Choose your blood type:" << endl;
    cout << "1- A" << endl;
    cout << "2- B" << endl;
    cout << "3- AB" << endl;
    cout << "4- O" << endl;
    cin >> bloodType;
    while (bloodType != 1 || bloodType != 2 || bloodType != 3 || bloodType != 4) {
        cout << "Invalid Input!" << endl;
        cout << "Try Again" << endl;
        cin >> bloodType;
    }

  
    cout << "Do you suffer from any disease from the following:" << endl<< "Blood Pressure Disorders, Thyroid Disease, Diabetes, Cancer, Heart Disorders, Hepatitis)"<< endl;
    int dChoice;
    cout << "1- Yes" << endl << "2- No " << endl;
    cin >> dChoice;
    while (dChoice != 1 || dChoice != 2)
    {
        cout << "Invalid Input!" << endl;
        cout << "Try Again" << endl;
        cin >> dChoice;

    }

    cout << "Do you suffer from any other disease?" << endl ;
    string dAnswer, mAnswer;
    cin >> dAnswer;
    cout << "Do you take any kind of medications?" << endl;
    cin >> mAnswer;

    cout << "Do you have any past donations? " << endl;
    cout << "1- You have a past donation. Press Y" << endl;
    cout << "2- You do not have a past donation. Press N " << endl;
    bool donationStatus;
    char c;
    cin >> c;
    if (c == 'y' || c == 'Y') {

        cout << "Enter the date of your latest donation if any exists" << endl;
        string lDonationDate = displayDate();
        donationStatus = true;
       
    }
    else if (c == 'n' || c == 'N'){

        donationStatus = false;

    }
    else {

        cout << "Invalid Input";

    }

    cout << "Registration is done successfully" << endl;
    homePage();
}



void Donor::Update() {

        int nID;
        string nName, nMail, nPassword;
        int newChoice;

        cout << "Choose the attribute you want to update" << endl;
        cout << "1- Update your ID" << endl;
        cout << "2- Update your name" << endl;
        cout << "3- Update your password" << endl;
        cout << "4- Update your mail" << endl;
        cout << "5- Update your gender" << endl;
        cout << "6- Update your blood type" << endl;
        cout << "7- Update your disease infection" << endl;
        cout << "8- Update your other disease and medications" << endl;
        cout << "9- Update the latest donation' date" << endl;

        if (newChoice == 1) {
            cout << "Enter your birth ID: " << endl;
            cin >> nID;
            ID = nID;
        }

        if (newChoice == 2) {
            cout << "Enter your new name: " << endl;
            cin >> nName;
            name = nName;
        }

        if (newChoice == 3) {
            cout << "Enter a new password (At least 8 characters):" << endl;
            cin >> nPassword;
            while (nPassword.length() < 8) {
                cout << "Invalid!" << endl;
                cout << "Try Again" << endl;
                cin >> nPassword;
            }
            password = nPassword;
        }

        if (newChoice == 4) {
            cout << "Enter your new mail:" << endl;
            cin >> nMail;
        }

        if (newChoice == 5) {
            cout << "Choose your gender: " << endl;
            int gchoice;
            cout << "1- Female" << endl;
            cout << "2- Male" << endl;
            cin >> gchoice;
            while (gchoice != 1 || gchoice != 2)
            {
                cout << "Invalid Input!" << endl;
                cout << "Try Again" << endl;
                cin >> gchoice;

            }
        }

        if (newChoice == 6) {
            cout << "Choose your blood type:" << endl;
            cout << "1- A" << endl;
            cout << "2- B" << endl;
            cout << "3- AB" << endl;
            cout << "4- O" << endl;
            cin >> bloodType;
            while (bloodType != 1 || bloodType != 2 || bloodType != 3 || bloodType != 4) {
                cout << "Invalid Input!" << endl;
                cout << "Try Again" << endl;
                cin >> bloodType;
            }
        }

        if (newChoice == 7) {
            int dChoice;
            cout << "Do you suffer from any disease from the following:" << endl << "Blood Pressure Disorders, Thyroid Disease, Diabetes, Cancer, Heart Disorders, Hepatitis)" << endl;
            cout << "1- Yes" << endl << "2- No " << endl;
            cin >> dChoice;
            while (dChoice != 1 || dChoice != 2)
            {
                cout << "Invalid Input!" << endl;
                cout << "Try Again" << endl;
                cin >> dChoice;

            }
        }


        if (newChoice == 8) {
            string dAnswer, mAnswer;
            cout << "Do you suffer from any other disease?" << endl;
            cin >> dAnswer;
            cout << "Do you take any kind of medications?" << endl;
            cin >> mAnswer;
        }

        if (newChoice == 9) {
            bool donationStatus;
            char c;
            cout << "Do you have any past donations? " << endl;
            cout << "1- You have a past donation. Press Y" << endl;
            cout << "2- You do not have a past donation. Press N " << endl;
            cin >> c;
            if (c == 'y' || c == 'Y') {

                cout << "Enter the date of your latest donation if any exists" << endl;
                string lDonationDate = displayDate();
                donationStatus = true;



            }
            else if (c == 'n' || c == 'N') {

                donationStatus = false;


            }
            else {

                cout << "Invalid Input";

            }



        }

        cout << "Updates are done successfully" << endl;
        homePage();
}

bool Donor :: donationReq() {












}






