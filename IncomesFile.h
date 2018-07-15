#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include "Incomes.h"


using namespace std;

class IncomesFile
{

public:

    void addIncomeToTextFile(Incomes income );
    Incomes loadIncomesFromFile(vector <Incomes> &incomes );

};

#endif
