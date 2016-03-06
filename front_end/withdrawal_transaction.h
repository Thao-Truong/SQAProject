#ifndef WITHDRAWAL_TRANSACTION_H
#define WITHDRAWAL_TRANSACTION_H

#include <string>
#include "users.h"

using namespace std;

//this class handles a withdrawal transaction
class WithdrawalTransaction {
  private:
    string name, account_number, amount;

  public:
    string  Process(Users user, Users* all_users);   //process a withdrawal transaction
};

#endif
