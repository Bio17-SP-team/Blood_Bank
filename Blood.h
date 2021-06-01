
#pragma once
#include<iostream>
#include<string>
using namespace std;
class Blood
{
	string blood_type;
	string recieved_data;
	int quantity;
	Blood(string, string, int);
	~Blood();

};

*****************
//bngarab hena
#pragma once
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
class Blood
{
	string blood_type;
	int quantity;
	time_t tmNow = time(0);
	char* dt = ctime(&tmNow);
	Blood(string ,time_t , int);
	Blood();
	~Blood();

};

