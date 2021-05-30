#pragma once
#include <iostream>
#include <string>

using namespace std;
class User
{
private:
	int ID;
	string name,  mail, password;
	int bloodType;
	
public:
	User();
	void Register();
	void Login();
	void Update();
	void Delete();
	void homePage();
	void mainMenu();
	~User();
	






};

