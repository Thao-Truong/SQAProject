#include "front_end.h"
#include <iostream>
using namespace std; 

// Used to get the arguments and call the transactions class
int main(int argc, char* argv[]) {
  if (argc == 3) {
  	FrontEnd myFrontEnd;
  	myFrontEnd.GetTransactions(argv[1], argv[2]);
  } else {
  	cout << "Invalid Arguments" << endl;
  }  
  return 0;
}