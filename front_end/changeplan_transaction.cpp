#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "users.h"
#include "changeplan_transaction.h"
#include "transaction_file.h"

using namespace std;

// Changes plan from N to S (and vice-versa) and writes the transaction line
string ChangePlanTransaction::Process(Users user, Users* all_users) {

  string transaction_data = "";

  if (user.GetAccountName() == "") {      //admin login
    cout << "Account holder's name:" << endl;
    cin.ignore();
    getline(cin, name);
  }
  else {
    cout << "Invalid transaction." << endl;
    return "invalid";
  }
  cout << "Enter account number:" << endl;
  cin >> account_number;

  for (int i = 0; i < 10; i++) {   // search to ensure name and account number exist before writing transaction
    if (all_users[i].GetAccountName().compare(name) == 0 && all_users[i].GetAccountNumber().compare(account_number) == 0) {
      // we only write a line to the transaction file (actual change to account will occur in the back-end)
      transaction_data = TransactionFile::WriteTransaction("changeplan", name, account_number, "", ""); 
      return transaction_data;
    }
  }
  return "invalid";
}       