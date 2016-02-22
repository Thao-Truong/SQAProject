#ifndef LOGOUT_H
#define LOGOUT_H

#include <string>
#include <vector>

using namespace std;

class Logout{
  public:
  	string logout(string &user);
  	void OutputTransactions(vector<string> current_transactions);
  protected:
  private:
};

#endif