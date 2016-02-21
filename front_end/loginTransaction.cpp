#include <iostream>
#include <string>
#include <fstream>
#include "Users.cpp"

using namespace std;


class loginTransaction {
   private:
      string amount;
      string name, kind;
   public:
      string getName() {
         return name;
      }
     
     
      string getKind() {
         return kind;
      }
      
      string getAmount() {
          return amount;
      }
      void setName(string nme) {
          name = nme;
      }
      
      
      void setKind(string knd) {
          kind = knd;
      }
      
      
      void setAmount(string amt) {
          amount = amt;
      }
      
      
      void login() {
         string input;
         cout << "Kind of Session:\n";
                cin >> input;
                if (input.compare("standard") == 0) {
                   setKind("S");
                   cout << "Account Holder's Name:\n";
                   cin.ignore();
                   getline(cin, input);
                   setName(input);
                   setAmount("00000.00");
                   
                 }
                else {
                   setKind("A");
                }
                
                
         }

         void writeTransaction() {
             cout << "10" << " " << getName() << "               " << getAmount() << " " << getKind() << endl;
          }
         
         void readAccounts() {
             Users users[10];
             int i = 0;
             string first, last, acctNo, status, balance, plan;
             ifstream infile;
             infile.open("accountsFile", ios::in);
             while (1) {
                infile >> acctNo >> first >> last >> status >> balance >> plan;
                users[i].setAccountNumber(acctNo);
                users[i].setStatus(status);
                users[i].setBalance(balance);
                users[i].setPlanType(plan);
                users[i].setAccountName(first + " " + last);

                if (users[i].getAccountNumber().compare("00000") == 0) {
                   users[i].setAccountName("");
                   users[i].setAccountNumber("");
                   users[i].setStatus("");
                   users[i].setBalance("");
                   users[i].setPlanType("");
                   break;
                }
                i += 1;
              }
              for (i = 0; i < 10; i++) {
                  cout << users[i].getAccountName() << endl;
              }
                
         


          }

};

      
      