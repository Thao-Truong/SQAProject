#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Users.cpp"


using namespace std;


class transferTransaction {
   private:
      string nameFrom, nameTo, accountNumberFrom, accountNumberTo, amount;

   public:
      int process(Users user, Users* allUsers) {
         double fee, total;
         string balanceFrom;    //balance of user for an admin login
         string accountTo;
         if (user.getAccountName() == "") {
            cout << "Account holder's name:" << endl;
            cin.ignore();
            getline(cin, nameFrom);
            }
          for (int i = 0; i < 10; i++) {
             if (allUsers[i].getAccountName().compare(nameFrom) == 0) {
                 balanceFrom = allUsers[i].getBalance();
                 break;
             }
           }
          cout << "Account number money will be transferred from:" << endl;
          cin >> accountNumberFrom;
          if (user.getAccountName() != "" && accountNumberFrom != user.getAccountNumber()) {
             return -1;
          }
          
          cout << "Account number money will be transferred to:" << endl;
          cin >> accountNumberTo;
          for (int i = 0; i < 10; i++) {
             if (allUsers[i].getAccountNumber().compare(accountNumberTo) == 0) {
                 nameTo = allUsers[i].getAccountName();
                 accountTo = allUsers[i].getAccountNumber();
                 break;
             }
           }
          if (user.getAccountName() != "" && accountNumberTo != accountTo) {
             return -1;
          }
          cout << "Amount to Transfer:" << endl;
          cin >> amount;
          
          

          if (user.getAccountName() != "") {
             nameFrom = user.getAccountName();
          }

          if (user.getPlanType() == "S") {
             fee = .05;
          }
          else if (user.getPlanType() == "N") {
             fee = .10;
          }
          else {
             fee = 0;
          }
          total = atof(amount.c_str()) + fee;
          
          if (user.getAccountName() != "" && total > 1000.00) {
             return -1;
          }      
          
          if (user.getAccountName() != "" && atof(user.getBalance().c_str()) - total < 0.0001) {
            
            return -1;
          }
            
       } 

       void writeTransaction() {
           printf("04 %-20s %s %s\n", nameFrom.c_str(), accountNumberFrom.c_str(), amount.c_str());
           printf("04 %-20s %s %s\n", nameTo.c_str(), accountNumberTo.c_str(), amount.c_str());
       } 
};
