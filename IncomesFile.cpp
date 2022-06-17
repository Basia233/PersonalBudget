#include "IncomesFile.h"

void IncomesFile::addIncomeToFile(Finances finances)
{
    CMarkup xml;
    string date = datesManager.convertDateFromIntToString(finances.getDate());

    bool fileExsist = xml.Load("Incomes.xml");

    if(!fileExsist)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", finances.getTransactionId());
    xml.AddElem("UserID", finances.getUserId());
    xml.AddElem("Date", date);
    xml.AddElem("Item", finances.getItem());
    xml.AddElem("Amount", finances.getAmount());

    xml.Save("Incomes.xml");

    idOfLastIncome ++;

}


vector <Finances> IncomesFile::loadIncomesOfLoggedInUserFromFile(int idOfLoggedInUser)
{
    Finances finances;
    vector <Finances> incomes;
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
                finances.setUserId(atoi(xml.GetData().c_str()));
                xml.FindElem("IncomeId");
                finances.setTransactionId(atoi(xml.GetData().c_str()));
                xml.FindElem("Date");
                date = datesManager.convertDateFromStringToInt(xml.GetData());
                finances.setDate(date);
                xml.FindElem("Item");
                finances.setItem(xml.GetData());
                xml.FindElem("Amount");
                finances.setAmount(xml.GetData());

                incomes.push_back(finances);
            }

            xml.OutOfElem();
            idOfLastIncome++;
        }
    }

    return incomes;
}


int IncomesFile::getIdOfLastIncome()
{
    return idOfLastIncome;
}

