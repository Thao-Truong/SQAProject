import java.io.*;

// Processes the transaction files and user files
public class BackEnd {
  private String transactionFile = "transactions";
  private String userFile;

  // Constructor
  public BackEnd() {
    processTransactions();
  }

  // Constructor
  public BackEnd(String transactionFile, String userFile) {
    this.transactionFile = transactionFile;
    this.userFile = userFile;
  }


  // Processes transactions
  public void processTransactions() {
  	FileReader transactionsReader = getFile(transactionFile);

  	try {
	  	BufferedReader br = new BufferedReader(transactionsReader);
	  	String transactionLine;

	  	// Read in each transaction line
	  	while ((transactionLine = br.readLine()) != null) {
	  		// Get Transaction Data
	  		String currentTransaction = transactionLine;

	  		Transaction transaction = new Transaction(currentTransaction);

	  		if (transaction.getCode() == "00") {
	  			//process transaction
	  		} 
	  		System.out.println(transactionLine);
	  	}
  	} catch (Exception E) {
  		System.out.println("err");
  	}
  }

	
  // Open or initialize files
  public FileReader getFile(String fileName) {
    // Check if file exists
    FileReader fr = null;
    // If it doesn't exist - create
    try {
      File file = new File(fileName);
      if (file.exists()) {
      	fr = new FileReader(fileName);
      } else {
      	file.createNewFile();
      }
    } catch (FileNotFoundException e) {
      	
      	// Err file not found message
    } catch(IOException e) {
      	// Err Reading file
    }
    //Return fileReader
    return fr;
  }

  public static void main(String[] args) {
    BackEnd backEnd = new BackEnd();
  }
}