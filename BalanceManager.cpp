#include "BalanceManager.h"


//BIEZ¥CY MIESI¥C
void BalanceManager::showBalanceForCurrentMonth(vector <Finances> incomes, vector <Finances> expenses)
{
    int dateOfFirstDayOfCurrentMonth = datesManager.getDateOfFirstDayOfCurrentMonth();
    int dateOfLastDayOfCurrentMonth = datesManager.getDateOfLastDayOfCurrentMonth();
    vector <Finances> incomesForCurrentMonth;
    vector <Finances> expensesForCurrentMonth;
    float totalIncomes = 0, totalExpenses= 0;

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

    sort(incomesForCurrentMonth.begin(), incomesForCurrentMonth.end());

    cout << "Twoje PRZYCHODY w biezacym miesiacu: " << endl;
    cout << endl;


    if (incomesForCurrentMonth.empty() == true)
        cout << "Brak przychodow w tym okresie. " << endl;
    else
    {
        for (int i = 0; i < incomesForCurrentMonth.size(); i++)
        {
            cout << "Data: " << datesManager.convertDateFromIntToString(incomesForCurrentMonth[i].getDate()) << endl;
            cout << "Opis: " << incomesForCurrentMonth[i].getItem() << endl;
            cout << "Kwota: " << fixed << setprecision(2) << atof(incomesForCurrentMonth[i].getAmount().c_str()) << endl;
            cout << endl;
        }
    }


//WYDATKI
    for(int i = 0; i < expenses.size(); i++)
    {
        if(expenses[i].getDate() >= dateOfFirstDayOfCurrentMonth && expenses[i].getDate() <= dateOfLastDayOfCurrentMonth)
        {
            expensesForCurrentMonth.push_back(expenses[i]);
            totalExpenses += atof(expenses[i].getAmount().c_str());
        }
    }

    sort(expensesForCurrentMonth.begin(), expensesForCurrentMonth.end());

    cout << endl;
    cout << "Twoje WYDATKI w biezacym miesiacu: " << endl;
    cout << endl;


    if (expensesForCurrentMonth.empty() == true)
        cout << "Brak wydatkow w tym okresie. " << endl;
    else
    {
        for (int i = 0; i < expensesForCurrentMonth.size(); i++)
        {
            cout << "Data: " << datesManager.convertDateFromIntToString(expensesForCurrentMonth[i].getDate()) << endl;
            cout << "Opis: " << expensesForCurrentMonth[i].getItem() << endl;
            cout << "Kwota: " << fixed << setprecision(2) << atof(expensesForCurrentMonth[i].getAmount().c_str()) << endl;
            cout << endl;
        }
    }


//BILANS
    cout << endl;
    cout << "PODSUMOWANIE:" << endl;
    cout << endl;

    cout << "Suma przychodow w biezacym miesiacu: " << fixed << setprecision(2) << totalIncomes << " zl" << endl;
    cout << "Suma wydatkow w biezacym miesiacu: " << fixed << setprecision(2) << totalExpenses << " zl" << endl;
    cout << "Bilans dla biezacego miesiaca: " << fixed << setprecision(2) << totalIncomes - totalExpenses << " zl" <<endl;

    system("pause");

}


//POPRZEDNI MIESI¥C
void BalanceManager::showBalanceForPreviousMonth(vector <Finances> incomes, vector <Finances> expenses)
{
    int dateOfFirstDayOfPreviousMonth = datesManager.getDateOfFirstDayOfPreviousMonth();
    int dateOfLastDayOfPreviousMonth = datesManager.getDateOfLastDayOfPreviousMonth();
    vector <Finances> incomesForPreviousMonth;
    vector <Finances> expensesForPreviousMonth;
    float totalIncomes = 0, totalExpenses = 0;

    system("cls");
    cout << ">>> BILANS Z POPRZEDNIEGO MIESIACA <<<" << endl;
    cout << endl;


//PRZYCHODY
    for(int i = 0; i < incomes.size(); i++)
    {
        if(incomes[i].getDate() >= dateOfFirstDayOfPreviousMonth && incomes[i].getDate() <= dateOfLastDayOfPreviousMonth)
        {
            incomesForPreviousMonth.push_back(incomes[i]);
            totalIncomes += atof(incomes[i].getAmount().c_str());

        }
    }

    sort(incomesForPreviousMonth.begin(),incomesForPreviousMonth.end());
    cout << "Twoje PRZYCHODY w poprzednim miesiacu: " << endl;
    cout << endl;


    if (incomesForPreviousMonth.empty() == true)
        cout << "Brak przychodow w tym okresie. " << endl;
    else
    {
        for (int i = 0; i < incomesForPreviousMonth.size(); i++)
        {
            cout << "Data: " << datesManager.convertDateFromIntToString(incomesForPreviousMonth[i].getDate()) << endl;
            cout << "Opis: " << incomesForPreviousMonth[i].getItem() << endl;
            cout << "Kwota: " << fixed << setprecision(2) << atof(incomesForPreviousMonth[i].getAmount().c_str()) << endl;
            cout << endl;
        }
    }


//WYDATKI
    for(int i = 0; i < expenses.size(); i++)
    {
        if(expenses[i].getDate() >= dateOfFirstDayOfPreviousMonth && expenses[i].getDate() <= dateOfLastDayOfPreviousMonth)
        {
            expensesForPreviousMonth.push_back(expenses[i]
            totalExpenses += atof(expenses[i].getAmount().c_str());
        }
    }
    sort(expensesForPreviousMonth.begin(),expensesForPreviousMonth.end());

    cout << endl;
    cout << "Twoje WYDATKI w poprzednim miesiacu: " << endl;
    cout << endl;


    if (expensesForPreviousMonth.empty() == true)
        cout << "Brak wydatkow w tym okresie. " << endl;
    else
    {
        for (int i = 0; i < expensesForPreviousMonth.size(); i++)
        {
            cout << "Data: " << datesManager.convertDateFromIntToString(expensesForPreviousMonth[i].getDate()) << endl;
            cout << "Opis: " << expensesForPreviousMonth[i].getItem() << endl;
            cout << "Kwota: " << fixed << setprecision(2) << atof(expensesForPreviousMonth[i].getAmount().c_str()) << endl;
            cout << endl;
        }
    }


//BILANS
        cout << endl;
        cout << "PODSUMOWANIE:" << endl;
        cout << endl;

        cout << "Suma przychodow w poprzednim miesiacu: " << fixed << setprecision(2) << totalIncomes << " zl" << endl;
        cout << "Suma wydatkow w poprzednim miesiacu: " << fixed << setprecision(2) << totalExpenses << " zl" << endl;
        cout << "Bilans dla poprzedniego miesiaca: " << fixed << setprecision(2) << totalIncomes - totalExpenses << " zl" <<endl;

    system("pause");

}


//WYBRANY PRZEDZIA£ CZASOWY
void BalanceManager::showBalanceForSelectedPeriod(vector <Finances> incomes, vector <Finances> expenses)
{
    int dateFrom = 0, dateTo = 0;
    string dateFromString = "", dateToString = "";
    vector <Finances> incomesForSelectedPeriod;
    vector <Finances> expensesForSelectedPeriod;
    float totalIncomes = 0, totalExpenses = 0;

    system("cls");
    cout << ">>> BILANS DLA WYBRANEGO OKRESU <<<" << endl;
    cout << endl;

// data OD:
    do
    {
        cout << "Podaj date, od ktorej chcesz wyswietlic dane o finansach (rrrr-mm-dd): " << endl;

        getline(cin, dateFromString);


        while(datesManager.checkDate(dateFromString)==0)
        {
            cout << "Podana data jest niepoprawna." << endl;
            cout << "Podaj date od 2000-01-01: ";
            getline(cin, dateFromString);
        }

        dateFrom = atoi(datesManager.addZeroToMonthAndDay(dateFromString).c_str());


// data DO:
        cout << "Podaj date, do ktorej chcesz wyswietlic dane o finansach (rrrr-mm-dd): " << endl;

        getline(cin, dateToString);


        while(datesManager.checkDate(dateToString)==0)
        {
            cout << "Podana data jest niepoprawna." << endl;
            cout << "Podaj date do ostatniego dnia biezacego miesiaca: ";
            getline(cin, dateToString);
        }

        dateTo = atoi(datesManager.addZeroToMonthAndDay(dateToString).c_str());

        if (dateTo < dateFrom)
        {
            cout << endl;
            cout << "Data koncowa powinna byc pozniejsza niz data poczatkowa. Wprowadz date jeszcze raz. " << endl;
            cout << endl;
        }

    }
    while (dateFrom > dateTo);





//PRZYCHODY
    for(int i = 0; i < incomes.size(); i++)
    {
        if(incomes[i].getDate() >= dateFrom && incomes[i].getDate() <= dateTo)
        {
            incomesForSelectedPeriod.push_back(incomes[i]);
            totalIncomes += atof(incomes[i].getAmount().c_str());

        }
    }
    sort(incomesForSelectedPeriod.begin(), incomesForSelectedPeriod.end());

    cout << endl;
    cout << "Twoje PRZYCHODY w wybranym okresie: " << endl;
    cout << endl;



    if (incomesForSelectedPeriod.empty() == true)
        cout << "Brak przychodow w tym okresie. " << endl;
    else
    {

        for (int i = 0; i < incomesForSelectedPeriod.size(); i++)
        {
            cout << "Data: " << datesManager.convertDateFromIntToString(incomesForSelectedPeriod[i].getDate()) << endl;
            cout << "Opis: " << incomesForSelectedPeriod[i].getItem() << endl;
            cout << "Kwota: " << fixed << setprecision(2) << atof(incomesForSelectedPeriod[i].getAmount().c_str()) << endl;
            cout << endl;
        }
    }


//WYDATKI
    for(int i = 0; i < expenses.size(); i++)
    {
        if(expenses[i].getDate() >= dateFrom && expenses[i].getDate() <= dateTo)
        {
            expensesForSelectedPeriod.push_back(expenses[i]);
            totalExpenses += atof(expenses[i].getAmount().c_str());
        }
    }

    sort(expensesForSelectedPeriod.begin(), expensesForSelectedPeriod.end());

    cout << endl;
    cout << "Twoje WYDATKI w wybranym okresie: " << endl;
    cout << endl;


    if (expensesForSelectedPeriod.empty() == true)
    {
        cout << "Brak wydatkow w tym okresie. " << endl;
        cout << endl;
    }
    else
    {
        for (int i = 0; i < expensesForSelectedPeriod.size(); i++)
        {
            cout << "Data: " << datesManager.convertDateFromIntToString(expensesForSelectedPeriod[i].getDate()) << endl;
            cout << "Opis: " << expensesForSelectedPeriod[i].getItem() << endl;
            cout << "Kwota: " << fixed << setprecision(2) << atof(expensesForSelectedPeriod[i].getAmount().c_str()) << endl;
            cout << endl;
        }
    }

//BILANS

        cout << endl;
        cout << "PODSUMOWANIE:" << endl;
        cout << endl;

        cout << "Suma przychodow w okresie od " << dateFromString << " do " << dateToString << " wynosi: " << fixed << setprecision(2) << totalIncomes << " zl" << endl;
        cout << "Suma wydatkow w okresie od " << dateFromString << " do " << dateToString << " wynosi: " << fixed << setprecision(2) << totalExpenses << " zl" << endl;
        cout << "Bilans dla wybranego okresu: " << fixed << setprecision(2) << totalIncomes - totalExpenses << " zl" <<endl;

    system("pause");

}

