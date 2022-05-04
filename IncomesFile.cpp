#include "IncomesFile.h"

void IncomesFile::addIncomeToFile(Income income)
{
    CMarkup xml;

    bool fileExsist = xml.Load("Incomes.xml" );

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
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", income.getAmount());

    xml.Save("Incomes.xml");
}
