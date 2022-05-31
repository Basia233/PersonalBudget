#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector> //inkludujemy vector bo uzytkownicy beda zapisani w vectorze
#include <windows.h> // system pause
#include <fstream>
#include <sstream> // konwersja int na string

#include "Income.h"
#include "IncomesFile.h"
#include "DatesManager.h"
//#include "UserManager.h"
#include "AncillaryMethods.h"

using namespace std;

class IncomeManager
{
    const int ID_OF_LOGGED_IN_USER;
    vector <Income> incomes;
    IncomesFile incomesFile;
    DatesManager datesManager;

    AncillaryMethods ancillaryMethods;

    Income enterNewIncomeData();
    int getNewIncomeId();
    //bool doesLoginExist(string login);

public:

    IncomeManager(string incomesFileName, int idOfLoggedInUser)
    : incomesFile(incomesFileName), ID_OF_LOGGED_IN_USER(idOfLoggedInUser)
    {
      incomes = incomesFile.loadIncomesOfLoggedInUserFromFile(ID_OF_LOGGED_IN_USER);
    };

    void addNewIncome();
    int getLoggedInUserId();// getter
    string convertAmount(string amount);
    /*void displayAllUsers();
    void changePasswordOfLoggedInUser();
    void logOut();

    int userLogIn();
    void setIdOfLoggedInUser(int newIdOfLoggedInUser);//setter
    bool isUserLoggedIn();
    */

};

#endif
