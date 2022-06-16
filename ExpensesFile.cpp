#include "ExpensesFile.h"

void ExpensesFile::addExpenseToFile(Expense expense)
{
    CMarkup xml;
    string date = ancillaryMethods.convertDateFromIntToString(expense.getDate());

    bool fileExsist = xml.Load("Expenses.xml");

    if(!fileExsist)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses"); // tworzy galaz Expenses
    }

    xml.FindElem(); //wchodzi do kolejnego poziomu pliku xml
    xml.IntoElem(); // ustawia ten element jako glowny, mozna dodac cos wewnatrz
    xml.AddElem("Expense"); // dodaje element
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getTransactionId());
    xml.AddElem("UserID", expense.getUserId());
    xml.AddElem("Date", date);
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", expense.getAmount());

    xml.Save("Expenses.xml");

    idOfLastExpense++;

}


vector <Expense> ExpensesFile::loadExpensesOfLoggedInUserFromFile(int idOfLoggedInUser)
{
    Expense expense;
    vector <Expense> expenses;
    CMarkup xml;
    int userIdInFile, date;

    bool fileExsist = xml.Load("Expenses.xml");

    if(fileExsist)
    {
        xml.FindElem("Expenses");
        xml.IntoElem();

        while (xml.FindElem("Expense"))
        {
            xml.IntoElem();
            xml.FindElem("UserID");

            userIdInFile = atoi(xml.GetData().c_str());

            if (idOfLoggedInUser == userIdInFile)
            {
                expense.setUserId(atoi(xml.GetData().c_str()));
                xml.FindElem("ExpenseId");
                expense.setTransactionId(atoi(xml.GetData().c_str()));
                xml.FindElem("Date");
                date = ancillaryMethods.convertDateFromStringToInt(xml.GetData());
                expense.setDate(date);
                xml.FindElem("Item");
                expense.setItem(xml.GetData());
                xml.FindElem("Amount");
                expense.setAmount(xml.GetData());

                expenses.push_back(expense);
            }

            xml.OutOfElem();
            idOfLastExpense++;
        }
    }
    return expenses;
}


int ExpensesFile::getIdOfLastExpense()
{
    return idOfLastExpense;
}

