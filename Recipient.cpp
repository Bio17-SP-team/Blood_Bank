#include "recipient.h"
#include "blood_bank.h"
#include <iostream>
#include "stdio.h"
using namespace std;

Recipient::Recipient() {}

void Recipient::Register() {

    User::Register();

    cout << "Enter your age: " << endl;
    cin >> age;
    cout << "Enter your hospital: " << endl;
    cin >> hospital;
    cout << "Enter the doctor responsible for your case: " << endl;
    cin >> case_doctor;
    cout << "Registration is done successfully" << endl;
    //HomePage();
}

void availabilityStatus() {
    cout << " The required blood type and quantity are Available";
}

bool Recipient::searchForAvailabilityOfBloodTypes(int quantity, Blood_Bank& b)
{

    // badawar 3ala el A type
    if (bloodType == "A+") {
        if (b.A.size() >= quantity - 1)
        {
            return true;
            availabilityStatus();
            cout << " A type is avalible ";
        }


        else if (b.B.size() >= quantity - 1)
        {
            return true;
            availabilityStatus();
            cout << " B type is avalible ";
        }
        else if (b.O.size() >= quantity - 1)
        {
            return true;
            availabilityStatus();
            cout << " o type is avalible ";
        }
        else
        {
            cout << "Your request is not Available ";
            cout << " you are directed to the waiting list";
            return false;
        }
    }
    // badawar 3ala el b
    else if (bloodType == "B+") {

        if (b.B.size() >= quantity - 1)
        {
            return true;
            availabilityStatus();
            cout << " B type is avalible ";

        }
        else  if (b.O.size() >= quantity - 1)
        {
            return true;
            availabilityStatus();
            cout << " O type is avalible ";
        }
        else {
            cout << "Your request is not Available ";
            cout << " you are directed to the waiting list";
            return false;
        }
    }


    // o type
    else if (bloodType == "O+") {
        if (b.O.size() >= quantity - 1)
        {

            return true;
            availabilityStatus();
            cout << " O type is avalible ";
        }
        else {
            cout << "Your request is not Available ";
            cout << " you are directed to the waiting list";
            return false;
        }
    }

    else if (bloodType == "AB+") {
        if (b.AB.size() >= quantity - 1)
        {

            return true;
            availabilityStatus();
            cout << " AB type is avalible ";
        }
        else if (b.O.size() >= quantity - 1)
        {

            return true;
            availabilityStatus();
            cout << " O type is avalible ";
        }
        else  if (b.A.size() >= quantity - 1)
        {
            return true;
            availabilityStatus();
            cout << " A type is avalible ";
        }
        else
        {
            cout << "Your request is not Available ";
            cout << " you are directed to the waiting list";
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
void Blood_Bank::Request(bool check)
{

if (searchForAvailabilityOfBloodTypes()==true) {
requestlist.push(ID);
cout<<"your request has been submitted sucessfully"<<endl;
}
else 
{
waitinglist.push(ID); 
cout<<"You are directed to the waiting list"<<endl;
}
}
