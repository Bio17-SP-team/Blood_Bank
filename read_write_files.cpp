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
    ifstream fs;
    string line;
    fs.open(file);
    int count = 0, array_count = 0;
    while (getline(fs, line))
        {
            if (count == 0) {
            d[array_count].ID = std::stoi(line);
        }
        else if (count == 1) {
		    string g = line;
            d[array_count].gender = line.at(0);
        }
        else if (count == 2) {
            d[array_count].name = line;
        }
        else if (count == 3) {
            d[array_count].mail = line;
        }
        else if (count == 4) {
            d[array_count].password = line;
        }
        else if(count==5){
            d[array_count].bloodType = line;
        }
		else if (count == 6) {
            d[array_count].age = std::stoi(line);
        }
        else if (count==7) {
		string flag = line;
		    if (flag == "0"){	
            d[array_count].illnesses = false;
			}
			else {
			d[array_count].illnesses = true;
			}
        }
        else if (count==8) {
            d[array_count].others = line;
        }
		else {
		    d[array_count].date = line;
        }
        count++;
        if (count > 9) {
            count = 0;
            array_count++;
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
