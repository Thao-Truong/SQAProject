#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Users.cpp"


using namespace std;


class withdrawalTransaction {
   private:
      string name, accountNumber, amount;

   public:
      int process(Users user) {
         double fee, total;
         if (user.getAccountName() == "") {
            cout << "Account holder's name:" << endl;
            cin.ignore();
            getline(cin, name);
            }
          cout << "Account number:" << endl;
          cin >> accountNumber;
          if (user.getAccountName() != "" && accountNumber != user.getAccountNumber()) {
             return -1;
          }
          cout << "Amount to withdraw:" << endl;
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
          total = atof(amount.c_str()) + fee;
         
          if (user.getAccountName() != "" && total > 499.999) {
             return -1;
          }
          
          if (user.getAccountName() != "" && (atof(user.getBalance().c_str()) - total) < 0.001) {
             return -1;
          }
          
              
            
       } 

       void writeTransaction() {
           printf("01 %-20s %s %s\n", name.c_str(), accountNumber.c_str(), amount.c_str());
       } 
};
