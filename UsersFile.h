#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Markup.h"
#include "User.h"
#include "AncillaryMethods.h"
#include "XMLFile.h"

using namespace std;

class UsersFile : public XMLFile
{
    const string FILENAME;

public:
    UsersFile(string usersFileName): XMLFile(usersFileName) {};

    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    vector <User> changePasswordOfLoggedInUser(int idOfLoggedInUser, vector <User> users);
    void changePasswordInFile(int idOfLoggedInUser, string newPassword);

};

#endif
