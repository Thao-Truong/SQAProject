#ifndef LOGOUT_H
#define LOGOUT_H

#include <string>
#include <vector>

using namespace std;

class Logout{
  public:
  	string LogoutTransaction(string &user);
  	void OutputTransactions(vector<string> current_transactions, string transactionFile);
  protected:
  private:
};

#endif