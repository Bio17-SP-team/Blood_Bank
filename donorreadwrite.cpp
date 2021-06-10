#pragma once
#include <iostream>
#include <string>

using namespace std;
class User
{
	public:

	int ID;
	char gender;
	string name,  mail, password;
	string bloodType;
	
	User();
	void HomePage();
	void Register();
	void Login();
	void Update();
	void Delete();
	
};


#include "User.h"
#include<iostream>

using namespace std;

User::User(){}

void User::Delete() {}

void User::HomePage() {}

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
    HomePage();
}

void User::Login() {
    string username ; //Read from the file
    string spassword ; //Read from the file
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> spassword;
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
}


#pragma once
#include <iostream>
#include <string>
#include "user.cpp"

using namespace std;
class Donor : public User
{
public: 
int age;
bool illnesses;
string others;
int date;
Donor();
void Register();
void Login();
void Update();
void Delete();
void HomePage();
bool DonationReq();
};


#include "donor.h"
#include <iostream>

using namespace std;

Donor::Donor(){
}

void Donor::Register() {
    
    User::Register();

    cout << "Enter your age: " << endl;
    cin >> age;
    if (age < 17 || age > 60) {
        cout << "Your age is not suitable to be a donor" << endl;
    }

    cout << "Do you suffer from any disease from the following:" << endl<< "Blood Pressure Disorders, Thyroid Disease, Diabetes, Cancer, Heart Disorders, Hepatitis)"<< endl;
    int dChoice;
    cout << "1- Yes" << endl << "2- No " << endl;
    cin >> dChoice;
    while (dChoice < 1 || dChoice > 2)
    {
        cout << "Invalid Input!" << endl;
        cout << "Try Again" << endl;
        cin >> dChoice;
    }

    if(dChoice == 1) {
        illnesses = true;
    }

    else if(dChoice == 2) {
        illnesses = false;
    }

    cout << "Do you suffer from any other disease or Do you take any kind of medications?" << endl ;
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
    else if (c == 'n' || c == 'N'){

        donationStatus = false;

    }
    else {

        cout << "Invalid Input";

    }
    

    cout << "Registration is done successfully" << endl;
    //HomePage();
}



#include <iostream>
#include <fstream>
using namespace std;

class read_write_donor{
public:

void read_donor(vector<Donor>& d, string file){
    Donor donor;
    ifstream fs;
    string line;
    fs.open(file);
    int count = 0;
    while (getline(fs, line))
        {
        if (count == 0) {
            donor.ID = std::stoi(line);
        }
        else if (count == 1) {
            donor.gender = line.at(0);
        }
        else if (count == 2) {
            donor.name = line;
        }
        else if (count == 3) {
            donor.mail = line;
        }
        else if (count == 4) {
            donor.password = line;
        }
        else if(count==5){
            donor.bloodType = line;
        }
		else if (count == 6) {
            donor.age = std::stoi(line);
        }
        else if (count==7) {
		string flag = line;
		    if (flag == "0"){	
            donor.illnesses = false;
			}
			else {
			donor.illnesses = true;
			}
        }
        else if (count==8) {
            donor.others = line;
        }
		else {
		    donor.date = std::stoi(line);
        }
        count++;
        if (count > 9) {
            d.push_back(donor);
            count = 0;
        }
    }
    fs.close();
}

void write_donor(vector<Donor>& d, string file){
    ofstream cf;
    cf.open(file);
    for(int i = 0; i < d.size(); i++){
	    cf << d[i].ID << endl;
        cf << d[i].gender << endl;
        cf << d[i].name << endl;
        cf << d[i].mail << endl;
        cf << d[i].password << endl;
        cf << d[i].bloodType << endl;
		cf << d[i].age << endl;
        cf << d[i].illnesses << endl;
        cf << d[i].others << endl;		
		cf << d[i].date << endl;
	
	}
    cf.close();
}
};



#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <vector>
#include "donor.cpp"
#include "recipient.h"
#include "blood_bank.cpp"
#include "read_write_files.cpp"
using namespace	std;

int	main()
{
	read_write_files rw;
    vector<Recipient> rlist;
    rw.read_recipient(rlist, "recipients.txt");
    Recipient u;
    u.Register();
    rlist.push_back(u);
    cout << "test";
    rw.write_recipient(rlist, "recipients.txt");
}


#pragma once
#include <iostream>
#include <string>
#include "user.cpp"

using namespace std;
class Recipient : public User
{
public: 
int age;
string hospital;
string case_doctor;
Recipient();
void Register();
void Login();
void Update();
void Delete();
void HomePage();
bool searchForAvalabilityOfBloodTypes(); //request  ( calling )
void DisaplayBloodTypes();// ele ana 25atooo // ask for functionality  /*alert */
void RequestABloodType();// blood type  , quantity ,( hospital ( from his data )
};


#include "recipient.h"
#include <iostream>
#include "stdio.h"
using namespace std;

Recipient::Recipient(){}

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

