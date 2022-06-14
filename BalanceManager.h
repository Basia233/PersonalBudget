#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "Income.h"
//#include "IncomeManager.h"
#include "Expense.h"
//#include "ExpenseManager.h"
#include "DatesManager.h"
#include "AncillaryMethods.h"


using namespace std;

class BalanceManager
{
    DatesManager datesManager;
    AncillaryMethods ancillaryMethods;

public:
    void showBalanceForCurrentMonth(vector <Income> incomes, vector <Expense> expenses);
    //void showBalanceForPreviousMonth(vector <Income> incomes, vector <Expense> expenses);
    //void showBalanceForSelectedPeriod(vector <Income> incomes, vector <Expense> expenses);

};

#endif
