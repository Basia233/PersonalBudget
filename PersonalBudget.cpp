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
   // userManager.getLoggedInUserId();

    if (userManager.isUserLoggedIn())
    {
        incomeManager = new IncomeManager(INCOMES_FILENAME, userManager.getLoggedInUserId());
        //expenseManager = new ExpenseManager(EXPENSES_FILENAME, userManager.getLoggedInUserId());
    }
}


void PersonalBudget::changePasswordOfLoggedInUser()
{
    userManager.changePasswordOfLoggedInUser();
}


void PersonalBudget::logOut()
{
    userManager.logOut();

    //delete incomeManager;
    //incomeManager = NULL;

    //delete expenseManager;
    //expenseManager = NULL;
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

