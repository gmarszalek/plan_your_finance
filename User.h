#ifndef USER_H
#define USER_H

#include <iostream>
#pragma once

using namespace std;

class User
{
    int userId = 0;
    string login = "";
    string password = "";
    string name = "";
    string surname = "";

public:
    int getUserId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
    void setUserId(int userId);
    void setLogin (string login);
    void setPassword (string password);
    void setName (string name);
    void setSurname (string surname);

};

#endif
