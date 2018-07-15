#ifndef AMOUNT_H
#define AMOUNT_H

#include <iostream>
#include <math.h>
#include "Conversion.h"


using namespace std;


class Amount
{
private:
    double amount;
    Conversion conversion;

public:
    Amount();
    virtual ~Amount();

    double enterAmount ();

private:
    bool isCorrectAmount(string amount);
    double roudDownToTwoDigitsAfterDot(string amount);

    string checkAmount (string userAmount);
};

#endif
