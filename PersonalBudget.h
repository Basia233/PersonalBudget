#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"
//#include "ExpenseManager.h"


using namespace std;

class PersonalBudget
{
    UserManager userManager;
    AncillaryMethods ancillaryMethods;
    IncomeManager *incomeManager;
   // ExpenseManager *expenseManager;
    const string INCOMES_FILENAME;
   // const string EXPENSES_FILENAME;

public:

   PersonalBudget(string usersFileName, string incomesFileName, string expensesFileName) :
        userManager(usersFileName), INCOMES_FILENAME(incomesFileName)//, EXPENSES_FILENAME(expenseFileName)
    {
        //incomesManager = NULL;
        //expenseManager = NULL; // ustawiamy wskaznik na null, aby od poczatu wskazywal na zero, a nie przypadkowe miejsce w pamieci
    };

    ~PersonalBudget()
    {
        //delete incomeManager;
        //incomeManager = NULL;

        //delete expenseManager;
        //expenseManager = NULL;
    }

    void userRegistration();
    void displayAllUsers();
    void userLogIn();
    int getLoggedInUserId();
    void changePasswordOfLoggedInUser();
    void logOut();
    //void wczytajUzytkownikowZPliku();


    bool isUserLoggedIn();

    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();


    void addNewIncome();
};

#endif
