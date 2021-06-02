#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include "blood_bank.cpp"
#include "read_write_files.cpp"
using	namespace	std;

int	main()
{
    Blood_Bank b;
	read_write_files rw;
    rw.read_file(b.Aplus, "Aplus.txt");
    rw.read_file(b.Aminus, "Aminus.txt");
    b.Aplus.push("test");
    b.Aplus.push("t3");
    b.Aplus.pop();
    b.Aplus.push("mana4r");
    b.Aminus.push("1");
    b.Aminus.push("ll ii");
    rw.write_file(b.Aplus, "Aplus.txt");
    rw.write_file(b.Aminus, "Aminus.txt");
}