#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "Finances.h"
#include "DatesManager.h"
#include "XMLFile.h"

using namespace std;

class ExpensesFile : public XMLFile
{
    int idOfLastExpense;
    DatesManager datesManager;


public:
    ExpensesFile(string expensesFileName): XMLFile(expensesFileName)
    {
        idOfLastExpense = 0;
    };

    void addExpenseToFile(Finances finances);
    int getIdOfLastExpense();

    vector <Finances> loadExpensesOfLoggedInUserFromFile(int idOfLoggedInUser);

};

#endif
