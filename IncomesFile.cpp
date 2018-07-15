#include <iostream>
#include <vector>
#include <iomanip>
#include <windows.h>
#include "Markup.h"
#include "Incomes.h"
#include "UserManager.h"
#include "IncomesFile.h"
#include "UserFile.h"
#include "Date.h"

using namespace std;

void IncomesFile::addIncomeToTextFile( Incomes income )
{
    Conversion conversion;
    UserManager userManager;
    CMarkup xmlFile;
    xmlFile.Load("Incomes.xml");

    if ( !xmlFile.FindElem("INCOMES"))
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("INCOMES");

    }

    xmlFile.IntoElem();
    xmlFile.AddElem("INCOMES");
    xmlFile.IntoElem();
    xmlFile.AddElem("INCOMEID", conversion.intToString(income.getIncomeId()));
    xmlFile.AddElem("USERID", conversion.intToString(income.getUserId()));
    xmlFile.AddElem("DATE", income.getDate());
    xmlFile.AddElem("ITEM", income.getItem());
    xmlFile.AddElem("AMOUNT", conversion.doubleToString(income.getAmount()));
    xmlFile.OutOfElem();
    xmlFile.Save("Incomes.xml");

}

Incomes IncomesFile::loadIncomesFromFile(vector <Incomes> &incomes)
{
    Conversion conversion;
    UserFile userFile;
    Incomes income;
    User user;
    Date date;

    CMarkup xmlFile;
    xmlFile.Load("Incomes.xml");

    xmlFile.FindElem();
    xmlFile.IntoElem();

    while ( xmlFile.FindElem("INCOMES"))
    {
        xmlFile.IntoElem();
        xmlFile.FindElem("INCOMEID");
        string incomeId = xmlFile.GetData();
        income.setIncomeId(atoi(incomeId.c_str()));
        xmlFile.FindElem("USERID");
        string userId = xmlFile.GetData();
        income.setUserId(atoi(userId.c_str()));
        xmlFile.FindElem("DATE");
        string dateFromFile = xmlFile.GetData();
        int dateStringToInt = date.sumOfSeparateDate(dateFromFile);
        income.setDate(dateFromFile);
        income.setSumOfDate(dateStringToInt);
        xmlFile.FindElem("ITEM");
        string item = xmlFile.GetData();
        income.setItem(item);
        xmlFile.FindElem("AMOUNT");
        string amount = xmlFile.GetData();
        income.setAmount(atof(amount.c_str()));
        incomes.push_back(income);
        xmlFile.OutOfElem();

    }

    return income;


}
