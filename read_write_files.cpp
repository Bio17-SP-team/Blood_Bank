#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "Donor.h"
#include "Recipient.h"
#include "Blood_Bank.h"
#include "date.h"
using namespace std;

class read_write_files {
public:
    void read_intqueue(queue<int>& a, string file) {
        ifstream fs;
        string line;
        fs.open(file);
        while (getline(fs, line))
        {
            int i = std::stoi(line);
            a.push(i);
        }
        fs.close();

    }

    void write_intqueue(queue<int>& a, string file) {
        ofstream cf;
        cf.open(file);
        while (!a.empty())
        {
            cf << a.front() << endl;
            a.pop();
        }
        cf.close();
    }

    void read_datequeue(queue<date>& a, string file) {
        ifstream fs;
        string line;
        int count = 0;
        date date;
        fs.open(file);
        while (getline(fs, line))
        {
            if (count == 0) {
                date.day = std::stoi(line);
            }
            else if (count == 1) {
                date.month = std::stoi(line);
            }
            else {
                date.year = std::stoi(line);
            }
            count++;
            if (count > 2) {
                a.push(date);
                count = 0;
            }
        }
        fs.close();

    }

    void write_datequeue(queue<date>& a, string file) {
        ofstream cf;
        cf.open(file);
        while (!a.empty())
        {
            cf << a.front().day << endl;
            cf << a.front().month << endl;
            cf << a.front().year << endl;
            a.pop();
        }
        cf.close();
    }

    void read_donor(vector<Donor>& d, string file) {
        Donor donor;
        ifstream fs;
        string line;
        fs.open(file);
        int count = 0;
        while (getline(fs, line))
        {
            if (count == 0) {
                donor.ID = std::stoi(line);
            }
            else if (count == 1) {
                string g = line;
                donor.gender = line.at(0);
            }
            else if (count == 2) {
                donor.name = line;
            }
            else if (count == 3) {
                donor.mail = line;
            }
            else if (count == 4) {
                donor.password = line;
            }
            else if (count == 5) {
                donor.bloodType = line;
            }
            else if (count == 6) {
                donor.age = std::stoi(line);
            }
            else if (count == 7) {
                string flag = line;
                if (flag == "0") {
                    donor.illnesses = false;
                }
                else {
                    donor.illnesses = true;
                }
            }
            else if (count == 8) {
                donor.others = line;
            }
            else if (count == 9) {
                donor.date.day = std::stoi(line);
            }
            else if (count == 10) {
                donor.date.month = std::stoi(line);
            }
            else {
                donor.date.year = std::stoi(line);
            }
            count++;
            if (count > 11) {
                d.push_back(donor);
                count = 0;
            }
        }
        fs.close();
    }

    void write_donor(vector<Donor>& d, string file) {
        ofstream cf;
        cf.open(file);
        for (int i = 0; i < d.size(); i++) {
            cf << d[i].ID << endl;
            cf << d[i].gender << endl;
            cf << d[i].name << endl;
            cf << d[i].mail << endl;
            cf << d[i].password << endl;
            cf << d[i].bloodType << endl;
            cf << d[i].age << endl;
            cf << d[i].illnesses << endl;
            cf << d[i].others << endl;
            cf << d[i].date.day << endl;
            cf << d[i].date.month << endl;
            cf << d[i].date.year << endl;
            

        }
        cf.close();
    }

    void read_recipient(vector<Recipient>& r, string file) {
        Recipient recipient;
        ifstream fs;
        string line;
        fs.open(file);
        int count = 0;
        while (getline(fs, line))
        {
            if (count == 0) {
                recipient.ID = std::stoi(line);
            }
            else if (count == 1) {
                recipient.gender = line.at(0);
            }
            else if (count == 2) {
                recipient.name = line;
            }
            else if (count == 3) {
                recipient.mail = line;
            }
            else if (count == 4) {
                recipient.password = line;
            }
            else if (count == 5) {
                recipient.bloodType = line;
            }
            else if (count == 6) {
                recipient.age = std::stoi(line);
            }
            else if (count == 7) {
                recipient.hospital = line;
            }
            else {
                recipient.case_doctor = line;
            }
            count++;
            if (count > 8) {
                r.push_back(recipient);
                count = 0;
            }
        }
        fs.close();
    }

    void write_recipient(vector<Recipient>& r, string file) {
        ofstream cf;
        cf.open(file);
        for (int i = 0; i < r.size(); i++) {
            cf << r[i].ID << endl;
            cf << r[i].gender << endl;
            cf << r[i].name << endl;
            cf << r[i].mail << endl;
            cf << r[i].password << endl;
            cf << r[i].bloodType << endl;
            cf << r[i].age << endl;
            cf << r[i].hospital << endl;
            cf << r[i].case_doctor << endl;
            

        }
        cf.close();
    }

};
