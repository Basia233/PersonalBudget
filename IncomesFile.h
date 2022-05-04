#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "Income.h"
//#include "AncillaryMethods.h"
#include "XMLFile.h"

using namespace std;

class IncomesFile : public XMLFile
{
   int idOfLastIncome = 0;

public:
    IncomesFile(string incomesFileName): XMLFile(incomesFileName)
    {
        idOfLastIncome=0;
    };

  void addIncomeToFile(Income income);

    vector <Income> loadIncomesOfLoggedInUserFromFile(int idOfLoggedInUser);
    /*vector <User> changePasswordOfLoggedInUser(int idOfLoggedInUser, vector <User> users);
    void changePasswordInFile(int idOfLoggedInUser, string newPassword);
*/
};

#endif
