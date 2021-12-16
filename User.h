#pragma once
#include <iostream>
#include <string>

using namespace std;
class User
{
public:
	int ID, age;
	char gender;
	string name, mail, password;
	string bloodType;

	User();
	void Register();
	void Update();
	void Logout();
	void setGender();
	void setBloodtype();
	void setId();
	void setName();
	void setPass();
	void setMail();
	void setAge();

};
