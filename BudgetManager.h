#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include "Incomes.h"
#include "Expenses.h"
#include "Date.h"


using namespace std;

class BudgetManager
{

private:
    int userId;
    Date date;
    Incomes *incomes;
    Expenses *expenses;

public:
    BudgetManager (int userId);
    virtual ~BudgetManager();

    void addIncome();
    void addExpenses();
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviouslyMonth();
    void ShowBalanceFromSelectedPeriod();

private:
    void showBalance(int stratDate, int EndDate);

};

#endif
