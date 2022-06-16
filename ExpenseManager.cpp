#include "ExpenseManager.h"

using namespace std;


void ExpenseManager::addNewExpense()
{
    Expense expense = enterNewExpenseData();

    expenses.push_back(expense);

    expensesFile.addExpenseToFile(expense);

    cout << endl << "Wydatek zostal dodany" << endl << endl;
    system("pause");
}


Expense ExpenseManager::enterNewExpenseData()
{
    Expense expense;

    expense.setUserId(ID_OF_LOGGED_IN_USER);

    expense.setTransactionId(expensesFile.getIdOfLastExpense() + 1);


    int date = 0;
    string dateString;
    string item;
    string amount;
    char choice;


    cout << "Czy podany wydatek dotyczy dnia dzisiejszego? Wybierz t/n: ";
    cin >> choice;

    if (choice == 't')
    {
        expense.setDate(datesManager.getCurrentDate());
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
        expense.setDate(date);
    }


    cin.clear();
    cin.sync();
    cout << "Podaj powod wydatku: ";
    item = AncillaryMethods::getSingleLine();
    expense.setItem(item);


    cin.clear();
    cin.sync();
    cout << "Podaj kwote wydatku: ";
    amount = AncillaryMethods::getSingleLine();
    amount = convertAmount(amount);
    expense.setAmount(amount);

    return expense;
}


string ExpenseManager::convertAmount(string amount)
{
    for (int i = 0; i < amount.length(); i++)
    {
        if (amount[i] == ',')
            amount[i] = '.';
    }

    return amount;
}


int ExpenseManager::getLoggedInUserId()
{
    return ID_OF_LOGGED_IN_USER;
}


vector <Expense> ExpenseManager::getExpensesOfLoggedInUser()
{
    return expenses;
}
