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
//DatesManager();

   int getCurrentDate();
   bool checkDate(string enteredDate);
   bool checkMinDate(string dateString);
   bool checkMaxDate(string dateString);
   bool isDateCorrect(string enteredDate);
   int getNumberOfDaysOfMonth(int month, int year);

};

#endif
