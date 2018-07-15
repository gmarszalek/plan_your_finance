#include <iostream>
#include <cstdlib>
#include <vector>
#include "BudgetManager.h"
#include "Incomes.h"


using namespace std;

BudgetManager::BudgetManager(int userId)
{
    this -> userId = userId;
}

BudgetManager::~BudgetManager()
{

}

void BudgetManager::addIncome()
{
    UserManager userManager;

    Incomes incomes;
    incomes.addIncome(userId);
}

void BudgetManager::addExpenses()
{
    UserManager userManager;

    Expenses expenses;
    expenses.addExpense(userId);
}

void BudgetManager::showBalanceFromCurrentMonth()
{
    int sumIncomesFromCurrentMonth;
    int sumExpensesFromCurrentMonth;

    cout << " -----Incomes----- ";
    Incomes incomes;
    sumIncomesFromCurrentMonth = incomes.showBalanceFromCurrentMonth(userId);
    cout << " -----EXPENCES----- ";
    Expenses expense;
    sumExpensesFromCurrentMonth = expense.showBalanceFromCurrentMonth(userId);
    cout << "BALANCE FROM CURRENT MONTH: " << endl;
    cout << "INCOMES: " << sumIncomesFromCurrentMonth << endl;
    cout << "EXPENSES: " << sumExpensesFromCurrentMonth << endl;
    cout << "BALANCE: " << sumIncomesFromCurrentMonth - sumExpensesFromCurrentMonth << endl;
    system("pause");


}
void BudgetManager::showBalanceFromPreviouslyMonth()

{
    int sumIncomesFromPreviouslyMonth;
    int sumExpensesFromPreviouslyMonth;
    Incomes incomes;
    cout << " -----Incomes----- " << endl;
    sumIncomesFromPreviouslyMonth = incomes.showBalanceFromPreviousMonth(userId);

    cout << " -----EXPENSES----- " << endl;
    Expenses expense;
    sumExpensesFromPreviouslyMonth = expense.showBalanceFromPreviousMonth(userId);

    cout << "-----BALANCE FROM PREVIOUSLY MONTH: -----" << endl;
    cout << "INCOMES: " << sumIncomesFromPreviouslyMonth << endl;
    cout << "EXPENSES: " << sumExpensesFromPreviouslyMonth << endl;
    cout << "BALANCE: " << sumIncomesFromPreviouslyMonth - sumExpensesFromPreviouslyMonth << endl;
    system("pause");



}
void BudgetManager::ShowBalanceFromSelectedPeriod()
{
    int sumIncomesFromSelectedPeriod;
    int sumExpensesFromSelectedPeriod;

    Date date;
    cout << "PLEASE ENTER A START DATE: ";
    string startDate = date.enterDate();
    cout << "PLEASE ENTER A END DATE: ";
    string endDate = date.enterDate();

    system("cls");
    cout << " -----Incomes----- " << endl;
    Incomes incomes;
    sumIncomesFromSelectedPeriod = incomes.showBalanceFromSelectedPeriod(userId, startDate, endDate);

     cout << " -----EXPENSES----- " << endl;
     Expenses expenses;
     sumExpensesFromSelectedPeriod = expenses.showBalanceFromSelectedPeriod(userId, startDate, endDate);

    cout << "-----BALANCE FROM SELECTED PERIOD: -----" << endl;
    cout << "INCOMES: " << sumIncomesFromSelectedPeriod << endl;
    cout << "EXPENSES: " << sumExpensesFromSelectedPeriod << endl;
    cout << "BALANCE: " << sumIncomesFromSelectedPeriod - sumExpensesFromSelectedPeriod << endl;
    system("pause");




}


