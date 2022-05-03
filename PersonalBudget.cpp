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
    userManager.getLoggedInUserId();
    //if (userManager.czyUzytkownikJestZalogowany())
    //{
       // adresatMenadzer = new AdresatMenadzer(NAZWA_PLIKU_Z_ADRESATAMI, userManager.pobierzIdZalogowanegoUzytkownika());
    //}
}


void PersonalBudget::changePasswordOfLoggedInUser()
{
    userManager.changePasswordOfLoggedInUser();
}


void PersonalBudget::logOut()
{
    userManager.logOut();
   // delete adresatMenadzer;
    //adresatMenadzer = NULL;
}


bool PersonalBudget::isUserLoggedIn()
{
    userManager.isUserLoggedIn();
}

void PersonalBudget::addNewIncome()
{
    incomeManager.addNewIncome();
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

