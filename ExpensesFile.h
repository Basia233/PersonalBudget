#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "Expense.h"
#include "AncillaryMethods.h"
#include "XMLFile.h"

using namespace std;

class ExpensesFile : public XMLFile
{
    int idOfLastExpense;
    AncillaryMethods ancillaryMethods;

public:
    ExpensesFile(string expensesFileName): XMLFile(expensesFileName)
    {
        idOfLastExpense = 0;
    };

    void addExpenseToFile(Expense expense);
    int getIdOfLastExpense();

    vector <Expense> loadExpensesOfLoggedInUserFromFile(int idOfLoggedInUser);

};

#endif
