#include <iostream>
#include <ctime>
#include "date.h"
#include "Date_time.h"
using namespace std;

Date_time::Date_time()
{
}

bool Date_time::isLeap(date& d)
{
    if (d.year % 100 != 0 && d.year % 4 == 0 || d.year % 400 == 0)
        return true;

    return false;
}

// Given a date, returns number of days elapsed
// from the  beginning of the current year (1st
// jan).
int Date_time::offsetDays(date& d)
{
    int offset = d.day;

    switch (d.month - 1)
    {
    case 11:
        offset += 30;
    case 10:
        offset += 31;
    case 9:
        offset += 30;
    case 8:
        offset += 31;
    case 7:
        offset += 31;
    case 6:
        offset += 30;
    case 5:
        offset += 31;
    case 4:
        offset += 30;
    case 3:
        offset += 31;
    case 2:
        offset += 28;
    case 1:
        offset += 31;
    }

    if (isLeap(d) && d.month > 2)
        offset += 1;

    return offset;
}

// Given a year and days elapsed in it, finds
// date by storing results in d and m.
void Date_time::revoffsetDays(int offset, date& d)
{
    int month[13] = { 0, 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31 };

    if (isLeap(d))
        month[2] = 29;

    int i;
    for (i = 1; i <= 12; i++)
    {
        if (offset <= month[i])
            break;
        offset = offset - month[i];
    }

    d.day = offset;
    d.month = i;
}

// Add x days to the given date.
void Date_time::addDays(date& d, int x)
{
    int offset1 = offsetDays(d);
    int remDays = isLeap(d) ? (366 - offset1) : (365 - offset1);

    // y2 is going to store result year and
    // offset2 is going to store offset days
    // in result year.
    date d2;
    int offset2;
    if (x <= remDays)
    {
        d2.year = d.year;
        offset2 = offset1 + x;
    }

    else
    {
        // x may store thousands of days.
        // We find correct year and offset
        // in the year.
        x -= remDays;
        d2.year = d.year + 1;
        d2.day = isLeap(d2) ? 366 : 365;
        while (x >= d2.day)
        {
            x -= d2.day;
            d2.year++;
            d2.day = isLeap(d2) ? 366 : 365;
        }
        offset2 = x;
    }

    // Find values of day and month from
    // offset of result year.
    revoffsetDays(offset2, d2);

    cout << "Expiry date: " << d2.day << "/" << d2.month
        << "/" << d2.year << endl;
}
