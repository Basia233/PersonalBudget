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

    int transactionId = getNewIncomeId();
    income.setTransactionId(transactionId);
    //income.setTransactionId(incomesFile.getIdOfLastIncome()+1);


    int date = 0;
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

        while(datesManager.checkDate(dateString)==0)
        {
            cout << "Podana data jest poza zakresem." << endl;
            cout << "Podaj date od 2000-01-01 do ostatniego dnia biezacego miesiaca: ";
            cin >> dateString;
        }

        date = atoi(datesManager.addZeroToMonthAndDay(dateString).c_str());
        income.setDate(date);
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
    amount = convertAmount(amount);
    income.setAmount(amount);

    return income;
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


void IncomeManager::displayAllIncomes()
{
    for (int i=0; i<incomes.size(); i++)
    {
        cout << incomes[i].getUserId() << endl;
        cout << incomes[i].getTransactionId() << endl;
        cout << incomes[i].getDate() << endl;
        cout << incomes[i].getItem() << endl;
        cout << incomes[i].getAmount() << endl;
    }
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


vector <Income> IncomeManager::getIncomesOfLoggedInUser()
{
    return incomes;
}
