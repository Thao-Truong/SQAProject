#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Users.cpp"


using namespace std;


class paybillTransaction {
   private:
      string name, accountNumber, amount, company;

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
          cout << "Company to whom bill is being paid:" << endl;
          cin >> company;
          if (company.compare("EC") != 0 && company.compare("CQ") != 0 && company.compare("TV") != 0) {
            return -1;
          }

          cout << "Amount to pay:" << endl;
          cin >> amount;
       
                   

          if (user.getAccountName() != "") {
             name = user.getAccountName();
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
          if (total > atof(user.getBalance().c_str())) {
             return -1;
          }
          if (user.getAccountName() != "" && total > 2000.00) {
             return -1;
          }
            
       } 

       void writeTransaction() {
           printf("0x %-20s %s %s %s\n", name.c_str(), accountNumber.c_str(), amount.c_str(), company.c_str());
       } 
};
