#include <iostream>
#include "UserManager.h"
#include "UserFile.h"
#include "BudgetManager.h"
#include "User.h"
#include <vector>
#include <windows.h>

using namespace std;

int UserManager::getLoggedInUserId()
{
    return loggedInUserId;
}

void UserManager::registration ()
{
    UserFile userFile;
    User user;
    string newLogin = "", name = "", surname = "", password = "";

    userFile.loadUserFromFile(users);

    system("cls");
    cout << "-----REGISTRATION-----" << endl << endl;

    if (users.empty() == true)
    {
        user.setUserId(1);
    }
    else
    {
        user.setUserId(users.back().getUserId() + 1 );

    }

    cout << "Enter your login: ";
    cin >> newLogin;

    vector <User>::iterator itr = users.begin();

    while (itr < users.end())

    {
        if (itr ->User::getLogin() == newLogin)
        {
            cout << "This login exist, pleas enter a new login: ";
            cin >> newLogin;
            itr = users.begin();
        }
        else
        {
            itr ++;
        }
    }

    cout << "Enter your Name: ";
    cin >> name;
    cout << "Enter your Surname: ";
    cin >> surname;
    cout << "Enter the password: ";
    cin >> password;

    user.setPassword(password);
    user.setLogin(newLogin);
    user.setName(name);
    user.setSurname(surname);
    users.push_back(user);

    userFile.addUserToTextFile(user);
    cout << "The account has been created!" << endl;
    Sleep(1500);

}
void UserManager::logging()
{
    vector <User> users;
    UserFile userFile;
    userFile.loadUserFromFile(users);

    system("cls");
    string login = "", password = "";

    cout << "-----LOGGING-----" << endl;
    cout << "-----------------" << endl;

    cout << endl << "Login: ";
    cin >> login;

    vector <User>::iterator itr = users.begin();

    while (itr < users.end())
    {
        if (itr ->User::getLogin() == login)

        {
            for (int attempt = 3; attempt >0; attempt--)
            {

                cout << "Enter your password. There are attempt left:  " << attempt << ": ";
                cin >> password;

                if (itr ->User::getPassword() == password)
                {

                    this -> loggedInUserId = itr -> User::getUserId();
                    cout << endl << "You are logged in." << endl << endl;
                    Sleep(2000);
                    return;
                }
            }
            cout << "Wrong password!" << endl;
            Sleep(2000);
            return;
        }
        itr++;

    }
    cout << "There is no user with this login!" << endl << endl;
    Sleep(2000);
    return;
}
void UserManager::passwordChange(int idLoggedInUser)
{

    User user;
    UserFile userFile;
    UserManager userManager;


    cout << "-----PASSWORD CHANGE-----" << endl << endl;

    string newPassword = "";

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {

        if (itr -> User::getUserId() == idLoggedInUser)
        {
            cout << "ENTER NEW PASSWORD: ";
            cin >> newPassword;
            itr -> User::setPassword(newPassword);
            cout << "PASSWORD CHANGED " << endl;
            userFile.addUserAfterChanged(users);
            Sleep(1500);
            cout << endl;

        }
        else
        {
            userFile.addUserAfterChanged(users);

        }

    }

}
int UserManager::logOut()
{
    this -> loggedInUserId = 0;
    cout << "YOU'RE LOGED OUT" << endl;
    Sleep(1500);
}

