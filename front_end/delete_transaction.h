#ifndef DELETE_TRANSACTION_H
#define DELETE_TRANSACTION_H

#include <string>
#include "users.h"

using namespace std;

class DeleteTransaction {
  private:
    string name, account_number, status;

  public:
    string DeleteAccount(Users user); 
};
            
#endif