#pragma once
#include "Blood_Bank.h"
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include "User.h"
#include "Date_time.h"

using namespace std;
class Recipient : public User
{
private:
	Date_time date_time;
public:
	string hospital;
	string case_doctor;
	Recipient();
	void Register();
	static void Login(vector<Recipient>&, Blood_Bank&);
	void Update();
	static void Delete(vector<Recipient>&);
	void HomePage(Blood_Bank&);
	bool searchForAvailabilityOfBloodTypes(Blood_Bank&);
	void DisplayBloodTypes(Blood_Bank&);// ele ana 25atooo // ask for functionality  /*alert */
	void RequestABloodType(Blood_Bank&);// blood type  , quantity ,( hospital ( from his data )
	void setHospital();
	void setDoctor();
};
