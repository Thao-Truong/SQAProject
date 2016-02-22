#include <iostream>
#include <string>
#ifndef USERS_H
#define USERS_H
using namespace std;

class Users {
   private:
      string accountName, accountNumber, Status, Balance, planType;
   
   public:
      string GetAccountName() {
         return accountName;
      }
      string GetAccountNumber() {
         return accountNumber;
      }
      string GetStatus() {
         return Status;
      }
      string GetBalance() {
         return Balance;
      }
      string GetPlanType() {
         return planType;
      }
      void SetAccountName(string name) {
         accountName = name;
      }
      void SetAccountNumber(string number) {
         accountNumber = number;
      }
      void SetStatus(string st) {
         Status = st;
      }
      void SetBalance(string bal) {
         Balance = bal;
      }
      void SetPlanType(string pt) { 
          planType = pt;
      }

 };
#endif