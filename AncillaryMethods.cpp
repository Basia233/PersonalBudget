#include "AncillaryMethods.h"

string AncillaryMethods::intToStringConversion(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}


int AncillaryMethods::stringToIntConversion(string number)
{
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;

    return intNumber;
}


string AncillaryMethods::getSingleLine()
{
    string input = "";
    getline(cin, input);

    return input;
}


string AncillaryMethods::changeFirstLetterToCapitalAndOtherToLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}


string AncillaryMethods::getNumber(string text, int characterPosition)
{
    string number = "";
    while(isdigit(text[characterPosition]) == true)
    {
        number += text[characterPosition];
        characterPosition ++;
    }
    return number;
}


char AncillaryMethods::getCharacter()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}


string AncillaryMethods::convertDateFromIntToString(int number)
{
    string stringDate = intToStringConversion(number);
    stringDate.insert (4,"-");
    stringDate.insert(7,"-");

    return stringDate;
}


int AncillaryMethods::convertDateFromStringToInt(string stringDate)
{
    int intDate =  0;
    stringDate.erase (4,1);
    stringDate.erase(6,1);

    intDate = stringToIntConversion(stringDate);

    return intDate;
}

