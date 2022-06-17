#include "ExpensesFile.h"

void ExpensesFile::addExpenseToFile(Finances finances)
{
    CMarkup xml;
    string date = datesManager.convertDateFromIntToString(finances.getDate());

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
    xml.AddElem("ExpenseId", finances.getTransactionId());
    xml.AddElem("UserID", finances.getUserId());
    xml.AddElem("Date", date);
    xml.AddElem("Item", finances.getItem());
    xml.AddElem("Amount", finances.getAmount());

    xml.Save("Expenses.xml");

    idOfLastExpense++;

}


vector <Finances> ExpensesFile::loadExpensesOfLoggedInUserFromFile(int idOfLoggedInUser)
{
    Finances finances;
    vector <Finances> expenses;
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
                finances.setUserId(atoi(xml.GetData().c_str()));
                xml.FindElem("ExpenseId");
                finances.setTransactionId(atoi(xml.GetData().c_str()));
                xml.FindElem("Date");
                date = datesManager.convertDateFromStringToInt(xml.GetData());
                finances.setDate(date);
                xml.FindElem("Item");
                finances.setItem(xml.GetData());
                xml.FindElem("Amount");
                finances.setAmount(xml.GetData());

                expenses.push_back(finances);
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

