#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "BalanceManager.h"


using namespace std;

class PersonalBudget
{
    UserManager userManager;
    AncillaryMethods ancillaryMethods;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;
    BalanceManager *balanceManager;
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;

public:

    PersonalBudget(string usersFileName, string incomesFileName, string expensesFileName) :
        userManager(usersFileName), INCOMES_FILENAME(incomesFileName), EXPENSES_FILENAME(expensesFileName)
    {
        incomeManager = NULL;
        expenseManager = NULL;
    };

    ~PersonalBudget()
    {
        delete incomeManager;
        incomeManager = NULL;

        delete expenseManager;
        expenseManager = NULL;
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
    void addNewExpense();
    //void displayAllIncomes();
    //void displayAllExpenses();
    void showBalanceForCurrentMonth();
    void showBalanceForPreviousMonth();

};

#endif
