#include "front_end.h"
#include <iostream>
using namespace std; 

int main(int argc, char* argv[]) {
  if (argc == 3) {
  	cout << "accounts file: " << argv[1] << endl;
  	cout << "transaction file: " << argv[2] << endl;

  	FrontEnd myFrontEnd;
  	myFrontEnd.GetTransactions();
  } else {
  	cout << "Invalid Arguments" << endl;
  }  
  return 0;
}