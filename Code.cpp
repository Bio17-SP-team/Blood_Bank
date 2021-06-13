#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <vector>
#include "Blood_Bank.h"
#include "Donor.h"
#include "read_write_files.cpp"
#include "Recipient.h"
using namespace	std;

void mainmenu(vector<Donor> d, vector<Recipient> r, Blood_Bank b) {
	while (true) {
		cout << "\t\t\tWelcome to Blood Bank System\n";
		cout << "To enter as a donor, press 1\nTo enter as a recipient press 2\nIf you want to exit, press any other key: ";
		int mainchoice, subchoice;
		cin >> mainchoice;
		if (mainchoice == 1) {
			cout << "To register, press 1\nTo login, press 2: ";
			cin >> subchoice;
			while (subchoice < 1 || subchoice > 2)
			{
				cout << "Invalid Input!" << endl;
				cout << "Try Again" << endl;
				cin >> subchoice;
			}

			if (subchoice == 1) {
				Donor donor;
				donor.Register(d);
				d.push_back(donor);
			}
			else if (subchoice == 2) {
				Donor::Login(d);
			}

		}
		else if(mainchoice == 2) {
			cout << "To register, press 1\nTo login, press 2: ";
			cin >> subchoice;
			while (subchoice < 1 || subchoice > 2)
			{
				cout << "Invalid Input!" << endl;
				cout << "Try Again" << endl;
				cin >> subchoice;
			}

			if (subchoice == 1) {
				Recipient recipient;
				recipient.Register(r, b);
				r.push_back(recipient);
			}
			else if (subchoice == 2) {
				Recipient::Login(r, b);
			}
		}
		else {
			break;
		}
	}
}

int	main()
{
	vector<Donor> donors;
	vector<Recipient> recipients;
	Blood_Bank bloodbank;
	mainmenu(donors, recipients, bloodbank);
}

//////////////////////////////////////////////////////////////////////


#pragma once
#include <iostream>
#include <string>

using namespace std;
class User
{
public:
	int ID;
	char gender;
	string name, mail, password;
	string bloodType;

	User();
	void Register();
	void Update();
	void Delete();
	void HomePage();
	void Logout();
};

///////////////////////////////////////////////////////////


#include "User.h"
#include<iostream>

using namespace std;

User::User() {}

void User::Delete() {}

void User::HomePage() {}

void User::Logout() {
    cout << "Loged out sucessfully!\n";
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
        cout << "Try Again" << endl;
        cin >> password;
    }
    cout << "Enter your mail:" << endl;
    cin >> mail;

    cout << "Choose your gender: " << endl;
    int gchoice;
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

    cout << "Choose your blood type:" << endl;
    cout << "1- A" << endl;
    cout << "2- B" << endl;
    cout << "3- AB" << endl;
    cout << "4- O" << endl;
    int btype;
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

void User::Update() {

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
}

/////////////////////////////////////////////////////////


#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "User.h"

using namespace std;

struct date {
	int day, month, year = 0;
};

class Donor : public User
{
public:
	int age;
	bool illnesses;
	string others;
	date date;
	Donor();
	void Register(vector<Donor>&);
	static void Login(vector<Donor>&);
	void Update();
	void Delete();
	void HomePage();
	bool DonationReq();
};


///////////////////////////////////////////////////////////////


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
    if (age < 17 || age > 60) {
        cout << "Your age is not suitable to be a donor" << endl;
    }

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
    Login(d);
}


///////////////////////////////////////////////////////////////


pragma once
#include "Blood_Bank.h"
#include <iostream>
#include <vector>
#include <string>
#include "User.h"

using namespace std;
class Recipient : public User
{
public:
	int age;
	string hospital;
	string case_doctor;
	Recipient();
	void Register(vector<Recipient>&, Blood_Bank&);
	static void Login(vector<Recipient>&, Blood_Bank&);
	void Update();
	void Delete();
	void HomePage(Blood_Bank&);
	bool searchForAvailabilityOfBloodTypes(int, Blood_Bank&);
	void DisplayBloodTypes(Blood_Bank&);// ele ana 25atooo // ask for functionality  /*alert */
	void RequestABloodType();// blood type  , quantity ,( hospital ( from his data )
};


///////////////////////////////////////////////////////////////////////


#include "Recipient.h"
#include "Blood_Bank.h"
#include <iostream>
#include "stdio.h"
using namespace std;

void Recipient::HomePage(Blood_Bank& b) {
    cout << "test";
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
    Login(r, b);
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
