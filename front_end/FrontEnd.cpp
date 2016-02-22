#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <vector>

#include "create_transaction.h"
#include "deposit_transaction.h"
#include "login_transaction.h"
#include "logout.h"
#include "paybill_transaction.h"
//#include "transaction_file.h"
#include "withdrawal_transaction.h"
#include "transfer_transaction.h"
#include "users.h"

using namespace std;

class FrontEnd {
  public:
    void getTransactions() {
      bool flag = false;      //flag to check that no transaction occurs before login
      bool previous = false;  //flag to check that no subsequent login should be accepted after a login, until after a logout
      string input;          //input line
      Users user;      //current logged-in user's info
      LoginTransaction lt;
      vector<string> current_transactions;

      while (1) {
       cout << "Enter a transaction:\n";
       cin >> input;
       if (input.compare("login") == 0 && previous == false) {
          flag = true;
          previous = true;
          current_transactions.push_back(lt.Login());
          user = lt.readAccounts(lt.GetName());
          if (user.GetAccountName() == "" && lt.GetKind() != "A") {
            cout << "Transaction invalid" << endl;
            flag = false;
            previous = false;
            continue;
          }  
          lt.writeTransaction();
          cout << "CURRENT USER IS:  " << user.GetAccountName() << endl;
          cout << "CURRENT BALANCE IS: " << user.GetBalance() << endl;     
        } else if (input.compare("withdrawal") == 0 && flag == true) {
           WithdrawalTransaction wt;
           Users* all_users = lt.GetUsers();

           if (wt.Process(user, all_users) == -1) {
              cout << "Transaction invalid." << endl;
              continue;
           }
           wt.WriteTransaction();
        } else if (input.compare("deposit") == 0 && flag == true) {
           DepositTransaction dt;
           Users* all_users = lt.GetUsers();

           current_transactions.push_back(dt.process(user, all_users));


           if (current_transactions.back().compare("invalid") == 0) {
               cout << "Transaction invalid." << endl;
               continue;
           } 



   
        } else if (input.compare("transfer") == 0 && flag == true) {
             TransferTransaction tt;
             Users* all_users = lt.GetUsers();
             if (tt.process(user, all_users) == -1) {
               cout << "Transaction invalid." << endl;
               continue;
              } 
              tt.WriteTransaction();

        } else if (input.compare("paybill") == 0 && flag == true) {
             paybillTransaction pt;
             Users* all_users = lt.GetUsers();
             if (pt.process(user, all_users) == -1) {
               cout << "Transaction invalid." << endl;
               continue;
              } 
              pt.WriteTransaction();

        } else if (input.compare("create") == 0 && flag == true) { 
             CreateTransaction ct;
             if  (ct.process(user) == -1) {
                cout << "Transaction invalid." << endl;
                continue;
             }
             //ct.writeTransaction(); 

        } else if (input.compare("delete") == 0 && flag == true) {

        } else if (input.compare("disable") == 0 && flag == true) { 

        } else if (input.compare("changeplan") == 0 && flag == true) {

        } else if (input.compare("logout") == 0 && flag == true) {
          // logout transaction
          string account_holder = lt.GetName();
          Logout lo;

          current_transactions.push_back(lo.Logout(account_holder));

          // output transactionfile
          lo.OutputTransactions(current_transactions);
        } else {
          cout << "Transaction invalid.\n";
        }
      }
    }
          
};

               

                 
               
             