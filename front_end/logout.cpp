#include "logout.h"
#include "transaction_file.cpp"

using namespace std;

void Logout::logout(string &user) {
  TransactionFile::WriteTransaction("end of session", user, "", "", "");
  return;
}