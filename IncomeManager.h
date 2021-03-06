#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector> //inkludujemy vector bo uzytkownicy beda zapisani w vectorze
#include <windows.h> // system pause
#include <fstream>
#include <sstream> // konwersja int na string

#include "Finances.h"
#include "IncomesFile.h"
#include "DatesManager.h"
#include "AncillaryMethods.h"

using namespace std;

class IncomeManager
{
    const int ID_OF_LOGGED_IN_USER;
    vector <Finances> incomes;
    IncomesFile incomesFile;
    DatesManager datesManager;

    Finances enterNewIncomeData();
    int getNewIncomeId();

public:

    IncomeManager(string incomesFileName, int idOfLoggedInUser)
        : incomesFile(incomesFileName), ID_OF_LOGGED_IN_USER(idOfLoggedInUser)
    {
        incomes = incomesFile.loadIncomesOfLoggedInUserFromFile(ID_OF_LOGGED_IN_USER);
    };

    void addNewIncome();
    int getLoggedInUserId();// getter
    string convertAmount(string amount);
    vector <Finances> getIncomesOfLoggedInUser();

};

#endif
