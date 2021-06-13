#include "Recipient.h"
#include "Blood_Bank.h"
#include <iostream>
#include "stdio.h"
#include <queue>
using namespace std;

void Recipient::HomePage(Blood_Bank& b) {
    RequestABloodType(b);
    DisplayBloodTypes(b);
}

void Recipient::Login(vector<Recipient>& r, Blood_Bank& b) {
    string username, userpass;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> userpass;

    for (int i = 0; i < r.size(); i++) {
        if (username == r[i].name && userpass == r[i].password) {
            r[i].HomePage(b);
        }
    }
}

Recipient::Recipient() {}

void Recipient::Register(vector<Recipient>& r, Blood_Bank& b) {

    User::Register();

    cout << "Enter your age: " << endl;
    cin >> age;
    cout << "Enter your hospital: " << endl;
    cin >> hospital;
    cout << "Enter the doctor responsible for your case: " << endl;
    cin >> case_doctor;
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

}

void Recipient::DisplayBloodTypes(Blood_Bank& b) {

    int count;

    if (!b.A.empty()) {
        queue<string> flag;
        count = 1;
        cout << "Blood type A:\n";
        cout << "Quantity: " << b.A.size() << endl;

        while (!b.A.empty())
        {
            cout << "Blood bag " << count << " :";
            cout << b.A.front() << endl;
            flag.push(b.A.front());
            b.A.pop();
            count++;
        }
        b.A = flag;

    }

    if (!b.B.empty()) {
        queue<string> flag;
        count = 1;
        cout << "Blood type B:\n";
        cout << "Quantity: " << b.B.size() << endl;

        while (!b.B.empty())
        {
            cout << "Blood bag " << count << " :";
            cout << b.B.front() << endl;
            flag.push(b.B.front());
            b.B.pop();
            count++;
        }
        b.B = flag;
    }

    if (!b.O.empty()) {
        queue<string> flag;
        count = 1;
        cout << "Blood type O:\n";
        cout << "Quantity: " << b.O.size() << endl;

        while (!b.O.empty())
        {
            cout << "Blood bag " << count << " :";
            cout << b.O.front() << endl;
            flag.push(b.O.front());
            b.O.pop();
            count++;
        }
        b.O = flag;
    }

    if (!b.AB.empty()) {
        queue<string> flag;
        count = 1;
        cout << "Blood type AB:\n";
        cout << "Quantity: " << b.AB.size() << endl;

        while (!b.AB.empty())
        {
            cout << "Blood bag " << count << " :";
            cout << b.AB.front() << endl;
            flag.push(b.AB.front());
            b.AB.pop();
            count++;
        }
        b.AB = flag;
    }


}


void Recipient::RequestABloodType(Blood_Bank& b)
{

    if (searchForAvailabilityOfBloodTypes(b) == true) {
        b.requestlist.push(ID);
        cout << "your request has been submitted sucessfully" << endl;
    }
    else
    {
        b.waitinglist.push(ID);
        cout << "You are directed to the waiting list" << endl;
    }
}
