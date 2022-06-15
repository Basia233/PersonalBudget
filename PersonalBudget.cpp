#include "PersonalBudget.h"


void PersonalBudget::userRegistration()
{
    userManager.userRegistration();
}


void PersonalBudget::displayAllUsers()
{
    userManager.displayAllUsers();
}


void PersonalBudget::userLogIn()
{
    userManager.userLogIn();

    if (userManager.isUserLoggedIn())
    {
        incomeManager = new IncomeManager(INCOMES_FILENAME, userManager.getLoggedInUserId());
        expenseManager = new ExpenseManager(EXPENSES_FILENAME, userManager.getLoggedInUserId());
        balanceManager = new BalanceManager();
    }
}


void PersonalBudget::changePasswordOfLoggedInUser()
{
    userManager.changePasswordOfLoggedInUser();
}


void PersonalBudget::logOut()
{
    userManager.logOut();

    delete incomeManager;
    incomeManager = NULL;

    delete expenseManager;
    expenseManager = NULL;

    delete balanceManager;
    balanceManager = NULL;
}


bool PersonalBudget::isUserLoggedIn()
{
    userManager.isUserLoggedIn();
}


void PersonalBudget::addNewIncome()
{
    if(userManager.isUserLoggedIn())
    {
        incomeManager -> addNewIncome();
    }
    else
        cout << "Aby dodac przychod nalezy sie najpierw zalogowac";

    system("pause");

}


void PersonalBudget::addNewExpense()
{
    if(userManager.isUserLoggedIn())
    {
        expenseManager -> addNewExpense();
    }
    else
        cout << "Aby dodac wydatek nalezy sie najpierw zalogowac";

    system("pause");

}


char PersonalBudget::selectOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    choice = ancillaryMethods.getCharacter();

    return choice;
}


char PersonalBudget::selectOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    choice = ancillaryMethods.getCharacter();

    return choice;
}

/*
void PersonalBudget::displayAllIncomes()
{
    if(userManager.isUserLoggedIn())
    {
        incomeManager -> displayAllIncomes();
    }
}


void PersonalBudget::displayAllExpenses()
{
    if(userManager.isUserLoggedIn())
    {
        expenseManager -> displayAllExpenses();
    }
}
*/

void PersonalBudget::showBalanceForCurrentMonth()
{
    if(userManager.isUserLoggedIn())
    {
        balanceManager -> showBalanceForCurrentMonth(incomeManager -> getIncomesOfLoggedInUser(), expenseManager -> getExpensesOfLoggedInUser());
    }
}


void PersonalBudget::showBalanceForPreviousMonth()
{
    if(userManager.isUserLoggedIn())
    {
        balanceManager -> showBalanceForPreviousMonth(incomeManager -> getIncomesOfLoggedInUser(), expenseManager -> getExpensesOfLoggedInUser());
    }
}


void PersonalBudget::showBalanceForSelectedPeriod()
{
    if(userManager.isUserLoggedIn())
    {
        balanceManager -> showBalanceForSelectedPeriod(incomeManager -> getIncomesOfLoggedInUser(), expenseManager -> getExpensesOfLoggedInUser());
    }
}
