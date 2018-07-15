#include <iostream>
#include <time.h>
#include <windows.h>
#include <iomanip>
#include "Conversion.h"
#include "Incomes.h"
#include "Date.h"


using namespace std;


Date::Date()
{

}
Date::~Date()
{

}
Date::DateComponents Date::separateDate(string userDate)
{
    Incomes income;
    DateComponents dateComponents;
    string userDateToSeparate = userDate + "-";
    string singleDate = "";
    int numberOfSingleDate = 1;

    for (int signPosition = 0; signPosition < userDateToSeparate.length(); signPosition++)
    {
        if (userDateToSeparate[signPosition] != '-' )
        {
            singleDate += userDateToSeparate[signPosition];
        }
        else
        {

            switch (numberOfSingleDate)
            {
            case 1:
                dateComponents.year = singleDate;
                break;
            case 2:
                dateComponents.month = singleDate;
                break;
            case 3:
                dateComponents.day = singleDate;
                break;

            }
            singleDate = "";
            numberOfSingleDate++;
        }
    }
    return dateComponents;
}

int Date::checkHowMaynyDaysInMonth (int month, int year)
{

    int amountOfDay = 0;

    switch( month )
    {
    case 1:
    {
        amountOfDay = 31;
        break;
    }
    case 2:
    {
        if (((year%4 == 0) && (year%100 !=0)) || (year%400 == 0))
        {
            amountOfDay = 29;
        }
        else
        {
            amountOfDay = 28;
        }
        break;
    }
    case 3:
    {
        amountOfDay = 31;
        break;
    }
    case 4:
    {
        amountOfDay = 30;
        break;
    }
    case 5:
    {
        amountOfDay = 31;
        break;
    }
    case 6:
    {
        amountOfDay = 30;
        break;
    }
    case 7:
    {
        amountOfDay = 31;
        break;
    }
    case 8:
    {
        amountOfDay = 31;
        break;
    }
    case 9:
    {
        amountOfDay = 30;
        break;
    }
    case 10:
    {
        amountOfDay = 31;
        break;
    }
    case 11:
    {
        amountOfDay = 30;
        break;
    }
    case 12:
    {
        amountOfDay = 31;
        break;
    }
    default:
    {
        cout << "Error!\n";
        system( "PAUSE" );
    }
    }

    return amountOfDay;

}

int Date::sumOfSeparateDate(string sumOfDate)
{
    string results = "";

    for (int i = 0; i < sumOfDate.length(); i++)
    {

        if (sumOfDate[i] != 45 )
        {
            results = results + sumOfDate[i];
        }
    }
    int dateStringToInt = atoi(results.c_str());

    return dateStringToInt;
}

int Date::checkDate( string userDate)
{
    Date date;
    DateComponents dateComponents;
    int amountOfDay = 0;
    int amountOfCurrentMonth = 0;
    string singleDate;
    SYSTEMTIME czas;
    GetLocalTime(&czas);


    int currentYear = czas.wYear;
    int currentMonth = czas.wMonth;
    int currentDay = czas.wDay;

    dateComponents = separateDate( userDate);

    string separateYear = dateComponents.year;
    string separateMonth = dateComponents.month;
    string separateDay = dateComponents.day;

    int year = atoi(separateYear.c_str());
    int month = atoi(separateMonth.c_str());
    int day = atoi(separateDay.c_str());

    string sumOfDate = separateYear+separateMonth+separateDay;

    amountOfDay = checkHowMaynyDaysInMonth(month, year);
    amountOfCurrentMonth = checkHowMaynyDaysInMonth(currentMonth, year);

    if(( year > 1999 ) && (year <= currentYear) && (month <= 12) && (month >0) && (day > 0) && (day <= amountOfDay) )
    {

        return 1 ;
    }
    else if ((year == currentYear) && (month <= currentMonth) && (day <= amountOfCurrentMonth))
    {

        return 1 ;

    }
    else
    {
        return 0;
    }

}

string Date::enterDate()
{
    string userDate;
    int goodDate = 0;
    int goodFormat = 0;
    Date date;

    cin.sync();
    getline(cin, userDate);

    goodFormat = date.checkFormat(userDate);

    while ((goodFormat < 1) || (goodDate < 1))
    {
        if (goodFormat == 0)
        {
            system("cls");
            cout << "INCORRECT DATE FORMAT!" << endl;
            cout << "ENTER AGAIN: [RRRR-MM-DD]: " << endl;
            cin.sync();
            getline(cin, userDate);
            goodFormat = date.checkFormat(userDate);

        }


        if (goodFormat == 1)
        {
            goodDate = date.checkDate(userDate);

        }

    }

    return userDate;
}

int Date::checkFormat(string userDate)
{


    if ((userDate[4] =='-') && (userDate[7] == '-'))
    {

        if (((userDate[5] == '0') && (userDate[6] <='9') && (userDate[6] > '0')) || ((userDate[5] =='1') && (userDate[6] >= '0') && (userDate[6] <= '2')) )
        {
            if ( ((userDate[8] == '0') && (userDate[9] <= '9') && (userDate[9] > '0')) || ((userDate[8] == '1') && (userDate[9] <= '9') && (userDate[9] >= '0')) ||
                    ((userDate[8] == '2' ) && (userDate[9] >= '0') && (userDate[9] <= '9')) || ((userDate[8] == '3') && (userDate[9] >= '0') && (userDate[9] <= '1')) )
            {

                return 1;

            }

        }


    }

    else
    {


        return 0;

    }


}

string Date::getCurrentDate()
{
    Conversion conversion;
    string todaysDate;
    string sumOfStringDate;
    SYSTEMTIME czas;
    GetLocalTime(&czas);

    int day = czas.wDay;
    int month = czas.wMonth;
    int year = czas.wYear;

    if (( month < 10) && (day < 10))
    {
        todaysDate = conversion.intToString(year) + "-" + "0" + conversion.intToString(month) + "-" + "0" + conversion.intToString(day);


    }

    else if (( month < 10) && (day > 10))
    {
        todaysDate = conversion.intToString(year) + "-" + "0" + conversion.intToString(month) + "-" + conversion.intToString(day);
    }

    else if (( month > 10) && (day < 10))
    {
        todaysDate = conversion.intToString(year) + "-" + conversion.intToString(month) + "-" + "0" + conversion.intToString(day);

    }
    else
    {
        todaysDate = conversion.intToString(year) + "-" + conversion.intToString(month) + "-" +  conversion.intToString(day);

    }



    return todaysDate;
}

string Date::getFirstDateInMonth(int year, int month)
{
    Conversion conversion;
    string firstDateInMonth;

    if ( month < 10)
    {
        firstDateInMonth = conversion.intToString(year) + "0" + conversion.intToString(month) + "01" ;


    }
    else
    {
        firstDateInMonth = conversion.intToString(year) + conversion.intToString(month) +  "01";

    }

    return firstDateInMonth;
}

string Date::getLastDateInMonth(int year, int month)
{
    Conversion conversion;
    Date date;
    string lastDateInMonth;
    int lastDayInMonth = date.checkHowMaynyDaysInMonth(month, year);


    if (( month < 10) && (lastDayInMonth < 10))
    {
        lastDateInMonth = conversion.intToString(year) + "0" + conversion.intToString(month) + "0" + conversion.intToString(lastDayInMonth);

    }

    else if (( month > 10) && (lastDayInMonth < 10))
    {
        lastDateInMonth = conversion.intToString(year) + conversion.intToString(month) + "0" + conversion.intToString(lastDayInMonth);
    }

    else if (( month < 10) && (lastDayInMonth > 10))
    {
        lastDateInMonth = conversion.intToString(year) + "0" + conversion.intToString(month) + conversion.intToString(lastDayInMonth);
    }

    else
    {
        lastDateInMonth = conversion.intToString(year) + conversion.intToString(month) +  conversion.intToString(lastDayInMonth);
    }
    return lastDateInMonth;
}

int Date::getCurrentMonth()
{
    SYSTEMTIME czas;
    GetLocalTime(&czas);
    int currentMonth = czas.wMonth;

    return currentMonth;

}

int Date::getCurrentYear()

{
    SYSTEMTIME czas;
    GetLocalTime(&czas);

    int currentYear = czas.wYear;
    return currentYear;

}



