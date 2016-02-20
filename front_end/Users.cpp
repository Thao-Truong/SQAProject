#include <iostream>
#include <string>

class Users {
   private:
      String accountName, accountNumber, Status, Balance, planType;
   
   public:
      String getAccountName() {
         return accountName;
      }
      String getAccountNumber() {
         return accountNumber;
      }
      String getStatus() {
         return Status;
      }
      String getBalance() {
         return Balance;
      }
      String getPlanType() {
         return planType;
      }
      void setAccountName(name) {
         accountName = name;
      }
      void setAccountNumber(number) {
         accountNumber = number;
      }
      void setStatus(st) {
         Status = st;
      }
      void setBalance(bal) {
         Balance = bal;
      }
      void setPlanType(pt) {
          planType = pt;
      }

 };
