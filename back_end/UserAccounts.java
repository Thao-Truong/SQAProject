import java.io.*;
import java.util.*;

// store all user accounts
public class UserAccounts {
  
  private ArrayList<User> userAccounts;
  
  public UserAccounts() {
    userAccounts = new ArrayList<User>(); 
  }
  public UserAccounts(String fileName) {
    //read file
    //for each line, make a user and add to userAccounts 
    
    // check if file exists; if it doesn't create.
    try {
      File file = new File(fileName);
      if (!file.exists()) {
      	file.createNewFile();
      }

      FileReader fileReader = new FileReader(file);
    } catch (FileNotFoundException e) {
      	
      	// Err file not found message
    } catch(IOException e) {
      	// Err Reading file
    }
    try {
	  	BufferedReader br = new BufferedReader(fileReader);
	  	String accountLine;

	  	// Read in each Account line
	  	while ((accountLine = br.readLine()) != null) {
	  		// Get Account Data
	  		String currentAccount = accountLine;
        User user = new User(currentAccount);
        if (user.getAccountName == "END_OF_FILE         ") {
          break;
        }
        userAccounts.add(user);
      }

      } catch (Exception E) {
  		System.out.println("Error");
      }          
  }  // end constructor  
  
  public User getUser(int index) {
    return userAccounts.get(i);
  }

  public void addUser(User user) {
    userAccounts.add(user);
  }

  public void removeUser(int index) {
    userAccounts.remove(index);
  }
  
  public int userCount() {
    return userAccounts.size();
  }
 
  public int getIndex(string accountNumber) {
    for (int i = 0; i < userAccounts.size(); i++) {
      if (userAccounts.get(i).getAccountNumber == accountNumber) {
        return i;
      }
    }
  }

  public void writeAccounts(String fileName) {
    try {
      FileWriter fileWriter = new FileWriter(fileName);
      BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
      for (int i = 0; i < userAccounts.size(); i++ ) {
        bufferedWriter.write(userAccounts.get(i).userAccountOuput());
        bufferedWriter.newLine();
      }
      bufferedWriter.close();
    } catch(IOException ex) {
        System.out.println"Error writing to file '" + fileName + "'");
    }
  }
} // end class UserAccounts