//bngarab
#include "Blood_Bank.h"
#include<queue>
#include<string>
#include<deque>
#include<iterator>
#include<iostream>
#include"Blood.cpp"
#include<deque>
using namespace std;
bool Blood_Bank::searchForAvalabilityOfBloodTypes(int quantity, string blood_type)
{
    if()
    Aplus.erase(Aplus.end());
    deque<Blood>::iterator it;
    for (it = Aplus.begin(); it != Aplus.end(); it++)
    {
       
    }
    if (blood_type == "A+"&& Aplus.size()>=quantity-1)
    {

        

    }
    else  if (blood_type == "A-" && Aminus.size() >= quantity - 1)
    {


    }
    else  if (blood_type == "B+" && Bplus.size() >= quantity - 1)
    {


    }
    else if (blood_type == "B-" && Bminus.size() >= quantity - 1)
    {


    }
    else  if (blood_type == "O+" && Oplus.size() >= quantity - 1)
    {



    }
    else if (blood_type == "O-" && Ominus.size() >= quantity - 1)
    {


    }
    else  if (blood_type == "AB+" && ABplus.size() >= quantity - 1)
    {


    }
    else  if (blood_type == "AB-" && ABminus.size() >= quantity - 1)
    {


    }
    else 

        return false;
}
void Blood_Bank::Request(bool check)
{


}
void Blood_Bank::Waiting_list(bool)
{

}
