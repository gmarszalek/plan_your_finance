#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#pragma once


using namespace std;

class UserManager
{
private:

    int loggedInUserId = 0;
    vector <User> users;

public:
    void registration();
    void logging ();
    void passwordChange (int idLoggedInUser);
    int getLoggedInUserId();
    int logOut();

};

#endif
