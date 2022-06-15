#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector> //inkludujemy vector bo uzytkownicy beda zapisani w vectorze
#include <windows.h> // system pause
#include <fstream>
#include <sstream> // konwersja int na string

#include "Expense.h"
#include "ExpensesFile.h"
#include "DatesManager.h"
#include "AncillaryMethods.h"

using namespace std;

class ExpenseManager
{
    const int ID_OF_LOGGED_IN_USER;
    vector <Expense> expenses;
    ExpensesFile expensesFile;
    DatesManager datesManager;
    AncillaryMethods ancillaryMethods;

    Expense enterNewExpenseData();
    int getNewExpenseId();

public:

    ExpenseManager(string expensesFileName, int idOfLoggedInUser)
        : expensesFile(expensesFileName), ID_OF_LOGGED_IN_USER(idOfLoggedInUser)
    {
        expenses = expensesFile.loadExpensesOfLoggedInUserFromFile(ID_OF_LOGGED_IN_USER);
    };

    void addNewExpense();
    int getLoggedInUserId();
    string convertAmount(string amount);
    vector <Expense> getExpensesOfLoggedInUser();


};

#endif
