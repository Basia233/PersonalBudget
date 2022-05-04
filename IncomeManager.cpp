#include "IncomeManager.h"

using namespace std;


void IncomeManager::addNewIncome()
{
   Income income = enterNewIncomeData();

    incomes.push_back(income);

    incomesFile.addIncomeToFile(income);

    cout << endl << "Przychod zostal dodany" << endl << endl;
    system("pause");
}


Income IncomeManager::enterNewIncomeData()
{
   Income income;

    income.setUserId(ID_OF_LOGGED_IN_USER);

    income.setTransactionId(getNewIncomeId());// do przetestowania, tutaj chyba trzeba pobrac idostatniej transakcji i zwiekszyc o 1

    int date;
    string item;
    string amount;//lub float
    char choiceDate;


    cout << "Czy podany przychod dotyczy dnia dzisiejszego? Wybierz T/N: ";
    cin >> date;

   if (choiceDate == 'T')
   {

      // income.setDate(.getCurrentDate)
   }
   else
   {
       cout << "Podaj date w formacie rrrr-mm-dd: ";
       income.setDate(date);// wprowadz sprawdzanie daty
   }


    cout << "Podaj zrodlo przychodu: ";
    getline(cin, item);
    income.setItem(item);
    cout << "Podaj kwote przychodu: ";
    cin >> amount;
    income.setAmount(amount);

    return income;
}


int IncomeManager::getNewIncomeId()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getTransactionId() + 1;
}


int IncomeManager::getLoggedInUserId()
{
    return ID_OF_LOGGED_IN_USER;
}
