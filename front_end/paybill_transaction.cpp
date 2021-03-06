#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "users.h"
#include "paybill_transaction.h"
#include "transaction_file.h"

using namespace std;

string PaybillTransaction::Process(Users user, Users* all_users) {
  double fee, total;
  string balance;    //balance of user for an admin login
  string acct_number;  //account number of user for an admin login
  string transaction_data = "";

  if (user.GetAccountName() == "") {  //if admin login...
    cout << "Account holder's name:" << endl;  //get account holder's name  (for admin login)
    cin.ignore();
    getline(cin, name);
  }
  for (int i = 0; i < 10; i++) {   //search for balance of account holder
    if (all_users[i].GetAccountName().compare(name) == 0) {  
      balance = all_users[i].GetBalance();
      acct_number = all_users[i].GetAccountNumber();
      break;
    }
  }
  cout << "Account number:" << endl;
  cin >> account_number;

  if (user.GetAccountName() != "" && account_number != user.GetAccountNumber()) {   //check if account number is valid
    return "invalid";
  }
  if (user.GetAccountName() == "" && account_number != acct_number) {
    return "invalid";
  }
  cout << "Payee:" << endl;
  cin >> company;

  if (company.compare("EC") != 0 && company.compare("CQ") != 0 && company.compare("TV") != 0) {  //can only accept companies EC, CQ, TV
    return "invalid";
  }
  cout << "Amount:" << endl;
  cin >> amount;
       
  if (user.GetAccountName() != "") {  // get name of user (for standard login)
    name = user.GetAccountName();
  }

  if (user.GetPlanType() == "S") {   //assess paybill transaction fee
    fee = .05;
  } else if (user.GetPlanType() == "N") {
    fee = .10;
  } else {
    fee = 0;
  }
  total = atof(amount.c_str()) + fee;   //total, including fee

  if (total > atof(user.GetBalance().c_str())) {  //check to make sure balance after is at least $0.00
    if (user.GetAccountName() == "") {
      for (int i = 0; i < 10; i++) {   // search for status of account holder
        if (all_users[i].GetAccountName().compare(name) == 0) {
          if (total > atof(all_users[i].GetBalance().c_str())) {
            return "invalid";
          }
        }
      }
    } else {
       return "invalid";
    }
  }
  if (user.GetAccountName() != "" && atof(amount.c_str()) > 2000.00) {   //check if standard user does not exceed limit of $2000.00
    return "invalid";
  }  
  transaction_data = TransactionFile::WriteTransaction("paybill", name, account_number, amount, company); 
  return transaction_data;        
}


       
