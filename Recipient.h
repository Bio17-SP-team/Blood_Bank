#pragma once
#include "blood_bank.h"
#include <iostream>
#include <string>
#include "user.h"

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
	bool searchForAvailabilityOfBloodTypes(int, Blood_Bank&);
	void DisplayBloodTypes(Blood_Bank&);// ele ana 25atooo // ask for functionality  /*alert */
	void RequestABloodType();// blood type  , quantity ,( hospital ( from his data )
};
