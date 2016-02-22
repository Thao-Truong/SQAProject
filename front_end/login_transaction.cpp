#include <iostream>
#include <string>
#include <fstream>
#include "Users.cpp"
#include "login_transaction.h"

using namespace std;

Users* LoginTransaction::GetUsers() {
  return users;
}

string LoginTransaction::getName() {
  return name;
}
     
string LoginTransaction::GetKind() {
  return kind;
}
      
string LoginTransaction::GetAmount() {
  return amount;
}
void LoginTransaction::SetName(string nme) {
  name = nme;
}   
void LoginTransaction::SetKind(string knd) {
  kind = knd;
} 
void LoginTransaction::SetAmount(string amt) {
  amount = amt;
}
      
void LoginTransaction::Login() {
  string input;
  cout << "Kind of Session:\n";
  cin >> input;
  if (input.compare("standard") == 0) {
    SetKind("S");
    cout << "Account Holder's Name:\n";
    cin.ignore();
    getline(cin, input);
    SetName(input);
    SetAmount("00000.00");
  }
  else {
    SetKind("A");
    SetAmount("00000.00");
  }
}
Users LoginTransaction::ReadAccounts(string name) {
  int i = 0;
  string first, last, acct_no, status, balance, plan;
  ifstream infile;
  infile.open("accountsFile", ios::in);
  while (1) {
    infile >> acct_no >> first >> last >> status >> balance >> plan;
    users[i].SetAccountNumber(acct_no);
    users[i].SetStatus(status);
    users[i].SetBalance(balance);
    users[i].SetPlanType(plan);
    users[i].SetAccountName(first + " " + last);
    if (users[i].GetAccountName().compare(name) == 0) {
      return users[i];
    }  
    if (users[i].GetAccountNumber().compare("00000") == 0) {
      users[i].SetAccountName("");
      users[i].SetAccountNumber("");
      users[i].SetStatus("");
      users[i].SetBalance("");
      users[i].SetPlanType("");
      return users[i];
    }
    i += 1;
  }
}           
                
        