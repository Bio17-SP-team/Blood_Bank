#pragma once
#include "Blood_Bank.h"
#include <iostream>
#include <queue>
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
	bool searchForAvailabilityOfBloodTypes(Blood_Bank&);
	void DisplayBloodTypes(Blood_Bank&);// ele ana 25atooo // ask for functionality  /*alert */
	void RequestABloodType(Blood_Bank&);// blood type  , quantity ,( hospital ( from his data )
};
