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

    currentDate = yearString + monthString + dayString;
    currentIntegerDate = atoi(currentDate.c_str());

    return currentIntegerDate;
}



bool DatesManager::checkMinDate(string enteredDate)
{
    const int minDate = 20000101;

    string dateString = addZeroToMonthAndDay(enteredDate);
    int date = atoi(dateString.c_str());

    if (date < minDate)
        return false;
    else
        return true;
}


bool DatesManager::checkMaxDate(string enteredDate)
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
    int maxDateInt = atoi(maxDate.c_str());

    string dateString = addZeroToMonthAndDay(enteredDate);
    int dateInt = atoi(dateString.c_str());


    if (dateInt > maxDateInt)
        return false;
    else
        return true;
}



bool DatesManager::checkNumberOfDaysAndMonth(string enteredDate)
{
    string yearString, monthString, dayString;

    stringstream dateString(enteredDate);
    getline(dateString, yearString, '-');
    getline(dateString, monthString, '-');
    getline(dateString, dayString, '-');

    int year = atoi(yearString.c_str());
    int month = atoi(monthString.c_str());
    int day = atoi(dayString.c_str());

    if(month < 1 || month > 12)
        return false;

    if(day < 1 || day > getNumberOfDaysOfMonth(month, year))
        return false;
}



string DatesManager::addZeroToMonthAndDay(string enteredDate)
{
    string yearString;
    string monthString;
    string dayString;

    stringstream dateString(enteredDate);
    getline(dateString, yearString, '-');
    getline(dateString, monthString, '-');
    getline(dateString, dayString, '-');

    int month = atoi(monthString.c_str());
    int day = atoi(dayString.c_str());

    if(month < 10 && monthString[0]!='0')
    {
        monthString = "0" + monthString;
    }

    if(day < 10 && dayString[0]!='0')
    {
        dayString = "0" + dayString;
    }

    string correctDateFormat = yearString + monthString + dayString;

    return correctDateFormat;
}



bool DatesManager::checkDate(string enteredDate)
{
    if ((checkMinDate(enteredDate) == 0) || (checkMaxDate(enteredDate) == 0) || (checkNumberOfDaysAndMonth(enteredDate) == 0))
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


int DatesManager::getDateOfFirstDayOfCurrentMonth()
{
    int currentDate = 0;
    string currentStringDate = "";
    string firstDayOfCurrentMonth = "";
    int dateOfFirstDayOfCurrentMonth = 0;


    currentDate = getCurrentDate();
    currentStringDate = ancillaryMethods.intToStringConversion(currentDate);

    firstDayOfCurrentMonth = currentStringDate.replace(6, 2, "01");

    dateOfFirstDayOfCurrentMonth = atoi(firstDayOfCurrentMonth.c_str());

    return dateOfFirstDayOfCurrentMonth;
}


int DatesManager::getDateOfLastDayOfCurrentMonth()
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

    string lastDayString = year + month + day;
    int dateOfLastDayOfMonth = atoi(lastDayString.c_str());

    return dateOfLastDayOfMonth;

}


int DatesManager::getDateOfFirstDayOfPreviousMonth()
{
   int dateOfLastDayOfPreviousMonth = 0;
   int dateOfFirstDayOfPreviousMonth = 0;
   string dateToString = "";
   string firstDayOfPreviousMonth = "";

    dateOfLastDayOfPreviousMonth = getDateOfLastDayOfPreviousMonth();
    dateToString = ancillaryMethods.intToStringConversion(dateOfLastDayOfPreviousMonth);

    firstDayOfPreviousMonth = dateToString.replace(6, 2, "01");
    dateOfFirstDayOfPreviousMonth = atoi(firstDayOfPreviousMonth.c_str());


    return dateOfFirstDayOfPreviousMonth;
}


int DatesManager::getDateOfLastDayOfPreviousMonth()
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    int currentMonth = st.wMonth;
    int currentYear = st.wYear;
    int previousMonth = 0;
    int previousYear = 0;
    int lastDayOfPreviousMonth = 0;
    string yearString = "";
    string previousMonthString = "";
    string lastDayOfPreviousMonthString = "";
    string previousMonthDateString = "";


    if (currentMonth == 1)
    {
        previousMonth = 12;
        previousYear = currentYear - 1;
        lastDayOfPreviousMonth = getNumberOfDaysOfMonth(previousMonth, previousYear);

        previousMonthDateString = ancillaryMethods.intToStringConversion(previousYear)
                                    + ancillaryMethods.intToStringConversion(previousMonth)
                                    + ancillaryMethods.intToStringConversion(lastDayOfPreviousMonth);
    }
    else
    {
        previousMonth = currentMonth - 1;
        previousMonthString = ancillaryMethods.intToStringConversion(previousMonth);
        lastDayOfPreviousMonth = getNumberOfDaysOfMonth(previousMonth, currentYear);

        if (previousMonth < 10)
        {
            previousMonthString = "0" + previousMonthString;
        }
        previousMonthDateString = ancillaryMethods.intToStringConversion(currentYear)
                                    + previousMonthString
                                    + ancillaryMethods.intToStringConversion(lastDayOfPreviousMonth);
    }

    int dateOfLastDayOfPreviousMonth = atoi(previousMonthDateString.c_str());

    return dateOfLastDayOfPreviousMonth;
}
