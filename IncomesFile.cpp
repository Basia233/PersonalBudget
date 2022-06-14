#include "IncomesFile.h"

void IncomesFile::addIncomeToFile(Income income)
{
    CMarkup xml;
    string date = ancillaryMethods.convertDateFromIntToString(income.getDate());

    bool fileExsist = xml.Load("Incomes.xml");

    if(!fileExsist)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem( "Incomes" ); // tworzy galaz Incomes
    }

    xml.FindElem(); //wchodzi do kolejnego poziomu pliku xml
    xml.IntoElem(); // ustawia ten element jako glowny, mozna dodac cos wewnatrz
    xml.AddElem("Income"); // dodaje element
    xml.IntoElem();
    xml.AddElem("UserID", income.getUserId());
    xml.AddElem("IncomeId", income.getTransactionId());
    xml.AddElem("Date", date);
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", income.getAmount());

    xml.Save("Incomes.xml");

}


vector <Income> IncomesFile::loadIncomesOfLoggedInUserFromFile(int idOfLoggedInUser)
{
    Income income;
    vector <Income> incomes;
    CMarkup xml;
    int userIdInFile, date;

    bool fileExsist = xml.Load("Incomes.xml");

    if(fileExsist)
    {
        xml.FindElem("Incomes");
        xml.IntoElem();

        while (xml.FindElem("Income"))
        {
            xml.IntoElem();
            xml.FindElem("UserID");

            userIdInFile = atoi(xml.GetData().c_str());

            if (idOfLoggedInUser == userIdInFile)
            {
                income.setUserId(atoi(xml.GetData().c_str()));
                xml.FindElem("IncomeId");
                income.setTransactionId(atoi(xml.GetData().c_str()));
                xml.FindElem("Date");
                date = ancillaryMethods.convertDateFromStringToInt(xml.GetData());
                income.setDate(date);
                xml.FindElem("Item");
                income.setItem(xml.GetData());
                xml.FindElem("Amount");
                income.setAmount(xml.GetData());

                incomes.push_back(income);
            }
            xml.OutOfElem();
        }
    }
    return incomes;
}


int IncomesFile::getIdOfLastIncome()
{
    return idOfLastIncome;
}

