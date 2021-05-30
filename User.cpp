#include "User.h"
#include<iostream>

using namespace std;

User::User(){

	int ID = 0;
	string name,  mail, password = NULL;
    int bloodType = 0;

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
    cout << "1- Female" << endl;
    cout << "2- Male"<<endl;
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
    while (bloodType != 1 || bloodType != 2 || bloodType!=3 || bloodType!=4) {
        cout << "Invalid Input!"<< endl;
        cout << "Try Again"<< endl;
        cin >> bloodType;
    }

    cout << "Registration is done successfully"<< endl;
    homePage();
}

void User::Login() {
    string username; //Read from the file
    string spassword; //Read from the file
    cout << "Enter username: ";
    cin >> name;
    cout << "Enter password: ";
    cin >> password;
    if (name == username && password == spassword) {
        homePage();

    }
    else {
        cout << "Invalid username or password!";
        mainMenu();
       
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
    cout << "Updates are done successfully" << endl;
    homePage();
}

  



void User::Delete() {





}
void User::homePage() {

    int c;
    cout << "1- Update your data" << endl << "2- Delete your data" << endl;
    cin >> c;

    while(c != 1 || c != 2)
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



User::~User() {


}

