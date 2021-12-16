#include "User.h"
#include<iostream>

using namespace std;

User::User() {}

void User::Logout() {
    cout << "Logged out successfully!\n";
}

void User::Register() {
    setId();
    setName();
    setPass();
    setMail();
    setAge();
    setGender();
    setBloodtype();
}

void User::Update() {
    setId();
    setName();
    setPass();
    setMail();
    setAge();
    setGender();
    setBloodtype();
}


void User::setGender() {
    int gchoice;
    cout << "Choose your gender: " << endl;
    cout << "1- F" << endl;
    cout << "2- M" << endl;
    cin >> gchoice;
    while (gchoice < 1 || gchoice > 2) {
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

void User::setBloodtype() {
    int btype;
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

void User::setId() {
    cout << "Enter your birth ID: " << endl;
    cin >> ID;
}


void User::setName() {
    cout << "Enter your name: " << endl;
    cin >> name;
}

void User::setPass() {
    cout << "Enter your password (At least 8 characters):" << endl;
    cin >> password;
    while (password.length() < 8) {
        cout << "Invalid!" << endl;
        cout << "Try Again" << endl;
        cin >> password;
    }
}

void User::setMail() {
    cout << "Enter your mail:" << endl;
    cin >> mail;
}

void User::setAge() {
    cout << "Enter your age: " << endl;
    cin >> age;
   
}
