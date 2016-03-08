#include <iostream>
#include <string>
#include <fstream>
#include "users.h"
#include "login_transaction.h"
#include "transaction_file.h"

using namespace std;

string LoginTransaction::Input(Users user, Users* all_users){
  (user.GetAccountName() == "") {
    cout << "Account holder's name:" << endl;
    cin.ignore();
    getline(cin, name);
  }
  return name;
 }

Users* LoginTransaction::GetUsers() {
  return users;
}

string LoginTransaction::GetName() {
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
      
string LoginTransaction::Login() {
  string input;
  string transaction_data = "";

  cout << "Kind of Session:\n";
  cin >> input;
  if (input.compare("standard") == 0) {
    SetKind("S");
    cout << "Account holder's name:\n";
    cin.ignore();
    getline(cin, input);
    SetName(input);
    SetAmount("00000.00");
  } else {
    SetKind("A");
    SetAmount("00000.00");
  }
  transaction_data = TransactionFile::WriteTransaction("login", GetName(), "", GetAmount(), GetKind()); 
  return transaction_data;  
}

string LoginTransaction::NextTrans() {
  string input;
  string transaction_data = "";

  cout << "Enter a Transaction:\n";
  cin >> input ;
}
/*Users LoginTransaction::ReadAccounts(string name) {
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
  } */
Users LoginTransaction::ReadAccounts(string name, string accountsFile) {
  int i = 0;
  string first, last, acct_no, status, balance, plan;
  ifstream infile;
  infile.open(accountsFile.c_str(), ios::in);
  while (1) {
    infile >> acct_no >> first >> last >> status >> balance >>plan;
    if (acct_no.compare("00000") == 0) {
      break;
    }
    users[i].SetAccountNumber(acct_no);
    users[i].SetStatus(status);
    users[i].SetBalance(balance);
    users[i].SetPlanType(plan);
    users[i].SetAccountName(first + " " + last);
    i += 1;
  }
  for (i = 0; i < 10; i++) {
    if (users[i].GetAccountName().compare(name) == 0) {
      return users[i];
    }
   }
}
    












              