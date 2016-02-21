#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include "loginTransaction.cpp"

using namespace std;


class FrontEnd {
   
   public:
       void getTransactions() {
          bool flag = false;
          string input;
          while (1) {
             cout << "Enter a transaction:\n";
             cin >> input;
             if (input.compare("login") == 0) {
                flag = true;
                
                loginTransaction lt;
                lt.login();
                lt.writeTransaction();
                lt.readAccounts();
                 
              }
              /*else if (input.compare("deposit") == 0 && flag == true) {
                 cout << "Enter account number:\n";
                 cin >> input;
                 trans.setAccountNumber(input);
                 cout << "Enter Amount: \n";
                 cin >> input;
                 trans.setAmount(input);
                 writeTransaction();
               } */
               else {
                  cout << "Transaction invalid.\n";
               }
              }
            }
            
};

               

                 
               
             