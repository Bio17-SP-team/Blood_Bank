#include "donor.h"
#include "read_write_files.cpp"
#include <fstream>
#include <vector>
#include <iostream>
#include "bloodBank_System.cpp"

using namespace std;

Donor::Donor() {
}

void Donor::homePage() {

    int c;
    cout << "1- Update your data" << endl << "2- Donation Request" << endl;
    cin >> c;

    while (c < 1 || c > 2)
    {
        cout << "Invalid Input!" << endl;
        cout << "Try Again" << endl;
        cin >> c;

    }

    if (c == 1) {

        Donor::Update();

    }

    else if (c == 2) {

        donationReq();
    }

   

}

void Donor::Register() {

    User::Register();

    cout << "Enter your age: " << endl;
    cin >> age;
    if (age < 17 || age > 60) {
        cout << "Your age is not suitable to be a donor" << endl;
        ageVer = 0;
    }
    else {
        ageVer = 1;
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
    homePage();
}

void Donor::Login(vector<Donor>& d) {


    string username;
    string takenPassword;
   
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> takenPassword;

    for (int i = 0; i < d.size(); i++) {
        if (username == d[i].name && takenPassword == d[i].password) {
            d[i].homePage();
        }
    }

}


void Donor::Update() {

    cout << "Choose the attribute you want to update" << endl;
    cout << "1- Update your ID" << endl;
    cout << "2- Update your name" << endl;
    cout << "3- Update your password" << endl;
    cout << "4- Update your mail" << endl;
    cout << "5- Update your gender" << endl;
    cout << "6- Update your age" << endl;
    cout << "7- Update your blood type" << endl;
    cout << "8- Update your disease infection" << endl;
    cout << "9- Update your other disease and medications" << endl;
    cout << "10- Update the latest donation' date" << endl;




    if (updateChoice == 1) {

        cout << "Enter your birth ID: " << endl;
        cin >> ID;

    }

    else if (updateChoice == 2) {

        cout << "Enter your new name: " << endl;
        cin >> name;

    }

    else if (updateChoice == 3) {

        cout << "Enter a new password (At least 8 characters):" << endl;
        cin >> password;
        while (password.length() < 8) {
            cout << "Invalid!" << endl;
            cout << "Try Again" << endl;
            cin >> password;
        }


    }

    else if (updateChoice == 4) {

        cout << "Enter your mail:" << endl;
        cin >> mail;

    }


    else if (updateChoice == 5) {

        cout << "Choose your gender: " << endl;
        cout << "1- F" << endl;
        cout << "2- M" << endl;
        cin >> gchoice;
        while (gchoice < 1 || gchoice > 2)
        {
            cout << "Invalid Input!" << endl;
            cout << "Try Again" << endl;
            cin >> gchoice;

        }

        if (gchoice == 1) {
            gender = 'F';
        }
        else if (gchoice == 2) {
            gender = 'M';
        }


    }

    else if (updateChoice == 6) {

        cout << "Enter your new age: " << endl;
        cin >> age;
        if (age < 17 || age > 60) {
            cout << "Your age is not suitable to be a donor" << endl;
            ageVer = 0;
        }
        else {
            ageVer = 1;
        }

    }


    else if (updateChoice == 7) {

        cout << "Choose your blood type:" << endl;
        cout << "1- A" << endl;
        cout << "2- B" << endl;
        cout << "3- AB" << endl;
        cout << "4- O" << endl;

        cin >> btype;
        while (btype < 1 || btype > 4) {
            cout << "Invalid Input!" << endl;
            cout << "Try Again" << endl;
            cin >> btype;
        }
        if (btype == 1) {
            bloodType = "A";
        }
        else if (btype == 2) {
            bloodType = "B";
        }
        else if (btype == 3) {
            bloodType = "AB";
        }
        else if (btype == 4) {
            bloodType = "O";
        }

    }

    else if (updateChoice == 8) {


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



    }

    else if (updateChoice == 9) {


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

    }


    else if (updateChoice == 10) {


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




    }

    cout << "Updates are done successfully" << endl;
    homePage();


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
            break;

        }
    }

   



}

bool Donor::donationReq() {

    if (sufferDisease == 1 || ageVer == 0 || (lDonationMonth = 0 && lDonationMonth <= 3) ) {
        cout << "Your request is rejected" << endl;
        return 0;
    }

    else {
        cout << "Your request is accepted" << endl;
        return 1;
    }

    homePage();

}

    

    











