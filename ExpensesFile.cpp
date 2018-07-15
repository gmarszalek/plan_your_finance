#include <iostream>
#include <vector>
#include <iomanip>
#include <windows.h>
#include "Markup.h"
#include "Date.h"
#include "Incomes.h"
#include "UserManager.h"
#include "ExpensesFile.h"
#include "UserFile.h"

using namespace std;

void ExpensesFile::addExpenseToTextFile( Expenses expense )
{
    Conversion conversion;
    UserManager userManager;
    CMarkup xmlFile;
    xmlFile.Load("Expenses.xml");

    if ( !xmlFile.FindElem("EXPENSES"))
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("EXPENSES");

    }

    xmlFile.IntoElem();
    xmlFile.AddElem("EXPENSES");
    xmlFile.IntoElem();
    xmlFile.AddElem("EXPENSESID", conversion.intToString(expense.getExpenseId()));
    xmlFile.AddElem("USERID", conversion.intToString(expense.getUserId()));
    xmlFile.AddElem("DATE", expense.getDate());
    xmlFile.AddElem("ITEM", expense.getItem());
    xmlFile.AddElem("AMOUNT", conversion.doubleToString(expense.getAmount()));
    xmlFile.OutOfElem();
    xmlFile.Save("Expenses.xml");

}

Expenses ExpensesFile::loadExpenseFromFile(vector <Expenses> &expenses)
{
    Conversion conversion;
    UserFile userFile;
    Expenses expense;
    Date date;
    User user;

    CMarkup xmlFile;
    xmlFile.Load("Expenses.xml");

    xmlFile.FindElem();
    xmlFile.IntoElem();

    while ( xmlFile.FindElem("EXPENSES"))
    {
        xmlFile.IntoElem();
        xmlFile.FindElem("EXPENSESID");
        string expenseId = xmlFile.GetData();
        expense.setExpenseId(atoi(expenseId.c_str()));
        xmlFile.FindElem("USERID");
        string userId = xmlFile.GetData();
        expense.setUserId(atoi(userId.c_str()));
        xmlFile.FindElem("DATE");
        string dateFromFile = xmlFile.GetData();
        int dateStringToInt = date.sumOfSeparateDate(dateFromFile);
        expense.setSumOfDate(dateStringToInt);
        expense.setDate(dateFromFile);
        xmlFile.FindElem("ITEM");
        string item = xmlFile.GetData();
        expense.setItem(item);
        xmlFile.FindElem("AMOUNT");
        string amount = xmlFile.GetData();
        expense.setAmount(atof(amount.c_str()));
        expenses.push_back(expense);
        xmlFile.OutOfElem();

    }

    return expense;


}
