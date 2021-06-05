#include <iostream>
#include <fstream>
using namespace std;

class read_write_files{
public:

void read_queue(queue<string>& a, string file) {
        ifstream fs;
        string line;
        fs.open(file);  
        while (getline(fs, line))
        {
           a.push(line);
        }
        fs.close();
        
}

void write_queue(queue<string>& a, string file) {
    ofstream cf;
    cf.open(file);
    while(!a.empty())
	{
		cf <<a.front()<<endl;
		a.pop();
	}
    cf.close();
}

void read_donor(vector<Donor>& d, string file){
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
        else if(count==5){
            donor.bloodType = line;
        }
		else if (count == 6) {
            donor.age = std::stoi(line);
        }
        else if (count==7) {
		string flag = line;
		    if (flag == "0"){	
            donor.illnesses = false;
			}
			else {
			donor.illnesses = true;
			}
        }
        else if (count==8) {
            donor.others = line;
        }
		else {
		    donor.date = line;
        }
        count++;
        if (count > 9) {
            d.push_back(donor);
            count = 0;
        }
    }
    fs.close();
}

void write_donor(vector<Donor>& d, string file){
    ofstream cf;
    cf.open(file);
    for(int i = 0; i < d.size(); i++){
	    cf << d[i].ID << endl;
        cf << d[i].gender << endl;
        cf << d[i].name << endl;
        cf << d[i].mail << endl;
        cf << d[i].password << endl;
        cf << d[i].bloodType << endl;
		cf << d[i].age << endl;
        cf << d[i].illnesses << endl;
        cf << d[i].others << endl;		
		cf << d[i].date << endl;
	
	}
    cf.close();
}

};
