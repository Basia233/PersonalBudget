#include "UserManager.h"

using namespace std;


void UserManager::userRegistration()
{
    User user = provideNewUserData();

    users.push_back(user);

    usersFile.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}


User UserManager::provideNewUserData()
{
    User user;

    user.setId(getNewUserId());
    string login;
    string password;
    string name;
    string surname;

    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    }
    while (doesLoginExist(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);
    cout << "Podaj imie: ";
    cin >> name;
    name = ancillaryMethods.changeFirstLetterToCapitalAndOtherToLowercase(name);
    user.setName(name);
    cout << "Podaj nazwisko: ";
    cin >> surname;
    surname = ancillaryMethods.changeFirstLetterToCapitalAndOtherToLowercase(surname);
    user.setSurname(surname);

    return user;
}


int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}


bool UserManager::doesLoginExist(string login)
{
    for (int i =0; i<users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}


void UserManager::displayAllUsers()
{
    for (int i=0; i<users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
    }
}


int UserManager::userLogIn()
{
    User user;
    string login = "", password = "";

    cout << "Podaj login: ";
    login = ancillaryMethods.getSingleLine();

    int i=0;

    while (i<users.size())
    {
        if (users[i].getLogin() == login)
        {
            for (int numberOfTrial = 3; numberOfTrial > 0; numberOfTrial--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfTrial << ": ";
                password = ancillaryMethods.getSingleLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");

                    idOfLoggedInUser = users[i].getId();

                    return idOfLoggedInUser;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        i++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}


void UserManager::changePasswordOfLoggedInUser()
{
    users = usersFile.changePasswordOfLoggedInUser(idOfLoggedInUser, users);
}


void UserManager::logOut()
{
    idOfLoggedInUser = 0;
}


void UserManager::setIdOfLoggedInUser(int newIdOfLoggedInUser)
{
    idOfLoggedInUser = newIdOfLoggedInUser;
}


int UserManager::getLoggedInUserId()
{
    return idOfLoggedInUser;
}


bool UserManager::isUserLoggedIn()
{
    if (idOfLoggedInUser > 0)
        return true;
    else
        return false;
}



