#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "users.h"
#include "create_transaction.h"

using namespace std;

string CreateTransaction::Process(Users user) {
  string transaction_data = "";

  if (user.GetAccountName() != "") {   //if not admin
    return "invalid";
  }
  cout << "Account holder's name:" << endl;
  cin >> name;

  if (name.length() > 20 ) {    //20 character max length for name
    return "invalid";
  }
  cout << "Initial balance:" << endl;
  cin >> balance;
  
  if (atof(balance.c_str()) > 99999.99 ) {   //max initial balance is $99999.99
    return "invalid";
  }
  transaction_data = TransactionFile::WriteTransaction("create", name, "", "", ""); 
  return transaction_data;    
}          