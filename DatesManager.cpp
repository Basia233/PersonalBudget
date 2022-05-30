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


//data od 01.01.2000 do ostatniego dnia biezacego miesiaca
bool DatesManager::checkMinDate(string dateString)
{
    const int minDate = 20000101;
    int date = ancillaryMethods.convertDateFromStringToInt(dateString);

    if (date < minDate)
        return false;
    else
        return true;
}


bool DatesManager::checkMaxDate(string dateString)
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    int currentMonth = st.wMonth;
    int currentYear = st.wYear;
    int lastDayOfMonth = getNumberOfDaysOfMonth(currentMonth, currentYear);

    string year = ancillaryMethods.intToStringConversion(currentYear);
    string month = ancillaryMethods.intToStringConversion(currentMonth);
    string day = ancillaryMethods.intToStringConversion(lastDayOfMonth);

    if (currentMonth < 10)
    {
       month = "0" + month;
    }

    string maxDate = year + month + day;

    int dateToInt = ancillaryMethods.stringToIntConversion(maxDate);
    int enteredDate = ancillaryMethods.convertDateFromStringToInt(dateString);


    if (enteredDate > dateToInt)
        return false;
    else
        return true;
}


bool DatesManager::checkDate(string enteredDate)
{
    if ((checkMinDate(enteredDate) == 0) || (checkMaxDate(enteredDate) == 0))
        return false;
    else
        return true;
}


/*
bool DatesManager::checkDateFormat(string enteredDate)
{
    int date = ancillaryMethods.

    // do sprawdzenia format daty (czy sa zera + czy dobre miesiace czy dni od 1 do ostatniego dnia mesiaca)
}

*/

int DatesManager::getNumberOfDaysOfMonth(int month, int year)
{
   int numberOfDays =0;

   if (month == 4 || month == 6 || month == 9 || month == 11)
         numberOfDays = 30;

    else if (month == 2)
    {
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            numberOfDays = 29;
        else
           numberOfDays = 28;
    }
    else
        numberOfDays = 31;

   return numberOfDays;

}
