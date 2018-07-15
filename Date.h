#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;

class Date
{
private:
    struct DateComponents
    {
        string year;
        string month;
        string day;
    };

public:

    Date();
    virtual ~Date();

    string enterDate();
    int getCurrentMonth();
    int getCurrentYear();
    string getFirstDateInMonth(int year, int month);
    string getLastDateInMonth(int year, int month);


    int checkDate( string userDate);
    int checkFormat(string userDate);
    int sumOfSeparateDate(string sumOfDate);


    string getCurrentDate();

private:
    int checkHowMaynyDaysInMonth (int month, int year);
    DateComponents separateDate(string userDate);


};

#endif
