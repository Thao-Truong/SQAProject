#include "logout.h"
#include "transaction_file.h"
#include <string>
#include <vector>

using namespace std;

string Logout::LogoutTransaction(string &user) {
  string transaction_data;

  transaction_data = TransactionFile::WriteTransaction("end of session", user, "", "", "");
  return transaction_data;
}

void Logout::OutputTransactions(vector<string> current_transactions, string transactionFile) {
  TransactionFile::OutputFile(current_transactions, transactionFile);
  return;
}