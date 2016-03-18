import java.io.*;
import java.util.*;

/* UserAccounts class stores all user accounts */
public class UserAccounts {
  
  private ArrayList<User> userAccounts;

  /* No argument constructor */
  public UserAccounts() {
    userAccounts = new ArrayList<User>(); 
  }

  /* 
  * Constructor for UserAccounts class
  * @param fileName - name of accounts file
  */
  public UserAccounts(String fileName) {
    userAccounts = new ArrayList<User>(); 
    try {
      File file = new File(fileName);
      if (!file.exists()) {
      	file.createNewFile();
      }

      FileReader fileReader = new FileReader(file);

      BufferedReader br = new BufferedReader(fileReader);
      String accountLine;

      /* Read in each Account line */
      while ((accountLine = br.readLine()) != null) {
        /* Get account data */
        String currentAccount = accountLine;
        User user = new User(currentAccount);
        if (user.getUserName() == "END_OF_FILE         ") {
          break;
        }
        userAccounts.add(user);
      }


    } catch (FileNotFoundException e) {
      	
      /* Error file not found message */
    } catch(IOException e) {
      /* Error Reading file */
    }
  }  
  /* 
  * Gets a User object at a given index
  * @param index - index in the arraylist
  */
  public User getUser(int index) {
    return userAccounts.get(index);
  }
  
  /* 
  * Adds a User object to arraylist
  * @param user - User object to add to arraylist
  */
  public void addUser(User user) {
    userAccounts.add(user);
  }

  /* 
  * Removes a User object from arraylist
  * @param index - index of arraylist
  */
  public void removeUser(int index) {
    userAccounts.remove(index);
  }
  
  /* 
  * Number of User objects in the arraylist
  */
  public int userCount() {
    return userAccounts.size();
  }
 
  /* 
  * Gets index of User object that contains given account number
  * @param accountNumber - user's account number
  */
  public int getIndex(String accountNumber) {
    int result = -1;
    for (int i = 0; i < userAccounts.size(); i++) {
      if (userAccounts.get(i).getAccountNumber().equals(accountNumber)) {
        result = i;
      }
    }
    return result;
  }

  /* 
  * Updates User object stored at given index in arraylist
  * @param index - index of arraylist
  * @param currentUser - User object with updated info
  */
  public void updateUser(int index, User currentUser) {
    userAccounts.set(index, currentUser);
  }

  
  public void sortAccounts() {
    Collections.sort(userAccounts, new MyUserComp());
  }

  /* 
  * Writes all the accounts stored in the arraylist to file
  * @param fileName - name of file to write accounts to
  */
  public void writeAccounts(String fileName, String type) {
    try {
      FileWriter fileWriter = new FileWriter(fileName);
      BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
      for (int i = 0; i < userAccounts.size(); i++ ) {
        if (type == "current") {
          bufferedWriter.write(userAccounts.get(i).userAccountOuput());
          bufferedWriter.newLine();
        } else if (type == "master") {
          bufferedWriter.write(userAccounts.get(i).masterAccountOuput());
          bufferedWriter.newLine();
        }
      }
      bufferedWriter.close();
    } catch(IOException ex) {
        System.out.println("Error writing to file '" + fileName + "'");
    }
  }
} 