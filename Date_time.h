#pragma once
class Date_time
{
public:
	Date_time();
	bool isLeap(date&);
	int offsetDays(date&);
	void revoffsetDays(int, date&);
	void addDays(date&, int);

};
