#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "users.h"
#include "withdrawal_transaction.h"

using namespace std;

int WithdrawalTransaction::Process(Users user, Users* all_users) {
  double fee, total;
  string balance;    //balance of user for an admin login
  if (user.GetAccountName() == "") {      //admin login
    cout << "Account holder's name:" << endl;
    cin.ignore();
    getline(cin, name);
  }
  for (int i = 0; i < 10; i++) {   // search for balance of account holder
    if (all_users[i].GetAccountName().compare(name) == 0) {
      balance = all_users[i].GetBalance();
      break;
    }
  }
  cout << "Account number:" << endl;
  cin >> account_number;

  if (user.GetAccountName() != "" && account_number != user.GetAccountNumber()) {  //check if account holder's name matches account number
    return -1;
  }
  cout << "Amount to withdraw:" << endl;
  cin >> amount;               

  if (user.GetAccountName() != "") {  //name of account holder if admin login
    name = user.GetAccountName();
  }

  if (user.GetPlanType() == "S") {    //get plan type to assess transaction fee
    fee = .05;
  } else if (user.GetPlanType() == "N") {
    fee = .10;
  } else {
    fee = 0;
  }
  total = atof(amount.c_str()) + fee;
         
  if (user.GetAccountName() != "" && total > 499.999) {  //check that standard user cannot withdraw more than $500
    return -1;
  }
          
  if (user.GetAccountName() != "" && (atof(user.GetBalance().c_str()) - total) < 0.001) {   //check if balance is at least $0.00 after withdrawal for standard user
    return -1;
  }
  if (user.GetAccountName() == "" && (atof(balance.c_str()) - total) < 0.001) {   //check if balance is at least $0.00 for admin user
    return -1;
  }    
}