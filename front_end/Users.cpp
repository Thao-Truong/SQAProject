#include <iostream>
#include <string>

using namespace std;

class Users {
   private:
      string accountName, accountNumber, Status, Balance, planType;
   
   public:
      string getAccountName() {
         return accountName;
      }
      string getAccountNumber() {
         return accountNumber;
      }
      string getStatus() {
         return Status;
      }
      string getBalance() {
         return Balance;
      }
      string getPlanType() {
         return planType;
      }
      void setAccountName(string name) {
         accountName = name;
      }
      void setAccountNumber(string number) {
         accountNumber = number;
      }
      void setStatus(string st) {
         Status = st;
      }
      void setBalance(string bal) {
         Balance = bal;
      }
      void setPlanType(string pt) { 
          planType = pt;
      }

 };
