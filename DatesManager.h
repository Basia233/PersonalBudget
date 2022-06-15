#ifndef DATESMANAGER_H
#define DATESMANAGER_H

#include <iostream>
#include <fstream>
#include <windows.h> //SYSTEMTIME st
#include <winbase.h> //SYSTEMTIME st
#include "AncillaryMethods.h"

using namespace std;

class DatesManager
{

    AncillaryMethods ancillaryMethods;

public:

    int getCurrentDate();
    bool checkDate(string enteredDate);
    bool checkMinDate(string enteredDate);
    bool checkMaxDate(string enteredDate);
    bool checkNumberOfDaysAndMonth(string enteredDate);
    string addZeroToMonthAndDay(string enteredDate);
    int getNumberOfDaysOfMonth(int month, int year);
    int getDateOfFirstDayOfCurrentMonth();
    int getDateOfLastDayOfCurrentMonth();
    int getDateOfFirstDayOfPreviousMonth();
    int getDateOfLastDayOfPreviousMonth();

};

#endif
