#ifndef CONVERSION_H
#define CONVERSION_H

#include <iostream>
#pragma once


using namespace std;


class Conversion
{
public:

    string intToString(int number);
    string commaToDot(string userAmount);
    string doubleToString(double amount);
};

#endif
