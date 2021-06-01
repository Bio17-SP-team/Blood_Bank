#pragma once
#include<deque>
#include"Blood.cpp"
#include<string>
using namespace std;
class Blood_Bank
{
public:
	deque<Blood> Aplus;
	queue<Blood> Aminus;
	queue<Blood> Bplus;
	queue<Blood> Bminus;
	queue<Blood> Oplus;
	queue<Blood> Ominus;
	queue<Blood> ABplus;
	queue<Blood> ABminus;
	bool searchForAvalabilityOfBloodTypes(int, string);
	void Request(bool);
	void Waiting_list(bool);
	Blood_Bank();
	~Blood_Bank();


};

