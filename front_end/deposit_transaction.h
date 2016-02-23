#ifndef DEPOSIT_TRANSACTION_H
#define DEPOSIT_TRANSACTION_H


#include <string>
#include "users.h"


using namespace std;

//this class handles a deposit transaction
class DepositTransaction {
   private:
      string name, account_number, amount;

   public:
      string Process(Users user, Users* all_users);   // process deposit transaction 

};
        
#endif
