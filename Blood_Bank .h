#pragma once
#include<queue>
#include<string>
#include "date.h"

using namespace std;


class Blood_Bank
{
public:
	queue<int> requestlist;
	queue<int> waitinglist;
	queue<int> donationlist;
	queue<date> A;
	queue<date> B;
	queue<date> O;
	queue<date> AB;
	Blood_Bank();


};
