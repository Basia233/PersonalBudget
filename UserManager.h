#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector> //uzytkownicy zapisani w vectorze
#include <windows.h> // system pause
#include <fstream>
#include <sstream> // konwersja int na string

#include "User.h"
#include "UsersFile.h"
#include "AncillaryMethods.h"

using namespace std;

class UserManager
{
    int idOfLoggedInUser;
    vector <User> users;
    UsersFile usersFile;

    User provideNewUserData();
    int getNewUserId();
    bool doesLoginExist(string login);

public:

    UserManager(string usersFileName): usersFile(usersFileName)
    {
        idOfLoggedInUser = 0;
        users = usersFile.loadUsersFromFile();
    };

    void userRegistration();
    void displayAllUsers();
    void changePasswordOfLoggedInUser();
    void logOut();

    int userLogIn();
    void setIdOfLoggedInUser(int newIdOfLoggedInUser);//setter
    int getLoggedInUserId();//getter
    bool isUserLoggedIn();


};

#endif
