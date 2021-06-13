#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <vector>
#include "Blood_Bank.h"
#include "Donor.h"
#include "read_write_files.cpp"
#include "Recipient.h"
using namespace	std;

void mainmenu(vector<Donor> d, vector<Recipient> r, Blood_Bank b) {
	while (true) {
		cout << "\t\t\tWelcome to Blood Bank System\n";
		cout << "To enter as a donor, press 1\nTo enter as a recipient press 2\nIf you want to exit, press any other key: ";
		int mainchoice, subchoice;
		cin >> mainchoice;
		if (mainchoice == 1) {
			cout << "To register, press 1\nTo login, press 2: ";
			cin >> subchoice;
			while (subchoice < 1 || subchoice > 2)
			{
				cout << "Invalid Input!" << endl;
				cout << "Try Again" << endl;
				cin >> subchoice;
			}

			if (subchoice == 1) {
				Donor donor;
				donor.Register(d);
				d.push_back(donor);
				Donor::Login(d);
			}
			else if (subchoice == 2) {
				Donor::Login(d);
			}

		}
		else if(mainchoice == 2) {
			cout << "To register, press 1\nTo login, press 2: ";
			cin >> subchoice;
			while (subchoice < 1 || subchoice > 2)
			{
				cout << "Invalid Input!" << endl;
				cout << "Try Again" << endl;
				cin >> subchoice;
			}

			if (subchoice == 1) {
				Recipient recipient;
				recipient.Register(r, b);
				r.push_back(recipient);
				Recipient::Login(r, b);
			}
			else if (subchoice == 2) {
				Recipient::Login(r, b);
			}
		}
		else {
			break;
		}
	}
}

int	main()
{
	read_write_files rw;
	vector<Donor> donors;
	vector<Recipient> recipients;
	Blood_Bank bloodbank;
	rw.read_queue(bloodbank.A, "A.txt");
	rw.read_queue(bloodbank.B, "B.txt");
	rw.read_queue(bloodbank.AB, "AB.txt");
	rw.read_queue(bloodbank.O, "O.txt");
	mainmenu(donors, recipients, bloodbank);
	rw.write_queue(bloodbank.A, "A.txt");
	rw.write_queue(bloodbank.B, "B.txt");
	rw.write_queue(bloodbank.AB, "AB.txt");
	rw.write_queue(bloodbank.O, "O.txt");

}
