/* Should take in the merged transaction file? */

import java.io.*;

/* Processes the transaction files and user files */
public class BackEnd {
  private String transactionFile = "transactions";
  private String userFile = "current_accounts";
  private UserAccounts userAccounts;

  /* if transfer transaction check that there are two */
  boolean transferCheck = false;



  /* Constructor for BackEnd class that calls the appropriate method to begin processing the trasactions*/
  public BackEnd() {
    processTransactions();
  }

  /* 
  * Constructor for BackEnd class that takes in the file names and stores them
  * @param transactionFile - the name of the MERGED transaction file to use
  * @param userFile - the name of the user accounts file to use
  */
  public BackEnd(String transactionFile, String userFile) {
    this.transactionFile = transactionFile;
    this.userFile = userFile;
  }


  /* 
  * Calls the appropriate classes to read in the files
  * Goes through each transaction and calls the appropriate actions
   */
  public void processTransactions() {
  	FileReader transactionsReader = getFile(transactionFile);
  	userAccounts = new UserAccounts(userFile);
    

  	try {
	  	BufferedReader br = new BufferedReader(transactionsReader);
	  	String transactionLine;

	  	// Read in each transaction line
	  	while ((transactionLine = br.readLine()) != null) {
	  		// Get Transaction Data
	  		String currentTransaction = transactionLine;

	  		Transaction transaction = new Transaction(currentTransaction);

	  		switch(transaction.getCode()) {
	  			case "01":
	  				System.out.println(transaction.getCode());
	  				withdrawal(transaction);
	  				break;
	  			case "02":
	  				System.out.println(transaction.getCode());
	  				transfer(transaction);
	  				break;
	  			case "03":
	  				System.out.println(transaction.getCode());
	  				paybill(transaction);
	  				break;
	  			case "04":
	  				System.out.println(transaction.getCode());
	  				deposit(transaction);
	  				break;
	  			case "05":
	  				System.out.println(transaction.getCode());
	  				create(transaction);
	  				break;
	  			case "06":
	  				System.out.println(transaction.getCode());
	  				delete(transaction);
	  				break;
	  			case "07":
	  				System.out.println(transaction.getCode());
	  				disable(transaction);
	  				break;
  				case "08":
	  				System.out.println(transaction.getCode());
	  				changePlan(transaction);
	  				break;
	  			case "09":
	  				System.out.println(transaction.getCode());
	  				enable(transaction);
	  				break;
	  			case "10":
	  				System.out.println(transaction.getCode());
	  				login(transaction);
	  				break;
	  			case "00":
	  				System.out.println(transaction.getCode());
	  				endOfSession(transaction);
	  				break;
	  			default:
	  				System.out.println("Invalid input");
	  		}

	  	}
  	} catch (IOException e) {
  		System.out.println("ERROR: There was an error with processing the transaction file");
  	} 

    // Generate the new currents account file
    try {
      //@param filename
      //@ param fileType
      userAccounts.writeAccounts("master_accounts.txt", "master"); //////////////////////////////////////////////////////////////////////////////// masteraccounts ame?
      userAccounts.writeAccounts("current_accounts.txt", "current");
    } catch (Exception e) {
      System.out.println("ERROR: Error");
    }

    // Generate the new master accounts file
  }

  /* 
  * Retrieves the user data and removes specified amount from their balance
	* @param transaction - currently being processed transaction
  */
  private void withdrawal(Transaction transaction) {
  	int index = userAccounts.getIndex(transaction.getNumber());
  	User currentUser = userAccounts.getUser(index);
  	float currentBalance = Float.parseFloat(currentUser.getBalance());

  	// Deduct transaction fee
  	if (currentUser.getPlan() == "S") {
  		currentBalance -= 0.05;
  	} else if (currentUser.getPlan() == "N") {
  		currentBalance -= 0.10;
  	}

  	// Deduct funds for withdrawal transaction to account
  	currentBalance -= Float.parseFloat(transaction.getFunds());
  	currentUser.setBalance(Float.toString(currentBalance));
    userAccounts.updateUser(index, currentUser);
  }

  /* 
  * Retrieves the user data and removes the specified amount from the balance, then
  * adds the specified amount to the specified account
	* @param transaction - currently being processed transaction
  */
  private void transfer(Transaction transaction) {
    int index = userAccounts.getIndex(transaction.getNumber());
    User currentUser = userAccounts.getUser(index);
    float currentBalance = Float.parseFloat(currentUser.getBalance());

    if (transferCheck == false) {
      // Deduct transaction fee
      if (currentUser.getPlan() == "S") {
        currentBalance -= 0.05;
      } else if (currentUser.getPlan() == "N") {
        currentBalance -= 0.10;
      }


      // Deduct funds for transfer transaction 
      currentBalance -= Float.parseFloat(transaction.getFunds());
      currentUser.setBalance(Float.toString(currentBalance));
      userAccounts.updateUser(index, currentUser);

      transferCheck = true;
    } else {
      // Add funds for transfer transaction 
      currentBalance += Float.parseFloat(transaction.getFunds());
      currentUser.setBalance(Float.toString(currentBalance));
      userAccounts.updateUser(index, currentUser);

      transferCheck = true;
    }
  }

  /* 
  * Retrieves the user data and removes specified amount from their balance to paybill
	* @param transaction - currently being processed transaction
  */
  private void paybill(Transaction transaction) {
  	int index = userAccounts.getIndex(transaction.getNumber());

    if (index == -1) {
      System.out.println("ERROR: Account not found");
    } else {
    	User currentUser = userAccounts.getUser(index);
    	float currentBalance = Float.parseFloat(currentUser.getBalance());

    	// Deduct transaction fee
    	if (currentUser.getPlan() == "S") {
    		currentBalance -= 0.05;
    	} else if (currentUser.getPlan() == "N") {
    		currentBalance -= 0.10;
    	}

    	// Deduct funds for paybill transaction to account
    	currentBalance -= Float.parseFloat(transaction.getFunds());
    	currentUser.setBalance(Float.toString(currentBalance));
      userAccounts.updateUser(index, currentUser);
    }
  }

  /* 
  * Retrieves the user data and adds the specified amount to their balance
	* @param transaction - currently being processed transaction
  */
  private void deposit(Transaction transaction) {
  	int index = userAccounts.getIndex(transaction.getNumber());

    if (index == -1) {
      System.out.println("ERROR: Account not found");
    } else {
    	User currentUser = userAccounts.getUser(index);
    	float currentBalance = Float.parseFloat(currentUser.getBalance());

    	// Deduct transaction fee
    	if (currentUser.getPlan() == "S") {
    		currentBalance -= 0.05;
    	} else if (currentUser.getPlan() == "N") {
    		currentBalance -= 0.10;
    	}

    	// Add funds for deposit transaction to account
    	currentBalance += Float.parseFloat(transaction.getFunds());
    	currentUser.setBalance(Float.toString(currentBalance));
      userAccounts.updateUser(index, currentUser);
    }
  }

  /* 
  * Creates a new user as specified by the create transaction
	* @param transaction - currently being processed transaction
  */
  private void create(Transaction transaction) {
  	User newUser = new User();
  	newUser.setUserName(transaction.getName());
  	newUser.setAccountNumber(transaction.getNumber()); ////////////////////////////// Is this given in the transaction file?  Or do we randomly generate it in the backend
  	newUser.setStatus("N");
  	newUser.setBalance(transaction.getFunds());
  	userAccounts.addUser(newUser);
  }

  /* 
  * Deletes a user as specified by the transaction
	* @param transaction - currently being processed transaction
  */
  private void delete(Transaction transaction) {
  	int index = userAccounts.getIndex(transaction.getNumber());
    if (index == -1) {
      System.out.println("ERROR: Account not found");
    } else {
    	userAccounts.removeUser(index);
    }
  }

  /* 
  * Retrieves the user data and sets the account to disabled
	* @param transaction - currently being processed transaction
  */
  private void disable(Transaction transaction) {
  	int index = userAccounts.getIndex(transaction.getNumber());

    if (index == -1) {
      System.out.println("ERROR: Account not found");
      } else {

    	User currentUser = userAccounts.getUser(index);

    	currentUser.setStatus("D");
      userAccounts.updateUser(index, currentUser);
    }
  }

  /* 
  * Retrieves the user data and changes the plan type
	* @param transaction - currently being processed transaction
  */
  private void changePlan(Transaction transaction) {
  	int index = userAccounts.getIndex(transaction.getNumber());

    if (index == -1) {
      System.out.println("ERROR: Account not found");
      } else {
    	User currentUser = userAccounts.getUser(index);
    	String currentPlan = currentUser.getPlan();

    	if (currentPlan == "S") {
    		currentPlan = "N";
    	} else if (currentPlan == "N") {
    		currentPlan = "S";
    	}

    	currentUser.setPlan(currentPlan);
      userAccounts.updateUser(index, currentUser);
     } 
  }

  /* 
  * Retrieves the user data and sets the account status to enabled
	* @param transaction - currently being processed transaction
  */
  private void enable(Transaction transaction) {
  	int index = userAccounts.getIndex(transaction.getNumber());
    if (index == -1) {
      System.out.println("ERROR: Account not found");
    } else {
  	 User currentUser = userAccounts.getUser(index);

    	currentUser.setStatus("A");
      userAccounts.updateUser(index, currentUser);  
    }
  }

  /* 
  * ...
	* @param transaction - currently being processed transaction
  */
  private void login(Transaction transaction) {

  }

  /* Last transaction */ 
  private void endOfSession(Transaction transaction) {

  }

	
  /* Open or initialize files */
  public FileReader getFile(String fileName) {
    // Check if file exists
    FileReader fr = null;
    // If it doesn't exist - create
    try {
      File file = new File(fileName);
      if (!file.exists()) {
      	file.createNewFile();
      }

      fr = new FileReader(file);
    } catch (FileNotFoundException e) {
      System.out.println("ERROR: " + fileName + "was not found");
      	// Err file not found message
    } catch(IOException e) {
      	System.out.println("ERROR: There was an error processing the transactions");
    }
    //Return fileReader
    return fr;
  }

  /* Initializes Backend to begin processing the transactions*/
  public static void main(String[] args) {
    BackEnd backEnd = new BackEnd();
  }
}