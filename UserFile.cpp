#include <iostream>
#include "Markup.h"
#include "UserFile.h"
#include "Conversion.h"
#include "UserManager.h"
#include "User.h"


using namespace std;


void UserFile::addUserToTextFile( User user)
{
    Conversion conversion;
    CMarkup xmlFile;
    UserManager userManager;
    xmlFile.Load("Users.xml");

    if ( !xmlFile.FindElem("USERS"))
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("USERS");

    }

    xmlFile.IntoElem();
    xmlFile.AddElem("USERS");
    xmlFile.IntoElem();
    xmlFile.AddElem("USERID", conversion.intToString(user.getUserId()));
    xmlFile.AddElem("LOGIN", user.getLogin());
    xmlFile.AddElem("PASSWORD", user.getPassword());
    xmlFile.AddElem("NAME", user.getName());
    xmlFile.AddElem("SURNAME", user.getSurname());
    xmlFile.OutOfElem();
    xmlFile.Save("Users.xml");

}

User UserFile::loadUserFromFile(vector <User> &users)
{
    Conversion conversion;
    UserFile userFile;
    User user;

    CMarkup xmlFile;
    xmlFile.Load("Users.xml");

    xmlFile.FindElem();
    xmlFile.IntoElem();

    while ( xmlFile.FindElem("USERS"))
    {
        xmlFile.IntoElem();
        xmlFile.FindElem("USERID");
        string userId = xmlFile.GetData();
        user.setUserId(atoi(userId.c_str()));
        xmlFile.FindElem("LOGIN");
        string login = xmlFile.GetData();
        user.setLogin(login);
        xmlFile.FindElem("PASSWORD");
        string password = xmlFile.GetData();
        user.setPassword(password);
        xmlFile.FindElem("NAME");
        string name = xmlFile.GetData();
        user.setName(name);
        xmlFile.FindElem("SURNAME");
        string surname = xmlFile.GetData();
        user.setSurname(surname);
        users.push_back(user);
        xmlFile.OutOfElem();

    }

    return user;

}

void UserFile::addUserAfterChanged(vector <User> &users)
{
    User user;
    Conversion conversion;
    CMarkup xmlFile;
    if ( !xmlFile.FindElem("USERS"))
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("USERS");
        xmlFile.IntoElem();

    }

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        xmlFile.AddElem("USERS");
        xmlFile.IntoElem();
        xmlFile.AddElem("USERID", conversion.intToString(itr -> User::getUserId()));
        xmlFile.AddElem("LOGIN", itr -> User::getLogin());
        xmlFile.AddElem("PASSWORD", itr -> User::getPassword());
        xmlFile.AddElem("NAME", itr -> User::getName());
        xmlFile.AddElem("SURNAME", itr -> User::getSurname());
        xmlFile.OutOfElem();
        xmlFile.Save("Users.xml");

    }

}
