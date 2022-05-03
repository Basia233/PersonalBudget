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
    IncomeManager incomeManager;
   // ExpenseManager expenseManager;
   // const string NAZWA_PLIKU_Z_ADRESATAMI;

public:

   PersonalBudget(string usersFileName, string incomesFileName) :
        userManager(usersFileName), incomeManager(incomesFileName)
    {
        //adresatMenadzer = NULL; // ustawiamy wskaznik na null, aby od poczatu wskazywal na zero, a nie przypadkowe miejsce w pamieci
    };

    ~PersonalBudget()
    {
        //delete adresatMenadzer;
        //adresatMenadzer = NULL;
    }87

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
