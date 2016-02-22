#ifndef PAYBILL_TRANSACTION_H
#define PAYBILL_TRANSACTION_H


#include <string>
#include "Users.cpp"


using namespace std;


class PaybillTransaction {
   private:
      string name, account_number, amount, company;

   public:
      int Process(Users user, Users* all_users);
       
};

#endif
