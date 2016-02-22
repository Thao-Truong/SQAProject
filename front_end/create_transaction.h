#ifndef CREATE_TRANSACTION_H
#define CREATE_TRANSACTION_H


#include <string>
#include "Users.h"

using namespace std;

class CreateTransaction {
  private:
    string name, account_number, balance;

  public:
    int Process(Users user); 
};
            
#endif
