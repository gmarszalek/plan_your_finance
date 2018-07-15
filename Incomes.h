#include <iostream>
#include <vector>
#include "UserManager.h"
#include "Conversion.h"
#pragma once



using namespace std;

class Incomes
{
    int incomeId;
    int userId;
    int sumOfDate;
    double amount;
    string date;
    string item;
    vector <Incomes> incomes;

public:
    int getIncomeId();
    int getUserId();
    int getSumOfDate();
    string getDate();
    string getItem();
    double getAmount();
    void setIncomeId(int incomeId);
    void setUserId(int userId);
    void setSumOfDate (int sumOfDate);
    void setDate (string date);
    void setItem(string item);
    void setAmount(double amount);
    void addIncome(int userId);
    int showBalanceFromCurrentMonth(int userId);
    int showBalanceFromPreviousMonth(int userId);
    int showBalanceFromSelectedPeriod(int userId, string startDate, string endDate);


    bool operator<(const Incomes &income)const
    {
        return sumOfDate <  income.sumOfDate;
    }


};
