#ifndef ANCILLARYMETHODS_H
#define ANCILLARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>


using namespace std;

class AncillaryMethods
{

public:
    static string intToStringConversion(int number);
    static int stringToIntConversion(string number);
    string getSingleLine();
    string changeFirstLetterToCapitalAndOtherToLowercase(string text);
    char getCharacter();
    string convertDateFromIntToString(int number);
    int convertDateFromStringToInt(string stringDate);

};

#endif
