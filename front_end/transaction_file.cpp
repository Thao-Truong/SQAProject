#include "iostream"
#include <string>
#include <fstream>
#include <vector>
#include "Users.cpp"

using namespace std;
/*

10                            00000.00 A 
01 Cindy Rosen          00040 00495.00   
00                            00000.00   


*/

class TransactionFile {
  private:
  public:     
    static void WriteTransaction(string code, string name, string number, string balance, string misc) {
      string transaction = "";

      // format transaction code

      //transaction += FormatTransactionCode(code);

      //format account holder's name
      transaction += name;

      // format account number
      transaction += number;

      // format balance
      transaction += balance;

      // format miscallaneous
      transaction += misc;

      // Write transactions to file
      ofstream write_transaction;
      write_transaction.open("transactionfile", ios::app);
      write_transaction << transaction << endl;
      write_transaction.close();
      
      return;
    }

    // void FormatTransactionCode() {
    //   if (!action.compare("end of session")) {
    //     return "00";
    //   } else if (!action.compare("withdrawal")) {
    //     return "01";
    //   } else if (!action.compare("transfer")) {
    //     return "02";
    //   } else if (!action.compare("paybill")) {
    //     return "03";
    //   } else if (!action.compare("deposit")) {
    //     return "04";
    //   } else if (!action.compare("create")) {
    //     return "05";
    //   } else if (!action.compare("delete")) {
    //     return "06";
    //   } else if (!action.compare("disable")) {
    //     return "07";
    //   } else if (!action.compare("changeplan")) {
    //     return "08";
    //   } else if (!action.compare("create")) {
    //     return "09";
    //   } else if (!action.compare("create")) {
    //     return "10";
    //   } else {

    //     cerr << "ERROR: Invalid action name. Please refer to the project decription for action names.\n";
    //     return "INVALID";
    //   }
    // }



/*


00
-
end of sessio
*/








};