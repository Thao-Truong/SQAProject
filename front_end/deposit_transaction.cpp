#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Users.cpp"
#include "deposit_transaction.h"

using namespace std;
  
int DepositTransaction::Process(Users user, Users* all_users) {
  double fee, total;
  string balance;    //balance of user for an admin login
  if (user.GetAccountName() == "") {     //check for admin login
    cout << "Account holder's name:" << endl;
    cin.ignore();
    getline(cin, name);
  }
  for (int i = 0; i < 10; i++) {
    if (all_users[i].GetAccountName().compare(name) == 0) {    //get account holder's balance
      balance = all_users[i].GetBalance();
      break;
    }
  }
  cout << "Account number:" << endl;
  cin >> account_number;
  if (user.GetAccountName() != "" && account_number != user.GetAccountNumber()) {   //check if account number matches account holder
    return -1;
  }
  cout << "Amount to Deposit:" << endl;
  cin >> amount;                  
  if (user.GetAccountName() != "") {   //get user's name for standard login
    name = user.GetAccountName();
  }

  if (user.GetPlanType() == "S") {         //get plan type to assess transaction fee
    fee = .05;
  }
  else if (user.GetPlanType() == "N") {
    fee = .10;
  }
  else {
    fee = 0;
  }
  total = atof(amount.c_str()) - fee;     //total amount to deposit
            
  }        
}
