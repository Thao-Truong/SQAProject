#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "users.cpp"
#include "paybill_transaction.h"
#include "transaction_file.h"

using namespace std;

string PaybillTransaction::Process(Users user, Users* all_users) {
  double fee, total;
  string balance;    //balance of user for an admin login
  string transaction_data = "";

  if (user.GetAccountName() == "") {  //if admin login...
    cout << "Account holder's name:" << endl;  //get account holder's name  (for admin login)
    cin.ignore();
    getline(cin, name);
  }
  for (int i = 0; i < 10; i++) {   //search for balance of account holder
    if (all_users[i].GetAccountName().compare(name) == 0) {  
      balance = all_users[i].GetBalance();
      break;
    }
  }
  cout << "Account number:" << endl;
  cin >> account_number;

  if (user.GetAccountName() != "" && account_number != user.GetAccountNumber()) {   //check if account number is valid
    return "invalid";
  }
  cout << "Company to whom bill is being paid:" << endl;
  cin >> company;

  if (company.compare("EC") != 0 && company.compare("CQ") != 0 && company.compare("TV") != 0) {  //can only accept companies EC, CQ, TV
    return "invalid";
  }
  cout << "Amount to pay:" << endl;
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
    return "invalid";
  }
  if (user.GetAccountName() != "" && total > 2000.00) {   //check if standard user does not exceed limit of $2000.00
    return "invalid.";
  }  
  transaction_data = TransactionFile::WriteTransaction("paybill", name, account_number, amount, ""); 
  return transaction_data;        
}

       
