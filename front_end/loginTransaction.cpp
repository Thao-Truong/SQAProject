#include <iostream>
#include <string>
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


          }

};

      
      