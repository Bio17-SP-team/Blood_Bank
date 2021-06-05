#include "User.h"
#include<iostream>

using namespace std;

User::User(){}

void User::Delete() {
    cout << "deleted\n";
}

void User::homePage() {

    int c;
    cout << "1- Update your data" << endl << "2- Delete your data" << endl;
    cin >> c;

    while(c < 1 || c > 2)
    {
        cout << "Invalid Input!" << endl;
        cout << "Try Again" << endl;
        cin >> c;

    }

    if (c == 1) {

       Update();

    }

    if (c == 2) {

        Delete();
    }

}

void User::Register() {

    cout << "Enter your birth ID: " << endl;
    cin >> ID;

    cout << "Enter your name: " << endl;
    cin >> name;
    cout << "Enter a password (At least 8 characters):" << endl;
    cin >> password;
    while (password.length() < 8) {
        cout << "Invalid!" << endl;
        cout << "Try Again"<< endl;
        cin >> password;
    }
    cout << "Enter your mail:" << endl;
    cin >> mail;
   
    cout << "Choose your gender: " << endl;
    int gchoice;
    cout << "1- F" << endl;
    cout << "2- M"<<endl;
    cin >> gchoice;
    while (gchoice < 1 || gchoice > 2)
    {
        cout << "Invalid Input!" << endl;
        cout << "Try Again" << endl;
        cin >> gchoice;

    }

    if(gchoice == 1){
        gender = 'F';
    }
    else if (gchoice == 2) {
        gender = 'M';
    }

    cout << "Choose your blood type:" << endl;
    cout << "1- A" << endl;
    cout << "2- B" << endl;
    cout << "3- AB" << endl;
    cout << "4- O" << endl;
    int btype;
    cin >> btype;
    while (btype < 1 || btype > 4) {
        cout << "Invalid Input!"<< endl;
        cout << "Try Again"<< endl;
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

    cout << "Registration is done successfully"<< endl;
    homePage();
}

void User::Login() {
    string username ; //Read from the file
    string spassword ; //Read from the file
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> spassword;
    if (username == name && spassword == password) {
        homePage();

    }
    else {
        cout << "Invalid username or password!";
        //mainMenu();
       
    }

}

void User::Update() {

    int nID;
    string nName, nMail, nPassword;
    int newChoice;

    cout << "Choose the attribute you want to update"<< endl;
    cout << "1- Update your ID" << endl;
    cout << "2- Update your name" << endl;
    cout << "3- Update your password" << endl;
    cout << "4- Update your mail" << endl;
    cout << "5- Update your gender" << endl;
    cout << "6- Update your blood type" << endl;

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
        mail = nMail;
    }

    if (newChoice == 5) {
        cout << "Choose your gender: " << endl;
    int gchoice;
    cout << "1- F" << endl;
    cout << "2- M"<<endl;
    cin >> gchoice;
    while (gchoice < 1 || gchoice > 2)
    {
        cout << "Invalid Input!" << endl;
        cout << "Try Again" << endl;
        cin >> gchoice;

    }

    if(gchoice == 1){
        gender = 'F';
    }
    else if (gchoice == 2) {
        gender = 'M';
    }
    }

    if (newChoice == 6) {
    cout << "Choose your blood type:" << endl;
    cout << "1- A" << endl;
    cout << "2- B" << endl;
    cout << "3- AB" << endl;
    cout << "4- O" << endl;
    int btype;
    cin >> btype;
    while (btype < 1 || btype > 4) {
        cout << "Invalid Input!"<< endl;
        cout << "Try Again"<< endl;
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
    cout << "Updates are done successfully" << endl;
    homePage();
}
