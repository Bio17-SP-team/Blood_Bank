#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Blood_Bank.h"
#include "User.h"
#include "date.h"
using namespace std;

class Donor : public User
{
public:
	bool illnesses;
	string others;
	date date;



	Donor();
	void Register();
	static void Login(vector<Donor>&, Blood_Bank&);
	void Update(Blood_Bank& b);
	static void Delete(vector<Donor>& d);
	void HomePage(Blood_Bank&);
	void DonationReq(Blood_Bank&);
	void setIllness();
	void setOthers();
	void setDonationdate();
};
