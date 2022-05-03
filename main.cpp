#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("Users.xml", "Incomes.xml");

    char choice;


    while(true)
    {
        if (personalBudget.isUserLoggedIn() == 0)
        {
            choice = personalBudget.selectOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogIn();
                break;
            case '9':
                exit(0);
                break;
            }
        }
        else
        {
            choice = personalBudget.selectOptionFromUserMenu();

            switch (choice)
            {
          /*  case '1':
                personalBudget.addNewIncome();
                break;
            case '2':
                personalBudget.addNewExpense();
                break;
            case '3':
                personalBudget.showBalanceForCurrentMonth();
                break;
            case '4':
                personalBudget.showBalanceForPreviousMonth();
                break;
            case '5':
                personalBudget.showBalanceForSelectedPeriod();
                break;*/
            case '6':
                personalBudget.changePasswordOfLoggedInUser();
                break;
            case '7':
                personalBudget.logOut();
                break;

            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system ("pause");
                break;
            }
        }
    }



 // personalBudget.displayAllUsers();
  // personalBudget.userRegistration(();
   //personalBudget.userRegistration(();
 //personalBudget.displayAllUsers();
   //personalBudget.userLogIn();
  // personalBudget.changePasswordOfLoggedInUser();
   //personalBudget.logOut();


    return 0;
}
