#include "IncomeManager.h"

using namespace std;


void IncomeManager::addNewIncome()
{
    Finances finances = enterNewIncomeData();

    incomes.push_back(finances);

    incomesFile.addIncomeToFile(finances);

    cout << endl << "Przychod zostal dodany" << endl << endl;
    system("pause");
}


Finances IncomeManager::enterNewIncomeData()
{
    Finances finances;

    finances.setUserId(ID_OF_LOGGED_IN_USER);

    finances.setTransactionId(incomesFile.getIdOfLastIncome() + 1);


    int date = 0;
    string dateString;
    string item;
    string amount;
    char choice;


    cout << "Czy podany przychod dotyczy dnia dzisiejszego? Wybierz t/n: ";
    cin >> choice;

    if (choice == 't')
    {
        finances.setDate(datesManager.getCurrentDate());
    }
    else
    {
        cout << "Podaj date w formacie rrrr-mm-dd: " << endl;
        cin.clear();
        cin.sync();

        dateString = AncillaryMethods::getSingleLine();

        while(datesManager.checkDate(dateString)==0)
        {
            cout << "Podana data jest nieprawidlowa." << endl;
            cout << "Podaj date od 2000-01-01 do ostatniego dnia biezacego miesiaca: ";
            cin >> dateString;
        }

        date = atoi(datesManager.addZeroToMonthAndDay(dateString).c_str());
        finances.setDate(date);
    }


    cin.clear();
    cin.sync();
    cout << "Podaj zrodlo przychodu: ";
    item = AncillaryMethods::getSingleLine();
    finances.setItem(item);


    cin.clear();
    cin.sync();
    cout << "Podaj kwote przychodu: ";
    amount = AncillaryMethods::getSingleLine();
    amount = convertAmount(amount);
    finances.setAmount(amount);

    return finances;
}


string IncomeManager::convertAmount(string amount)
{
    for (int i = 0; i < amount.length(); i++)
    {
        if (amount[i] == ',')
            amount[i] = '.';
    }

    return amount;
}


int IncomeManager::getLoggedInUserId()
{
    return ID_OF_LOGGED_IN_USER;
}


vector <Finances> IncomeManager::getIncomesOfLoggedInUser()
{
    return incomes;
}
