#include "iostream"
#include <string>
#include <fstream>
#include <vector>
#include "Users.cpp"
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <vector>


using namespace std;
class TransactionFile {
  private:
  public:     
    static void OutputFile(vector<string> current_transactions) {
      // Write transactions to file
      ofstream write_transaction;
      write_transaction.open("transactionfile", ios::app);





      for(vector<string>::const_iterator i = current_transactions.begin(); i != current_transactions.end(); ++i) {
          // process i
          cout << *i << " "; // this will print all the contents of *features*
          write_transaction << *i << endl;
      }










      // for(int i: current_transactions) {
        
      //   write_transaction << i << endl;
        
      // }
      write_transaction.close();
    }

    static string WriteTransaction(string trans, string name, string number, string balance, string misc) {
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

    static string FormatTransactionCode(string transaction) {
      if (!transaction.compare("end of session")) {
        return "00 ";
      } else if (transaction.compare("withdrawal")) {
        return "01 ";
      } else if (transaction.compare("transfer")) {
        return "02 ";
      } else if (transaction.compare("paybill")) {
        return "03 ";
      } else if (transaction.compare("deposit")) {
        return "04 ";
      } else if (transaction.compare("create")) {
        return "05 ";
      } else if (transaction.compare("delete")) {
        return "06 ";
      } else if (transaction.compare("disable")) {
        return "07 ";
      } else if (transaction.compare("changeplan")) {
        return "08 ";
      } else if (transaction.compare("enable")) {
        return "09 ";
      } else if (transaction.compare("login")) {
        return "10 ";
      } else {
        cerr << "Transaction invalid";
        return "invalid";
      }
    }


    static string FormatAccountName(string name) {
      string final_name = name;;

      for (int i = name.length(); i < 20; i++) {
        final_name += " ";
      }
      // field seperator
      final_name += " ";

      return final_name;
    }

    static string FormatAccountNumber(string number) {
      string final_number = "";

      for (int i = number.length(); i < 5; i++) {
        final_number += "0";
      }
      final_number += number;

      // field seperator
      final_number += " ";
      return final_number; 
    }

    static string FormatBalance(string balance) {
      string final_number = "";
      double num = atof(balance.c_str());
      //num = std::setprecision(2);

      stringstream stream;
      stream << fixed << setprecision(2) << num;
      string bal = stream.str();

      for (int i = bal.length(); i < 8; i++) {
        final_number += "0";
      }

      final_number += bal;
      // field seperator
      final_number += " ";
      return final_number;
    }

    static string FormatMiscellaneous(string misc) {
      string final_misc = misc;
      for (int i = misc.length(); i < 2; i++) {
        final_misc += " ";
      }
      return final_misc;
    }
};