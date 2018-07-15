#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <algorithm>
#include "Expenses.h"
#include "Date.h"
#include "ExpensesFile.h"
#include "Amount.h"


using namespace std;

int Expenses::getExpenseId()
{
    return expenseId;
}
int Expenses::getUserId()
{
    return userId;
}
int Expenses::getSumOfDate()
{
    return sumOfDate;
}
string Expenses::getDate()
{
    return date;
}
string Expenses::getItem()
{
    return item;
}
double Expenses::getAmount()
{
    return amount;
}
void Expenses::setExpenseId(int expenseId)
{
    this -> expenseId = expenseId;
}
void Expenses::setUserId(int userId)
{
    this -> userId = userId;
}
void Expenses::setSumOfDate (int sumOfDate)
{
    this -> sumOfDate = sumOfDate;
}
void Expenses::setDate(string date)
{
    this ->  date = date;
}
void Expenses::setItem(string item)
{
    this -> item = item;
}
void Expenses::setAmount(double amount)
{
    this -> amount = amount;
}


void  Expenses::addExpense(int userId)
{
    Expenses expense;
    Date date;
    ExpensesFile expensesFile;;
    Amount amount;
    string userAmount;
    string userAmountAfterConvertion;
    string userDate;
    char choice;

    expensesFile.loadExpenseFromFile(expenses);


    if (expenses.empty() == true)
    {
        expense.setExpenseId(1);
    }
    else
    {
        expense.setExpenseId(expenses.back().expenseId + 1 );

    }

    system("cls");
    cout << "-----ADD EXPENSE-----" << endl << endl;

    cout << "EXPENSE FROM TODAY (t), OR OTHER DAY (n) ? " << endl;
    cin >> choice;

    if (choice == 't')
    {
        string userDate = date.getCurrentDate();
        int dateStringToInt = date.sumOfSeparateDate(userDate);
        expense.setDate(userDate);
        expense.setSumOfDate(dateStringToInt);
    }
    else if (choice == 'n')
    {
        system("cls");
        cout << "-----EXPENSE FROM ANOTHER DAY-----" << endl;
        cout << "PLEASE ENTER A DATE:[RRRR-MM-DD]: " << endl;
        string userDate = date.enterDate();
        int dateStringToInt = date.sumOfSeparateDate(userDate);
        expense.setDate(userDate);
        expense.setSumOfDate(dateStringToInt);

    }


    cout << "SOURCE OF EXPENSE: " << endl;
    cin >> item;
    cout << endl;

    double inputAmount = amount.enterAmount();

    expense.setUserId(userId);
    expense.setItem(item);
    expense.setAmount(inputAmount);
    expenses.push_back(expense);

    expensesFile.addExpenseToTextFile(expense);
    cout << "The expense has been added!";
    Sleep(1500);

}

int Expenses::showBalanceFromCurrentMonth(int userId)
{
    Expenses expense;
    ExpensesFile expensesFile;
    expensesFile.loadExpenseFromFile(expenses);
    Date date;
    int currentMonth = date.getCurrentMonth();
    int currentYear = date.getCurrentYear();
    string beginingDate = date.getFirstDateInMonth(currentYear, currentMonth);
    int beginingDateToInt = date.sumOfSeparateDate(beginingDate);
    double sum = 0;

    for (vector <Expenses>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        std::sort (expenses.begin(), expenses.end());

        if ( (itr -> Expenses::getUserId()  == userId ) && (itr -> Expenses::getSumOfDate() >= beginingDateToInt))
        {
            cout << "DATE:              " << itr -> Expenses::getDate() << endl;
            cout << "ITEM:              " << itr -> Expenses::getItem() << endl;
            cout << "AMOUNT:            " << itr -> Expenses::getAmount() << endl;
            double result = itr -> Expenses::getAmount();
            sum = sum + result;

        }
        cout << endl;

    }
return sum;

}

int Expenses::showBalanceFromPreviousMonth(int userId)
{
    Expenses expense;
    ExpensesFile expenseFile;
    Date date;
    expenseFile.loadExpenseFromFile(expenses);

    int currentMonth = date.getCurrentMonth();
    int currentYear = date.getCurrentYear();
    int previousMonth = currentMonth - 1;
    string beginingDate = date.getFirstDateInMonth(currentYear, previousMonth);
    int beginingDateToInt = date.sumOfSeparateDate(beginingDate);
    string endingDate = date.getLastDateInMonth(currentYear, previousMonth);
    int endingDateToInt = date.sumOfSeparateDate(endingDate);
    double sum = 0;

    for (vector <Expenses>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        std::sort (expenses.begin(), expenses.end());

        if ( (itr -> Expenses::getUserId()  == userId ) && (itr -> Expenses::getSumOfDate() >= beginingDateToInt) && (itr -> Expenses::getSumOfDate() <= endingDateToInt))
        {
            cout << "DATE:              " << itr -> Expenses::getDate() << endl;
            cout << "ITEM:              " << itr -> Expenses::getItem() << endl;
            cout << "AMOUNT:            " << itr -> Expenses::getAmount() << endl;
            double result = itr -> Expenses::getAmount();
            sum = sum + result;

        }
        cout << endl;

    }
    return sum;


}
int Expenses::showBalanceFromSelectedPeriod(int userId, string startDate, string endDate)
{
    Expenses expense;
    Date date;
    ExpensesFile expenseFile;
    expenseFile.loadExpenseFromFile(expenses);


    int startDateToInt = date.sumOfSeparateDate(startDate);
    int endDateToInt = date.sumOfSeparateDate(endDate);
    double sum = 0;

    for (vector <Expenses>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        std::sort (expenses.begin(), expenses.end());

        if ( (itr -> Expenses::getUserId()  == userId ) && (itr -> Expenses::getSumOfDate() >= startDateToInt) && (itr -> Expenses::getSumOfDate() <= endDateToInt))
        {
            cout << "DATE:              " << itr -> Expenses::getDate() << endl;
            cout << "ITEM:              " << itr -> Expenses::getItem() << endl;
            cout << "AMOUNT:            " << itr -> Expenses::getAmount() << endl;
            double result = itr -> Expenses::getAmount();
            sum = sum + result;

        }
        cout << endl;

    }
  return sum;


}




