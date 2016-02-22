#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <string>

using namespace std;

class Users {
  private:
  string account_name, account_number, status, balance, plan_type;
   
  public:
    string GetAccountName();
    string GetAccountNumber();
    string GetStatus(); 
    string GetBalance(); 
    string GetPlanType(); 
    void SetAccountName(string name);
    void SetAccountNumber(string number);
    void SetStatus(string st);
    void SetBalance(string bal);
    void SetPlanType(string pt);

 };
#endif
