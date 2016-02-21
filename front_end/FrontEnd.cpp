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
          bool previous = false;
          string input;
          Users user;
          while (1) {
             cout << "Enter a transaction:\n";
             cin >> input;
             if (input.compare("login") == 0 && previous == false) {
                flag = true;
                previous = true;
                loginTransaction lt;
                lt.login();
                lt.writeTransaction();
                user = lt.readAccounts(lt.getName());
                cout << "CURRENT USER IS:  " << user.getAccountName() << endl;
                cout << "CURRENT BALANCE IS: " << user.getBalance() << endl;
                 
              }
             else if (input.compare("deposit") == 0 && flag == true) {
                 cout << "Enter account number:\n";
                 cin >> input;
                 cout << "Enter Amount: \n";
                 cin >> input;
                 
               } 
               else {
                  cout << "Transaction invalid.\n";
               }
              }
            }
            
};

               

                 
               
             