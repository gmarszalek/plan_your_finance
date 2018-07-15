#include <iostream>
#include <windows.h>
#include "UserManager.h"
#include "BudgetManager.h"


using namespace std;

int main()
{
    vector <User> users;

    UserManager userManager;
    BudgetManager budgetManager(userManager.getLoggedInUserId());

    char choice;

    while (true)
    {
        if ( userManager.getLoggedInUserId() == 0)
        {
            system ("cls");

            cout << "-----PLAN YOUR FINANCES-----" << endl;
            cout << "--------------------------------" << endl;
            cout << "1. Registration" << endl;
            cout << "2. Sign In" << endl;
            cout << "9. Exit" << endl;
            cout << "--------------------------------" << endl;
            cout << "Your choice: ";
            cin >> choice;

            switch (choice)
            {

            case '1':
                userManager.registration();
                break;
            case '2':
                userManager.logging();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Incorrect option!" << endl << endl;
                system ("pause");
                break;

            }

        }

        else if ( userManager.getLoggedInUserId() > 0 )
        {
            BudgetManager budgetManager(userManager.getLoggedInUserId());
            int idLoggedInUser = userManager.getLoggedInUserId();


            system("cls");
            cout << " ----- USER MENU ----- " << endl;
            cout << " ----------------------" << endl;
            cout << "1. ADD INCOMES" << endl;
            cout << "2. ADD EXPENSES" << endl;
            cout << "-----------------------" << endl;
            cout << "3. Balance from current month" << endl;
            cout << "4. Balance from previous month" << endl;
            cout << "5. Balance from selected period" << endl;
            cout << "-----------------------" << endl;
            cout << "6. Password change" << endl;
            cout << "7. Logging Out" << endl;
            cout << "-----------------------" << endl;
            cout << "Your choice: ";
            cin >> choice;


            switch (choice)
            {

            case '1':

                budgetManager.addIncome();
                break;

            case '2':
                budgetManager.addExpenses();
                break;
            case '3':
                budgetManager.showBalanceFromCurrentMonth();
                break;
            case '4':
                budgetManager.showBalanceFromPreviouslyMonth();
                break;
            case '5':
                budgetManager.ShowBalanceFromSelectedPeriod();
                break;
            case '6':
                userManager.passwordChange(idLoggedInUser);
                break;
            case '7':
                userManager.logOut();
                break;
            default:
                cout << endl << "Incorrect option!" << endl << endl;
                system ("pause");
                break;


            }
            string newPassword;


        }

    }

    return 0;
}
