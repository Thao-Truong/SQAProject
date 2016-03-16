import java.io.*;

/* Processes the transaction files and user files */
public class BackEnd {
  private String transactionFile = "transactions";
  private String userFile = "current_accounts";

  /* Constructor for BackEnd class that calls the appropriate method to begin processing the trasactions*/
  public BackEnd() {
    processTransactions();
  }

  /* 
  * Constructor for BackEnd class that takes in the file names and stores them
  * @param transactionFile - the name of the transaction file to use
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
  	// UserAccounts userAccounts = new UserAccounts(userFile);

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
	  				withdrawal();
	  				break;
	  			case "02":
	  				System.out.println(transaction.getCode());
	  				transfer();
	  				break;
	  			case "03":
	  				System.out.println(transaction.getCode());
	  				paybill();
	  				break;
	  			case "04":
	  				System.out.println(transaction.getCode());
	  				deposit();
	  				break;
	  			case "05":
	  				System.out.println(transaction.getCode());
	  				create();
	  				break;
	  			case "06":
	  				System.out.println(transaction.getCode());
	  				delete();
	  				break;
	  			case "07":
	  				System.out.println(transaction.getCode());
	  				disable();
	  				break;
  				case "08":
	  				System.out.println(transaction.getCode());
	  				changePlan();
	  				break;
	  			case "09":
	  				System.out.println(transaction.getCode());
	  				enable();
	  				break;
	  			case "10":
	  				System.out.println(transaction.getCode());
	  				login();
	  				break;
	  			case "00":
	  				System.out.println(transaction.getCode());
	  				endOfSession();
	  				break;
	  			default:
	  				System.out.println("Invalid input");
	  		}

	  	}
  	} catch (Exception E) {
  		System.out.println("Error");
  	}
  }

  /*  */
  private void withdrawal() {

  }

  /* */
  private void transfer() {

  }

  /* */
  private void paybill() {

  }

  /* */
  private void deposit() {

  }

  /* */
  private void create() {

  }

  /* */
  private void delete() {

  }

  /* */
  private void disable() {

  }

  /* */
  private void changePlan() {

  }

  /* */
  private void enable() {

  }

  /* */
  private void login() {

  }

  /* Last transaction */ 
  private void endOfSession() {

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
      	
      	// Err file not found message
    } catch(IOException e) {
      	// Err Reading file
    }
    //Return fileReader
    return fr;
  }

  /* Initializes Backend to begin processing the transactions*/
  public static void main(String[] args) {
    BackEnd backEnd = new BackEnd();
  }
}