#include "Recipient.h"
#include "date.h"
#include "Date_time.h"
#include <iostream>
#include "stdio.h"
#include <queue>
#include "Blood_Bank.h"
using namespace std;

void Recipient::HomePage(Blood_Bank& b) {

    int c;
    cout << "1- Update your data" << endl << "2- Display all blood data" << endl << "3- Search for blood availability" << endl
        << "4- Blood Request" << endl << "5- Log out" << endl;
    cin >> c;

    while (c < 1 || c > 5)
    {
        cout << "Invalid Input!" << endl;
        cout << "Try Again" << endl;
        cin >> c;
    }

    if (c == 1) {
        Update();
        HomePage(b);
    }

    else if (c == 2) {
        DisplayBloodTypes(b);
    }

    else if (c == 3) {
        searchForAvailabilityOfBloodTypes(b);
        HomePage(b);
    }

    else if (c == 4) {
        RequestABloodType(b);
    }

    else if (c == 5) {
        Logout();
    }
}

void Recipient::Login(vector<Recipient>& r, Blood_Bank& b) {
    string username, userpass;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> userpass;
    bool flag = 0;

    for (int i = 0; i < r.size(); i++) {
        if (username == r[i].name && userpass == r[i].password) {
            flag = 1;
            r[i].HomePage(b);
        }
    }

    if (flag == 0) {
        cout << "Invalid username or password! " << endl;
        Login(r, b);
    }

}

Recipient::Recipient() {}

void Recipient::Register() {

    User::Register();
    setHospital();
    setDoctor();
    cout << "Registration is done successfully" << endl;
}

void availabilityStatus() {
    cout << " The required blood type and quantity are available\n";
}

bool Recipient::searchForAvailabilityOfBloodTypes(Blood_Bank& b)
{
    int quantity;
    cout << "Enter quantity: ";
    cin >> quantity;

    // badawar 3ala el A type
    if (bloodType == "A") {
        if (b.A.size() >= quantity)
        {
            availabilityStatus();
            cout << " A type is available\n";
            return true;
        }


        else if (b.B.size() >= quantity)
        {

            availabilityStatus();
            cout << " B type is available\n";
            return true;
        }
        else if (b.O.size() >= quantity)
        {
            availabilityStatus();
            cout << " o type is available\n";
            return true;
        }
        else
        {
            cout << "Your request is not available\n";
            return false;
        }
    } 
    // badawar 3ala el b
    else if (bloodType == "B") {

        if (b.B.size() >= quantity)
        {

            availabilityStatus();
            cout << " B type is available\n";
            return true;
        }
        else  if (b.O.size() >= quantity)
        {

            availabilityStatus();
            cout << " O type is available\n";
            return true;
        }
        else {
            cout << "Your request is not available\n";
            return false;
        }
    }


    // o type
    else if (bloodType == "O") {
        if (b.O.size() >= quantity)
        {


            availabilityStatus();
            cout << " O type is available\n";
            return true;
        }
        else {
            cout << "Your request is not available\n";
            return false;
        }
    }

    else if (bloodType == "AB") {
        if (b.AB.size() >= quantity)
        {
            availabilityStatus();
            cout << " AB type is available\n";
            return true;
        }
        else if (b.O.size() >= quantity)
        {


            availabilityStatus();
            cout << " O type is available\n";
            return true;
        }
        else  if (b.A.size() >= quantity)
        {

            availabilityStatus();
            cout << " A type is available\n";
            return true;
        }
        else
        {
            cout << "Your request is not available\n";
            return false;
        }
    }

    HomePage(b);

}

void Recipient::DisplayBloodTypes(Blood_Bank& b) {

    int count;

    if (!b.A.empty()) {
        queue<date> flag;
        count = 1;
        cout << "Blood type A:\n";
        cout << "Quantity: " << b.A.size() << endl;


        while (!b.A.empty())
        {
            cout << "Blood bag " << count << " :";
            cout << b.A.front().day << "/" << b.A.front().month << "/" << b.A.front().year << endl;
            flag.push(b.A.front());
            date_time.addDays(b.A.front(), 30);
            b.A.pop();
            count++;
        }
        b.A = flag;

    }

    if (!b.B.empty()) {
        queue<date> flag;
        count = 1;
        cout << "Blood type B:\n";
        cout << "Quantity: " << b.B.size() << endl;

        while (!b.B.empty())
        {
            cout << "Blood bag " << count << " :";
            cout << b.B.front().day << "/" << b.B.front().month << "/" << b.B.front().year << endl;
            flag.push(b.B.front());
            date_time.addDays(b.B.front(), 30);
            b.B.pop();
            count++;
        }
        b.B = flag;
    }

    if (!b.O.empty()) {
        queue<date> flag;
        count = 1;
        cout << "Blood type O:\n";
        cout << "Quantity: " << b.O.size() << endl;

        while (!b.O.empty())
        {
            cout << "Blood bag " << count << " :";
            cout << b.O.front().day << "/" << b.O.front().month << "/" << b.O.front().year << endl;
            flag.push(b.O.front());
            date_time.addDays(b.O.front(), 30);
            b.O.pop();
            count++;
        }
        b.O = flag;
    }

    if (!b.AB.empty()) {
        queue<date> flag;
        count = 1;
        cout << "Blood type AB:\n";
        cout << "Quantity: " << b.AB.size() << endl;

        while (!b.AB.empty())
        {
            cout << "Blood bag " << count << " :";
            cout << b.AB.front().day << "/" << b.AB.front().month << "/" << b.AB.front().year << endl;
            flag.push(b.AB.front());
            date_time.addDays(b.AB.front(), 30);
            b.AB.pop();
            count++;
        }
        b.AB = flag;
    }

    HomePage(b);
}


void Recipient::RequestABloodType(Blood_Bank& b)
{
    cout << "You will receive the blood at hospital: " << hospital << endl;
    cout << "To confirm, press 1 and to change press 2: ";

    int hchoice;
    cin >> hchoice;
    while (hchoice < 1 || hchoice > 2) {
        cout << "Invalid Input!" << endl;
        cout << "Try Again" << endl;
        cin >> hchoice;
    }

    if (hchoice == 1) {
        cout << "Hospital confirmed!\n";
    }
    else if (hchoice == 2) {
        setHospital();
        cout << "Hospital charged!\n";
    }
    if (searchForAvailabilityOfBloodTypes(b) == true) {
        b.requestlist.push(ID);
        cout << "your request has been submitted sucessfully" << endl;
    }
    else
    {
        b.waitinglist.push(ID);
        cout << "You are directed to the waiting list" << endl;
    }
    HomePage(b);
}

void Recipient::Delete(vector<Recipient>& r) {

    int takenID;

    cout << "Enter your birth ID: ";
    cin >> takenID;

    vector <Recipient> ::iterator it;

    for (it = r.begin(); it != r.end(); it++)
    {
        if (takenID == it->ID) {

            r.erase(it);
            break;

        }
    }
}

void Recipient::setHospital() {
    cout << "Enter your hospital: " << endl;
    cin >> hospital;
}

void Recipient::setDoctor() {
    cout << "Enter the doctor responsible for your case: " << endl;
    cin >> case_doctor;
}

void Recipient::Update() {
    cout << "Choose the attribute you want to update:" << endl;
    cout << "1- Update your ID" << endl;
    cout << "2- Update your name" << endl;
    cout << "3- Update your password" << endl;
    cout << "4- Update your mail" << endl;
    cout << "5- Update your age" << endl;
    cout << "6- Update your gender" << endl;
    cout << "7- Update your blood type" << endl;
    cout << "8- Update your Hospital" << endl;
    cout << "9- Update your doctor" << endl;

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
    }

    else if (updateChoice == 6) {
         setGender();
        
    }

    else if (updateChoice == 7) {
        setBloodtype();
    }

    else if (updateChoice == 8) {
        setHospital();
    }

    else if (updateChoice == 9) {
        setDoctor();
    }
    cout << "Updates are done successfully" << endl;

   

}
