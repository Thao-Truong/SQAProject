#include "iostream"
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <vector>

#include "transaction_file.h"
#include "users.h"

using namespace std;

  void TransactionFile::OutputFile(vector<string> current_transactions) {
    // Write transactions to file
    ofstream write_transaction;
    write_transaction.open("transactionfile", ios::app);

    // Iterate through transactions and output to file
    for(vector<string>::const_iterator i = current_transactions.begin(); i != current_transactions.end(); ++i) {
        write_transaction << *i << endl;
    }

    write_transaction.close();
  }

  string TransactionFile::WriteTransaction(string trans, string name, string number, string balance, string misc) {
    string transaction = "";

    // format transaction code
    transaction += FormatTransactionCode(trans);

    //format account holder's name
    transaction += FormatAccountName(name);

    // format account number
    transaction += FormatAccountNumber(number);

    // format balance
    transaction += FormatBalance(balance);

    // format miscallaneous
    transaction += FormatMiscellaneous(misc);

    return transaction;
  }

  string TransactionFile::FormatTransactionCode(string transaction) {
    if (!transaction.compare("end of session")) {
      return "00 ";
    } else if (!transaction.compare("withdrawal")) {
      return "01 ";
    } else if (!transaction.compare("transfer")) {
      return "02 ";
    } else if (!transaction.compare("paybill")) {
      return "03 ";
    } else if (!transaction.compare("deposit")) {
      return "04 ";
    } else if (!transaction.compare("create")) {
      return "05 ";
    } else if (!transaction.compare("delete")) {
      return "06 ";
    } else if (!transaction.compare("disable")) {
      return "07 ";
    } else if (!transaction.compare("changeplan")) {
      return "08 ";
    } else if (!transaction.compare("enable")) {
      return "09 ";
    } else if (!transaction.compare("login")) {
      return "10 ";
    } else {
      cout << "Transaction invalid";
      return "invalid";
    }
  }

  // Add blank space padding to make the account name 20 characters, with a space as a field seperator
  string TransactionFile::FormatAccountName(string name) {
    string final_name = name;

    for (int i = name.length(); i < 20; i++) {
      final_name += " ";
    }
    final_name += " ";
    return final_name;
  }

  // Add left aligned zeros as necessary to ensure that the account number if 5 values
  string TransactionFile::FormatAccountNumber(string number) {
    string final_number = "";

    for (int i = number.length(); i < 5; i++) {
      final_number += "0";
    }
    final_number += number;

    // field seperator
    final_number += " ";
    return final_number; 
  }

  // balance to have two values after the decimal, as well as left padding zeroes match "00000.00"
  // add space as field seperator
  string TransactionFile::FormatBalance(string balance) {
    string final_number = "";
    double num = atof(balance.c_str());

    stringstream stream;
    stream << fixed << setprecision(2) << num;
    string bal = stream.str();

    for (int i = bal.length(); i < 8; i++) {
      final_number += "0";
    }

    final_number += bal + " ";
    return final_number;
  }
 
  // Pads misc field to ensure that it's two spaces long
  string TransactionFile::FormatMiscellaneous(string misc) {
    string final_misc = misc;
    for (int i = misc.length(); i < 2; i++) {
      final_misc += " ";
    }
    return final_misc;
  }