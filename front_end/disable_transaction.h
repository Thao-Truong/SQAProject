#ifndef DISABLE_TRANSACTION_H
#define DISABLE_TRANSACTION_H

#include <string>
#include "users.h"

using namespace std;

class DisableTransaction {
  private:
    string name, account_number, status;

  public:
    string Process(Users user, Users* all_users); 
};
            
#endif
