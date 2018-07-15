#include <iostream>
#include <sstream>
#include <windows.h>
#include "Conversion.h"


using namespace std;


string Conversion::intToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();

    return str;
}

string Conversion::commaToDot(string userAmount)
{
    string userAmountWithDot = "";
    for (int i = 0; i < userAmount.length(); i++)
    {
        if (userAmount[i] == 44)
        {
            userAmount[i] = 46;
        }

        userAmountWithDot = userAmountWithDot + userAmount[i];

    }
    return userAmountWithDot;
}
string Conversion::doubleToString(double amount)
{
    ostringstream buff;
    buff << amount;
    return buff.str();
}
