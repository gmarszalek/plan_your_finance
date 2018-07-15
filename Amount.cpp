#include <iostream>
#include "Conversion.h"
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include "Amount.h"


using namespace std;

string Amount::checkAmount(string userAmount)
{

    Conversion conversion;
    string userAmountAfterConvertion = conversion.commaToDot(userAmount);

    return userAmountAfterConvertion;
}

double Amount::enterAmount()
{
    Amount amount;
    bool isCorrect = true;
    bool greaterThanZero = true;
    string userAmount;
    cout << "AMOUNT OF INCOME: " << endl;
    cin >> userAmount;
    isCorrect = isCorrectAmount(userAmount);

    while ((isCorrect == false) || ( greaterThanZero == false ))
    {
        cout << "INCORECT AMOUT, PLEASE ENTER AGAIN: " << endl;
        cin >> userAmount;
        isCorrect = isCorrectAmount(userAmount);
        string userAmountWithDot = conversion.commaToDot(userAmount);
        double amountLikeADouble = amount.roudDownToTwoDigitsAfterDot(userAmountWithDot);
        if (amountLikeADouble == 0)
        {
            greaterThanZero = false;
        }
        else
        {
            greaterThanZero = true;
        }
    }
    string userAmountWithDot = conversion.commaToDot(userAmount);

    double amountLikeADouble = amount.roudDownToTwoDigitsAfterDot(userAmountWithDot);

    return amountLikeADouble;

}

bool Amount::isCorrectAmount(string amount)
{

    for( int i = 0; i < amount.length(); i++ )
    {
        if( !isdigit( amount[ i ] ) && (amount [ i ] != 46) && (amount[i] != 44) )
            return false;
    }

    return true;
}
double Amount::roudDownToTwoDigitsAfterDot(string userAmountWithDot)
{
    double amount = atof(userAmountWithDot.c_str());
    double amountWithTwoDigitsAfterDot = roundf(amount *100) / 100;

    return amountWithTwoDigitsAfterDot;

}

Amount::Amount()
{

}
Amount::~Amount()
{

}



