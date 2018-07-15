#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>
#include <vector>
#include "UserManager.h"
#include "Conversion.h"


using namespace std;

class Expenses
{
    int expenseId;
    int userId;
    int sumOfDate;
    double amount;
    string date;
    string item;
    vector <Expenses> expenses;

public:
    int getExpenseId();
    int getUserId();
    int getSumOfDate();
    string getDate();
    string getItem();
    double getAmount();
    void setExpenseId(int expenseId);
    void setUserId(int userId);
    void setSumOfDate (int sumOfDate);
    void setDate (string date);
    void setItem(string item);
    void setAmount(double amount);
    void addExpense(int userId);
    int showBalanceFromCurrentMonth(int userId);
    int showBalanceFromPreviousMonth(int userId);
    int showBalanceFromSelectedPeriod(int userId, string startDate, string endDate);

    bool operator<(const Expenses &expense)const
    {
        return sumOfDate <  expense.sumOfDate;
    }


};

#endif
