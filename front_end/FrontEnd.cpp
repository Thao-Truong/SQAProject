#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include "loginTransaction.cpp"
#include "withdrawalTransaction.cpp"
#include "depositTransaction.cpp"
//#include "transaction_file.cpp"
#include "Users.cpp"

using namespace std;

class FrontEnd {
  public:
    void getTransactions() {
      bool flag = false;      //flag to check that no transaction occurs before login
      bool previous = false;  //flag to check that no subsequent login should be accepted after a login, until after a logout
      string input;          //input line
      Users user;      //current logged-in user's info
      loginTransaction lt;

      while (1) {
       cout << "Enter a transaction:\n";
       cin >> input;
       if (input.compare("login") == 0 && previous == false) {
          flag = true;
          previous = true;
          //loginTransaction lt;
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
           Users* allUsers = lt.getUsers();

           if (wt.process(user, allUsers) == -1) {
              cout << "Transaction invalid." << endl;
              continue;
           }
           wt.writeTransaction();
        } else if (input.compare("deposit") == 0 && flag == true) {
           depositTransaction dt;
           Users* allUsers = lt.getUsers();
           if (dt.process(user, allUsers) == -1) {
               cout << "Transaction invalid." << endl;
               continue;
           } 



   
        } else if (input.compare("transfer") == 0 && flag == true) {
          Users* allUsers = lt.getUsers();

          for (int i = 0; i < 10; i++) {
                  cout << allUsers[i].getAccountName() << endl;
              }
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

               

                 
               
             