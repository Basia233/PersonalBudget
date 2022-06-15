#include "UsersFile.h"

void UsersFile::addUserToFile(User user)
{
    CMarkup xml;

    bool fileExsist = xml.Load( "Users.xml" ); // otwiera plik xml

    if(!fileExsist)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n"); //kodowanie UTF-8
        xml.AddElem( "Users" ); // tworzy galaz Users
    }

    xml.FindElem(); //wchodzi do kolejnego poziomu pliku xml
    xml.IntoElem(); // ustawia ten element jako glowny, mozna dodac cos wewnatrz
    xml.AddElem("User"); // dodaje element
    xml.IntoElem();
    xml.AddElem("UserID", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.Save("Users.xml"); // zapisuje to co jest w pamieci do obiektu xml
}


vector <User> UsersFile::loadUsersFromFile()
{
    User user;
    vector <User> users;
    CMarkup xml;

    bool fileExsist = xml.Load("Users.xml");

    if(fileExsist)
    {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("User"))
        {
            xml.IntoElem();
            xml.FindElem("UserID");
            user.setId(atoi(xml.GetData().c_str()));
            xml.FindElem("Login");
            user.setLogin(xml.GetData());
            xml.FindElem("Password");
            user.setPassword(xml.GetData());
            xml.FindElem("Name");
            user.setName(xml.GetData());
            xml.FindElem("Surname");
            user.setSurname(xml.GetData());
            xml.OutOfElem();

            users.push_back(user);
        }

    }

    return users;
}


vector <User> UsersFile::changePasswordOfLoggedInUser(int idOfLoggedInUser, vector <User> users)
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    getline(cin, newPassword);


    for (int i=0; i<users.size(); i++)
    {
        if (users[i].getId() == idOfLoggedInUser)
        {
            users[i].setPassword(newPassword);

            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
        changePasswordInFile(idOfLoggedInUser, newPassword);
    }

    return users;
}


void UsersFile::changePasswordInFile(int idOfLoggedInUser, string newPassword)
{
    CMarkup xml;

    bool fileExsist = xml.Load("Users.xml");

    if(fileExsist)
    {
        xml.FindElem();//wchodzi do kolejnego poziomu pliku xml
        xml.IntoElem();

        while (xml.FindElem("User"))
        {
            xml.IntoElem();
            xml.FindElem("UserID");

            if (idOfLoggedInUser == atoi(xml.GetData().c_str()))
            {
                xml.FindElem("Password");
                xml.SetData(newPassword);
                break;
            }
            xml.OutOfElem();
        }

        xml.Save("Users.xml");
    }

}


