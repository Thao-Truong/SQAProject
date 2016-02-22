#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Users.cpp"


using namespace std;


class createTransaction {
   private:
      string name, accountNumber, balance;

   public:
      int process(Users user) {
         
          if (user.getAccountName() != "") {   //if not admin
             return -1;
          }
          cout << "Account holder's name:" << endl;
          cin >> name;
          if (name.length() > 20 ) {    //20 character max length for name
             return -1;
          }
          cout << "Initial balance:" << endl;
          cin >> balance;
          if (atof(balance.c_str()) > 99999.99 ) {   //max initial balance is $99999.99
             return -1;
          }
            