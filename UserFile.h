#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

class UserFile
{
public:

    void addUserToTextFile (User user);
    void addUserAfterChanged (vector <User> &users);
    User loadUserFromFile(vector <User> &users);


};
