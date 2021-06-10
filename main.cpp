#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <vector>
#include "blood_bank.h"
#include "donor.h"
#include "read_write_files.cpp"
#include "recipient.h"
using namespace	std;

int	main()
{
    Blood_Bank bank;
    read_write_files rw;
    vector<Recipient> rlist;
    rw.read_recipient(rlist, "recipients.txt");
    rw.read_queue(bank.A, "A.txt");
    rw.read_queue(bank.B, "B.txt");
    rw.read_queue(bank.O, "O.txt");
    rw.read_queue(bank.AB, "AB.txt");
    Recipient u;
    u.Register();
    u.DisplayBloodTypes(bank);
    rlist.push_back(u);
    rw.write_recipient(rlist, "recipients.txt");
    rw.write_queue(bank.A, "A.txt");
    rw.write_queue(bank.B, "B.txt");
    rw.write_queue(bank.O, "O.txt");
    rw.write_queue(bank.AB, "AB.txt");
}
