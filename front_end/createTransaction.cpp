#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "users.h"

using namespace std;

class createTransaction {
  private:
    string name, account_number, balance;

  public:
    string Process(Users user) {  
           
    if (user.GetAccountName() != "") {   //if not admin
      cout << "Transaction invalid." << endl;
    }
    cout << "Account holder's name:" << endl;
    cin >> name;

    if (name.length() > 20 ) {    //20 character max length for name
      cout << "Transaction invalid." << endl;
    }
    cout << "Initial balance:" << endl;
    cin >> balance;
    if (atof(balance.c_str()) > 99999.99 ) {   //max initial balance is $99999.99
      cout << "Transaction invalid." << endl;
    }
  }
};
          