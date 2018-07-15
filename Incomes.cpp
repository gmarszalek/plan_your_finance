#include <iostream>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <algorithm>
#include "Incomes.h"
#include "Date.h"
#include "IncomesFile.h"
#include "Amount.h"


using namespace std;

int Incomes::getIncomeId()
{
    return incomeId;
}
int Incomes::getUserId()
{
    return userId;
}
int Incomes::getSumOfDate()
{
    return sumOfDate;
}
string Incomes::getDate()
{
    return date;
}
string Incomes::getItem()
{
    return item;
}
double Incomes::getAmount()
{
    return amount;
}
void Incomes::setIncomeId(int incomeId)
{
    this -> incomeId = incomeId;
}
void Incomes::setUserId(int userId)
{
    this -> userId = userId;
}
void Incomes::setSumOfDate (int sumOfDate)
{
    this -> sumOfDate = sumOfDate;
}
void Incomes::setDate(string date)
{
    this ->  date = date;
}
void Incomes::setItem(string item)
{
    this -> item = item;
}
void Incomes::setAmount(double amount)
{
    this -> amount = amount;
}


void  Incomes::addIncome(int userId)
{
    Incomes income;
    Date date;
    IncomesFile incomesFile;
    Amount amount;
    string userAmount;
    string userAmountAfterConvertion;
    string userDate;
    char choice;

    incomesFile.loadIncomesFromFile(incomes);


    if (incomes.empty() == true)
    {
        income.setIncomeId(1);
    }
    else
    {
        income.setIncomeId(incomes.back().incomeId + 1 );

    }

    system("cls");
    cout << "-----ADD INCOME-----" << endl << endl;

    cout << "INCOME FROM TODAY (t), OR OTHER DAY (n) ? " << endl;
    cin >> choice;

    if (choice == 't')
    {

        string userDate = date.getCurrentDate();
        int dateStringToInt = date.sumOfSeparateDate(userDate);
        income.setDate(userDate);
        income.setSumOfDate(dateStringToInt);
    }
    else if (choice == 'n')
    {
        system("cls");
        cout << "-----INCOME FROM ANOTHER DAY-----" << endl;
        cout << "PLEASE ENTER A DATE:[RRRR-MM-DD]: " << endl;
        string userDate = date.enterDate();
        int dateStringToInt = date.sumOfSeparateDate(userDate);
        income.setDate(userDate);
        income.setSumOfDate(dateStringToInt);

    }

    cout << "SOURCE OF INCOME: " << endl;
    cin >> item;
    cout << endl;

    double inputAmount = amount.enterAmount();

    income.setUserId(userId);
    income.setItem(item);
    income.setAmount(inputAmount);
    incomes.push_back(income);

    incomesFile.addIncomeToTextFile(income);
    cout << "The income was added!";
    Sleep(1500);

}

int Incomes::showBalanceFromCurrentMonth(int userId)
{
    Incomes income;
    IncomesFile incomesFile;
    incomesFile.loadIncomesFromFile(incomes);
    Date date;
    int currentMonth = date.getCurrentMonth();
    int currentYear = date.getCurrentYear();
    string beginingDate = date.getFirstDateInMonth(currentYear, currentMonth);
    int beginingDateToInt = date.sumOfSeparateDate(beginingDate);
    double sum = 0;

    for (vector <Incomes>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        std::sort (incomes.begin(), incomes.end());

        if ( (itr -> Incomes::getUserId()  == userId ) && (itr -> Incomes::getSumOfDate() >= beginingDateToInt))
        {
            cout << "DATE:              " << itr -> Incomes::getDate() << endl;
            cout << "ITEM:              " << itr -> Incomes::getItem() << endl;
            cout << "AMOUNT:            " << itr -> Incomes::getAmount() << endl;
            double result = itr -> Incomes::getAmount();
            sum = sum + result;

        }
        cout << endl;

    }
return sum;
}
int Incomes::showBalanceFromPreviousMonth(int userId)
{
    Incomes income;
    IncomesFile incomesFile;
    Date date;
    incomesFile.loadIncomesFromFile(incomes);

    int currentMonth = date.getCurrentMonth();
    int currentYear = date.getCurrentYear();
    int previousMonth = currentMonth - 1;
    string beginingDate = date.getFirstDateInMonth(currentYear, previousMonth);
    int beginingDateToInt = date.sumOfSeparateDate(beginingDate);
    string endingDate = date.getLastDateInMonth(currentYear, previousMonth);
    int endingDateToInt = date.sumOfSeparateDate(endingDate);
    double sum = 0;

    for (vector <Incomes>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        std::sort (incomes.begin(), incomes.end());

        if ( (itr -> Incomes::getUserId()  == userId ) && (itr -> Incomes::getSumOfDate() >= beginingDateToInt) && (itr -> Incomes::getSumOfDate() <= endingDateToInt))
        {
            cout << "DATE:              " << itr -> Incomes::getDate() << endl;
            cout << "ITEM:              " << itr -> Incomes::getItem() << endl;
            cout << "AMOUNT:            " << itr -> Incomes::getAmount() << endl;
            double result = itr -> Incomes::getAmount();
            sum = sum + result;

        }
        cout << endl;

    }
return sum;

}

int Incomes::showBalanceFromSelectedPeriod(int userId, string startDate, string endDate)
{
    Incomes income;
    Date date;
    IncomesFile incomesFile;
    incomesFile.loadIncomesFromFile(incomes);

    int startDateToInt = date.sumOfSeparateDate(startDate);
    int endDateToInt = date.sumOfSeparateDate(endDate);
    double sum = 0;

    for (vector <Incomes>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        std::sort (incomes.begin(), incomes.end());

        if ( (itr -> Incomes::getUserId()  == userId ) && (itr -> Incomes::getSumOfDate() >= startDateToInt) && (itr -> Incomes::getSumOfDate() <= endDateToInt))
        {
            cout << "DATE:              " << itr -> Incomes::getDate() << endl;
            cout << "ITEM:              " << itr -> Incomes::getItem() << endl;
            cout << "AMOUNT:            " << itr -> Incomes::getAmount() << endl;
            double result = itr -> Incomes::getAmount();
            sum = sum + result;

        }
        cout << endl;

    }

return sum;
}



