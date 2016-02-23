#ifndef CHANGEPLAN_TRANSACTION_H
#define CHANGEPLAN_TRANSACTION_H

#include <string>
#include "users.h"

using namespace std;

class ChangePlanTransaction {
  private:
    string name, account_number, plan;

  public:
    string ChangePlan(Users user); 
};
            
#endif