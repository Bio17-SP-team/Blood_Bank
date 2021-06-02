#include <iostream>
#include <fstream>
using namespace std;

class read_write_files{
public:

void read_file(queue<string> a, string file) {
        ifstream fs;
        string line;
        fs.open(file);
        
        while (getline(fs, line))
        {
                a.push(line);
        }
        fs.close();
        
}

void write_file(queue<string> a, string file) {
    ofstream cf;
    cf.open(file);
    while(!a.empty())
	{
		cf <<a.front()<<endl;
		a.pop();
	}
    cf.close();
}
};