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
    static string getSingleLine();
    static string changeFirstLetterToCapitalAndOtherToLowercase(string text);
    static char getCharacter();
};

#endif
