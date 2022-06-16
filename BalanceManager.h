#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>
#include <iomanip>
#include "Markup.h"
#include "Income.h"
#include "Expense.h"
#include "DatesManager.h"
#include "AncillaryMethods.h"


using namespace std;

class BalanceManager
{
    DatesManager datesManager;

public:
    void showBalanceForCurrentMonth(vector <Income> incomes, vector <Expense> expenses);
    void showBalanceForPreviousMonth(vector <Income> incomes, vector <Expense> expenses);
    void showBalanceForSelectedPeriod(vector <Income> incomes, vector <Expense> expenses);

};

#endif
