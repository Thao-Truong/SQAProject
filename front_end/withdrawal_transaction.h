#include <string>
#include "Users.cpp"


using namespace std;

//this class handles a withdrawal transaction
class WithdrawalTransaction {
   private:
      string name, account_number, amount;

   public:
      int  Process(Users user, Users* all_users);   //process a withdrawal transaction
         
};
