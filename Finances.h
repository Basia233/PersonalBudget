#ifndef FINANCES_H
#define FINANCES_H

#include <iostream>

using namespace std;

class Finances
{
    int transactionId;
    int userId;
    int date;
    string item;
    string amount;//lub float

public:
    void setTransactionId(int newTransactionId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);// lub float

    int getTransactionId();
    int getUserId();
    int getDate();
    string getItem();
    string getAmount(); // lub float
};

#endif
