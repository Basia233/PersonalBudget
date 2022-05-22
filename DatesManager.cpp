#include "DatesManager.h"


int DatesManager::getCurrentDate()
{
    SYSTEMTIME st;
    GetLocalTime(&st);

    int day = st.wDay;
    int month = st.wMonth;
    int year = st.wYear;
    int currentIntegerDate = 0;

    string dayString;
    string monthString;
    string yearString;
    string currentDate = " ";


    dayString = ancillaryMethods.intToStringConversion(day);
    monthString = ancillaryMethods.intToStringConversion(month);
    yearString = ancillaryMethods.intToStringConversion(year);

    if (day < 10)
    {
        dayString = "0" + dayString;
    }
    if (month < 10 )
    {
       monthString = "0" + monthString;
    }

  // currentDate = yearString + "-" + monthString + "-" + dayString;

    currentDate = yearString + monthString + dayString;
    currentIntegerDate = atoi(currentDate.c_str());

 return currentIntegerDate;
}


