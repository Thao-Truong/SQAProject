#include <string>
#include "Users.h"

using namespace std;

  string Users::GetAccountName() {
    return account_name;
  }
  string Users::GetAccountNumber() {
    return account_number;
  }
  string Users::GetStatus() {
    return status;
  }
  string Users::GetBalance() {
    return balance;
  }
  string Users::GetPlanType() {
    return planType;
  }
  void Users::SetAccountName(string name) {
    account_name = name;
  }
  void Users::SetAccountNumber(string number) {
    account_number = number;
  }
  void Users::SetStatus(string st) {
    status = st;
  }
  void Users::SetBalance(string bal) {
    balance = bal;
  }
  void Users::SetPlanType(string pt) { 
    planType = pt;
  }

 
#endif