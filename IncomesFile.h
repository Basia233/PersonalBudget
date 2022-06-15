#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "Income.h"
#include "AncillaryMethods.h"
#include "XMLFile.h"

using namespace std;

class IncomesFile : public XMLFile
{
    int idOfLastIncome;
    AncillaryMethods ancillaryMethods;

public:
    IncomesFile(string incomesFileName): XMLFile(incomesFileName)
    {
        idOfLastIncome=0;
    };

    void addIncomeToFile(Income income);
    int getIdOfLastIncome();

    vector <Income> loadIncomesOfLoggedInUserFromFile(int idOfLoggedInUser);

};

#endif
