#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "Finances.h"
#include "DatesManager.h"
#include "XMLFile.h"

using namespace std;

class IncomesFile : public XMLFile
{
    int idOfLastIncome;
    DatesManager datesManager;

public:
    IncomesFile(string incomesFileName): XMLFile(incomesFileName)
    {
        idOfLastIncome=0;
    };

    void addIncomeToFile(Finances finances);
    int getIdOfLastIncome();

    vector <Finances> loadIncomesOfLoggedInUserFromFile(int idOfLoggedInUser);

};

#endif
