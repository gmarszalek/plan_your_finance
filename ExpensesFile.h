#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include "Expenses.h"


using namespace std;

class ExpensesFile
{

public:

    void addExpenseToTextFile( Expenses expense );
    Expenses loadExpenseFromFile(vector <Expenses> &expenses );

};

#endif
