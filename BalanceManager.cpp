#include "BalanceManager.h"


void BalanceManager::showBalanceForCurrentMonth(vector<Income> incomes, vector<Expense> expenses)
{
    int dateOfFirstDayOfCurrentMonth = datesManager.getDateOfFirstDayOfCurrentMonth();
    int dateOfLastDayOfCurrentMonth = datesManager.getDateOfLastDayOfCurrentMonth();
    vector<Income> incomesForCurrentMonth;
    vector<Expense> expensesForCurrentMonth;
    float totalIncomes, totalExpenses;

    system("cls");
    cout << ">>> BILANS Z BIEZACEGO MIESIACA <<<" << endl;
    cout << endl;


//PRZYCHODY

    for(int i = 0; i < incomes.size(); i++)
    {
        if(incomes[i].getDate() >= dateOfFirstDayOfCurrentMonth && incomes[i].getDate() <= dateOfLastDayOfCurrentMonth)
        {
            incomesForCurrentMonth.push_back(incomes[i]);
            totalIncomes += atof(incomes[i].getAmount().c_str());

        }
    }

    sort(incomesForCurrentMonth.begin(),incomesForCurrentMonth.end());

    cout << "Twoje PRZYCHODY w biezacym miesiacu: " << endl;
    cout << endl;

    for (int i = 0; i < incomesForCurrentMonth.size(); i++)
    {
        cout << "Data: " << ancillaryMethods.convertDateFromIntToString(incomesForCurrentMonth[i].getDate()) << endl;
        cout << "Opis: " << incomesForCurrentMonth[i].getItem() << endl;
        cout << "Kwota: " << incomesForCurrentMonth[i].getAmount() << endl;
        cout << endl;
    }


//WYDATKI

    for(int i = 0; i < expenses.size(); i++)
    {
        if(expenses[i].getDate() <= dateOfLastDayOfCurrentMonth && expenses[i].getDate() >= dateOfFirstDayOfCurrentMonth)
        {
            expensesForCurrentMonth.push_back(expenses[i]);
            totalExpenses += atof(expenses[i].getAmount().c_str());
        }
    }

    sort(expensesForCurrentMonth.begin(),expensesForCurrentMonth.end());

    cout << endl;
    cout << "Twoje WYDATKI w biezacym miesiacu: " << endl;
    cout << endl;

    for (int i = 0; i < expensesForCurrentMonth.size(); i++)
    {
        cout << "Data: " << ancillaryMethods.convertDateFromIntToString(expensesForCurrentMonth[i].getDate()) << endl;
        cout << "Opis: " << expensesForCurrentMonth[i].getItem() << endl;
        cout << "Kwota: " << expensesForCurrentMonth[i].getAmount() << endl;
        cout << endl;
    }


//BILANS
    cout << endl;
    cout << "PODSUMOWANIE:" << endl;
    cout << endl;

    cout << "Suma przychodow dla biezacego miesiaca: " << totalIncomes << " zl" << endl;
    cout << "Suma wydatkow dla biezacego miesiaca: " << totalExpenses << " zl" << endl;
    cout << "Bilans dla biezacego miesiaca: " << totalIncomes - totalExpenses << " zl" <<endl;

    system("pause");

}
