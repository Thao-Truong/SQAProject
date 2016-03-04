#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "users.h"
#include "disable_transaction.h"

using namespace std;

// Disables an active account and writes the transaction line
string Process(Users user) {
  #include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "users.h"
#include "disable_transaction.h"
#include "transaction_file.h"

using namespace std;

// Enables a disabled account and writes the transaction line
string DisableTransaction::Process(Users user, Users* all_users) {
  string transaction_data = "";

  if (user.GetAccountName() == "") {      //admin login
    cout << "Account holder's name:" << endl;
    cin.ignore();
    getline(cin, name);
  }
  else {
    cout << "Invalid transaction." << endl;
  }
  cout << "Enter account number:" << endl;
  cin >> account_number;

  for (int i = 0; i < 10; i++) {   // search for status of account holder
    if (all_users[i].GetAccountName().compare(name) == 0) {
      status = all_users[i].GetStatus();
      break;
    }
  }
  if (status.compare("A") == 0 ) {
    // we only write a line to the transaction file (the accounts file will be changed in the back-end)
    transaction_data = TransactionFile::WriteTransaction("disable", name, account_number, "", ""); 
    return transaction_data;
  }
  else {
    return "invalid";
  }

}       
}       