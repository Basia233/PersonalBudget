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

   //int transactionId = getNewIncomeId();
   //income.setTransactionId(transactionId);
 income.setTransactionId(incomesFile.getIdOfLastIncome()+1);


    int date;
    string dateString;
    string item;
    string amount;//lub float
    char choice;


    cout << "Czy podany przychod dotyczy dnia dzisiejszego? Wybierz t/n: ";
    cin >> choice;

    if (choice == 't')
    {
        income.setDate(datesManager.getCurrentDate());
    }
    else
    {
        cout << "Podaj date w formacie rrrr-mm-dd: " << endl;
        cin.clear();
        cin.sync();
        dateString = ancillaryMethods.getSingleLine();
        date = ancillaryMethods.convertDateFromStringToInt(dateString);

        income.setDate(date);// wprowadz sprawdzanie daty
    }

    cin.clear();
    cin.sync();
    cout << "Podaj zrodlo przychodu: ";
    item = ancillaryMethods.getSingleLine();
    income.setItem(item);


    cin.clear();
    cin.sync();
    cout << "Podaj kwote przychodu: ";
    amount = ancillaryMethods.getSingleLine();
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
