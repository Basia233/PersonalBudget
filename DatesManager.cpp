#include "DatesManager.h"


int DatesManager::getCurrentDate()
{
    SYSTEMTIME st;
    GetLocalTime(&st);

    int day = st.wDay;
    int month = st.wMonth;
    int year = st.wYear;
    int currentIntegerDate = 0;
    //cout << day << endl;
    //cout << month << endl;
    //cout << year << endl;

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

    currentDate = yearString + monthString + dayString;
    currentIntegerDate = atoi(currentDate.c_str());
   // cout << currentIntegerDate;

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

/*
bool DatesManager::isDateCorrect(string enteredDate)
{
   // string yearString = enteredDate.substr(0,4);
    //string monthString = enteredDate.substr(5,2);
    //string dayString = enteredDate.substr(8,2);
    string yearString;
    string monthString;
    string dayString;

    stringstream dateString(enteredDate);
    getline(dateString, yearString, '-');
    getline(dateString, monthString, '-');
    getline(dateString, dayString, '-');

    int year = atoi(yearString.c_str());
    int month = atoi(monthString.c_str());
    int day = atoi(dayString.c_str());

    if(month < 10 && monthString[0]!='0')
    {
        monthString.insert(0,"0");

    }


    if(day < 10 && dayString[0]!='0')
    {
        dayString.insert(0,"0");

    }

    if(month < 1 || month > 12)
        return false;

    if(day < 1 || day > getNumberOfDaysOfMonth(month, year))
        return false;

    return true;
}
*/

bool DatesManager::checkDate(string enteredDate)
{
    if ((checkMinDate(enteredDate) == 0) || (checkMaxDate(enteredDate) == 0))
        return false;
    else
        return true;
}


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
