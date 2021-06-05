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
string date;
Donor();
void Register();
void Update();
bool donationReq();
};
