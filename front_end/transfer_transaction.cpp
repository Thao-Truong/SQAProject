#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "users.h"
#include "transfer_transaction.h"
#include "transaction_file.h"

using namespace std;

  vector<string> TransferTransaction::Process(Users user, Users* all_users) {
  double fee, total;
  string balance_from;    //balance of user for an admin login
  string account_to;
  vector<string> transaction_data;

  if (user.GetAccountName() == "") {   //check if admin login & get account holder's name
    cout << "Account holder's name:" << endl;
    cin.ignore();
    getline(cin, name_from);
  }
  for (int i = 0; i < 10; i++) {   //search for user's balance_from 
    if (all_users[i].GetAccountName().compare(name_from) == 0) {
      balance_from = all_users[i].GetBalance();
      break;
    }
  }
  cout << "Account number money will be transferred from:" << endl;
  cin >> account_number_from;
  if (user.GetAccountName() != "" && account_number_from != user.GetAccountNumber()) {   //check if account number is valid for the user
    transaction_data.push_back("invalid");
    return transaction_data;
  }
          
  cout << "Account number money will be transferred to:" << endl;
  cin >> account_number_to;
  for (int i = 0; i < 10; i++) {
    if (all_users[i].GetAccountNumber().compare(account_number_to) == 0) {   //search for name and account money will be transferred to
      name_to = all_users[i].GetAccountName();
      account_to = all_users[i].GetAccountNumber();
      break;
    }
  }
  if (user.GetAccountName() != "" && account_number_to != account_to) {    //check if account_number_to is valid
    transaction_data.push_back("invalid");
    return transaction_data;
  }
  cout << "Amount to Transfer:" << endl;
  cin >> amount;          

  if (user.GetAccountName() != "") {   //if standard login 
    name_from = user.GetAccountName();
  }

  if (user.GetPlanType() == "S") {   //assess transaction fee
    fee = .05;
  } else if (user.GetPlanType() == "N") {
    fee = .10;
  } else {
    fee = 0;
  }


  total = atof(amount.c_str()) + fee;
    

  if (user.GetAccountName() != "" && atof(amount.c_str()) > 1000.00) {   //standard user cannot transfer more than $1000.00
    transaction_data.push_back("invalid");
    return transaction_data;
  }      

          
  if (user.GetAccountName() != "" && atof(user.GetBalance().c_str()) - total < 0.0001) {  // make sure account balance is at least $0.00
     transaction_data.push_back("invalid");
    return transaction_data;
  }       


  // To do balance_to
  // To do balance_from
  transaction_data.push_back(TransactionFile::WriteTransaction("transfer", name_from, account_number_from, amount, "")); 
  transaction_data.push_back(TransactionFile::WriteTransaction("transfer", name_to, account_number_to, amount, "")); 

  return transaction_data;              
}