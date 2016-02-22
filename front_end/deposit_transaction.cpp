#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Users.cpp"

using namespace std;
  
int DepositTransaction::Process(Users user, Users* all_users) {
  double fee, total;
  string balance;    //balance of user for an admin login
  if (user.GetAccountName() == "") {
    cout << "Account holder's name:" << endl;
    cin.ignore();
    getline(cin, name);
  }
  for (int i = 0; i < 10; i++) {
    if (all_users[i].GetAccountName().compare(name) == 0) {
      balance = all_users[i].GetBalance();
      break;
    }
  }
  cout << "Account number:" << endl;
  cin >> account_number;
  if (user.GetAccountName() != "" && account_number != user.GetAccountNumber()) {
    return -1;
  }
  cout << "Amount to Deposit:" << endl;
  cin >> amount;                  
  if (user.GetAccountName() != "") {
    name = user.GetAccountName();
  }

  if (user.GetStatus() == "S") {
    fee = .05;
  }
  else if (user.GetStatus() == "N") {
    fee = .10;
  }
  else {
    fee = 0;
  }
  total = atof(amount.c_str()) - fee;     
            
  }        
}
