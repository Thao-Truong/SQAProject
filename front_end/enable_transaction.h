#ifndef ENABLE_TRANSACTION_H
#define ENABLE_TRANSACTION_H

#include <string>
#include "users.h"

using namespace std;

class EnableTransaction {
  private:
    string name, account_number, status;

  public:
    string Process(Users user, Users* all_users); 
};
            
#endif