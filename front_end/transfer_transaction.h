#ifndef TRANSFER_TRANSACTION_H
#define TRANSFER_TRANSACTION_H

#include <string>
#include "users.h"


using namespace std;


class TransferTransaction {
   private:
      string name_from, name_to, account_number_from, account_number_to, amount;

   public:
      int Process(Users user, Users* all_users);
       
};
#endif
