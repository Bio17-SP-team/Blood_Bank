
#include "Blood.h"
Blood::Blood(string b, string r, int q) :blood_type(b), recieved_data(r), quantity(q) {};




************************
//bngarab
#include "Blood.h"
#include"Blood_Bank.h"
#include<assert.h>
#include<queue>
#include"Blood_Bank.cpp"
#include<iostream>
using namespace std;
Blood::Blood(string b, time_t expiry_date, int q) :blood_type(b), tmNow(expiry_date), quantity(q) {};


