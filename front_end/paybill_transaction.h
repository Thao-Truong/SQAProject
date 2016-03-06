#ifndef PAYBILL_TRANSACTION_H
#define PAYBILL_TRANSACTION_H

#include <string>
#include "users.h"

using namespace std;

class PaybillTransaction {
  private:
    string name, account_number, amount, company;

  public:
    string Process(Users user, Users* all_users);
};

#endif

