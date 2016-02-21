#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Users.cpp"


using namespace std;


class depositTransaction {
   private:
      string name, accountNumber, amount;

   public:
      int process(Users user, Users* allUsers) {
         double fee, total;
         string balance;    //balance of user for an admin login
         if (user.getAccountName() == "") {
            cout << "Account holder's name:" << endl;
            cin.ignore();
            getline(cin, name);
            }
          for (int i = 0; i < 10; i++) {
             if (allUsers[i].getAccountName().compare(name) == 0) {
                 balance = allUsers[i].getBalance();
                 break;
             }
           }
          cout << "Account number:" << endl;
          cin >> accountNumber;
          if (user.getAccountName() != "" && accountNumber != user.getAccountNumber()) {
             return -1;
          }
          cout << "Amount to Deposit:" << endl;
          cin >> amount;
     
                   

          if (user.getAccountName() != "") {
             name = user.getAccountName();
          }

          if (user.getStatus() == "S") {
             fee = .05;
          }
          else if (user.getStatus() == "N") {
             fee = .10;
          }
          else {
             fee = 0;
          }
          total = atof(amount.c_str()) - fee;
          
         
            
       } 

       void writeTransaction() {
           printf("04 %-20s %s %s\n", name.c_str(), accountNumber.c_str(), amount.c_str());
       } 
};
