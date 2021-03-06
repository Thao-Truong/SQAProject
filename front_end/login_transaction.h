#ifndef LOGIN_TRANSACTION_H
#define LOGIN_TRANSACTION_H

#include <string>
#include "users.h"

using namespace std;

//class to process the login transaction
class LoginTransaction {
  private:
    string amount;
    string name, kind;
    Users users[10];
  public:
    string Input(Users users);
    Users* GetUsers();   //returns the array of users
    string GetName();    
    string GetKind();
    string GetAmount();

    void SetName(string nme);
    void SetKind(string knd);
    void SetAmount(string amt);
     
    string Login();   //determines whether the session is admin or standard

    Users ReadAccounts(string name, string accountsFile);   //reads in the current bank accounts file    
};

#endif        