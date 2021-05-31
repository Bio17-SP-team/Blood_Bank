#pragma once
#include<queue>
#include"Blood.cpp"
class Blood_Bank
{
	queue<Blood> Aplus;
	queue<Blood> Aminus;
	queue<Blood> Bplus;
	queue<Blood> Bminus;
	queue<Blood> Oplus;
	queue<Blood> Ominus;
	queue<Blood> ABplus;
	queue<Blood> ABminus;
	Blood_Bank();
	~Blood_Bank();


};
