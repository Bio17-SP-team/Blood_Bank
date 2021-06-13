#pragma once
#include<queue>
#include<string>

using namespace std;

class Blood_Bank
{
public:
	queue<int> requestlist;
	queue<int> waitinglist;
	queue<int> donationlist;
	queue<string> A;
	queue<string> B;
	queue<string> O;
	queue<string> AB;
	Blood_Bank();


};
