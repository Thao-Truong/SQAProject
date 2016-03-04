#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>

using namespace std;

class TransactionFile{
  public:
  	static void OutputFile(vector<string> current_transactions, string transactionFile);
  	static string WriteTransaction(string trans, string name, string number, string balance, string misc);
  	static string FormatTransactionCode(string transaction);
  	static string FormatAccountName(string name);
  	static string FormatAccountNumber(string number);
  	static string FormatBalance(string balance);
  	static string FormatMiscellaneous(string misc);
  protected:
  private:
};

#endif