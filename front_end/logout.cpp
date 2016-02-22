#include "logout.h"
#include "transaction_file.cpp"
#include <string>
#include <vector>

using namespace std;

string Logout::logout(string &user) {
  string transaction_data;

  transaction_data = TransactionFile::WriteTransaction("end of session", user, "", "", "");
  return transaction_data;
}

void Logout::OutputTransactions(vector<string> current_transactions) {
  TransactionFile::OutputFile(current_transactions);
  return;
}