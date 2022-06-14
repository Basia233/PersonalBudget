#include "BalanceManager.h"


void BalanceManager::showBalanceForCurrentMonth(vector <Income> incomes, vector <Expense> expenses)
{
    int dateOfFirstDayOfCurrentMonth = datesManager.getDateOfFirstDayOfCurrentMonth();
    int dateOfLastDayOfCurrentMonth = datesManager.getDateOfLastDayOfCurrentMonth();
    vector <Income> incomesForCurrentMonth;
    vector <Expense> expensesForCurrentMonth;

    system("cls");
    cout<< ">>> BILANS Z BIEZACEGO MIESIACA <<<" <<endl;
    cout<< endl;

    for(int i = 0; i < incomes.size(); i++)
    {
        if(incomes[i].getDate() >= dateOfFirstDayOfCurrentMonth && incomes[i].getDate() <= dateOfLastDayOfCurrentMonth)
        {
            incomesForCurrentMonth.push_back(incomes[i]);

        }
    }
    /*
        cout << "Twoje przychody w biezacym miesiacu to: " << endl;
        cout << endl;

        for (int i = 0; i < incomesForCurrentMonth.size(); i++)
        {
            cout << "Data: " << ancillaryMethods.convertDateFromIntToString(incomesForCurrentMonth[i].getDate()) << endl;
            cout << "Opis: " << incomesForCurrentMonth[i].getItem() << endl;
            cout << "Kwota: " << incomesForCurrentMonth[i].getAmount() << endl;
        }
        system("pause");*/

    for(int i = 0; i < expenses.size(); i++)
    {
        if(expenses[i].getDate() >= dateOfFirstDayOfCurrentMonth && expenses[i].getDate() <= dateOfLastDayOfCurrentMonth)
        {
            expensesForCurrentMonth.push_back(expenses[i]);
        }
    }

    /*
        cout << "Twoje wydatki w biezacym miesiacu to: " << endl;
        cout << endl;

        for (int i = 0; i < expensesForCurrentMonth.size(); i++)
        {
            cout << "Data: " << ancillaryMethods.convertDateFromIntToString(expensesForCurrentMonth[i].getDate()) << endl;
            cout << "Opis: " << expensesForCurrentMonth[i].getItem() << endl;
            cout << "Kwota: " << expensesForCurrentMonth[i].getAmount() << endl;
        }
        system("pause");*/


}
