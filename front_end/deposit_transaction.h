#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Users.cpp"


using namespace std;


class DepositTransaction {
   private:
      string name, account_number, amount;

   public:
      int process(Users user, Users* all_users);

};
        