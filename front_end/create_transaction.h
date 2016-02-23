#ifndef CREATE_TRANSACTION_H
#define CREATE_TRANSACTION_H

#include <string>
#include "users.h"

using namespace std;

class CreateTransaction {
  private:
    string name, account_number, balance;

  public:
    string Process(Users user); 
};
            
#endif