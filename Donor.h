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
	int date;
	Donor();
	void Register(vector<Donor>&);
	static void Login(vector<Donor>&);
	void Update();
	void Delete();
	void HomePage();
	bool DonationReq();
};
