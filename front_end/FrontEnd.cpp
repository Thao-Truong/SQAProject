#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include "loginTransaction.cpp"
#include "withdrawalTransaction.cpp"

using namespace std;

  

class FrontEnd {
  public:
    void getTransactions() {
      bool flag = false;
      bool previous = false;
      string input;
      Users user;      //current logged-in user's info

      while (1) {
       cout << "Enter a transaction:\n";
       cin >> input;
       if (input.compare("login") == 0 && previous == false) {
          flag = true;
          previous = true;
          loginTransaction lt;
          lt.login();
          user = lt.readAccounts(lt.getName());
          if (user.getAccountName() == "" && lt.getKind() != "A") {
            cout << "Transaction invalid" << endl;
            flag = false;
            previous = false;
            continue;
          }  
          lt.writeTransaction();
          cout << "CURRENT USER IS:  " << user.getAccountName() << endl;
          cout << "CURRENT BALANCE IS: " << user.getBalance() << endl;     
        } else if (input.compare("withdrawal") == 0 && flag == true) {
           withdrawalTransaction wt;
           if (wt.process(user) == -1) {
              cout << "Transaction invalid." << endl;
              continue;
           }
           wt.writeTransaction();
        } else if (input.compare("deposit") == 0 && flag == true) {
               cout << "Enter account number:\n";
               cin >> input;
               cout << "Enter Amount: \n";
               cin >> input;               
        } else if (input.compare("transfer") == 0 && flag == true) {

        } else if (input.compare("paybill") == 0 && flag == true) {

        } else if (input.compare("create") == 0 && flag == true) { 

        } else if (input.compare("delete") == 0 && flag == true) {

        } else if (input.compare("disable") == 0 && flag == true) { 

        } else if (input.compare("changeplan") == 0 && flag == true) {

        } else if (input.compare("logout") == 0 && flag == true) {

        } else {
          cout << "Transaction invalid.\n";
        }
      }
    }
          
};

               

                 
               
             