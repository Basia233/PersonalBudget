#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>
#include <iomanip>
#include "Markup.h"
#include "Finances.h"
#include "DatesManager.h"
#include "AncillaryMethods.h"


using namespace std;

class BalanceManager
{
    DatesManager datesManager;

public:
    void showBalanceForCurrentMonth(vector <Finances> incomes, vector <Finances> expenses);
    void showBalanceForPreviousMonth(vector <Finances> incomes, vector <Finances> expenses);
    void showBalanceForSelectedPeriod(vector <Finances> incomes, vector <Finances> expenses);

};

#endif
