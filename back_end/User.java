import java.io.*;

// creates a User object that stores info about each user 
public class User {
  
  private String userName;
  private String accountNumber;
  private String status;
  private String balance;
  

  // Constructor
  // Read in line and parse it to store appropriate data
  public User(String userLine) {
    accountNumber = userLine.substring(0, 4);
    userName = userLine.substring(6, 25);
    status = userLine.substring(27, 27);
    balance = userLine.substring(29, 36);
  }
  
  public String getUserName() {
    return userName;
  }

  public String getAccountNumber() {
    return accountNumber;
  }

  public String getStatus() {
    return status;
  }
  
  public String getBalance() {
    return balance;
  }
  
  public void setUserName(String userName) {
    this.userName = userName;
  }
  
  public void setAccountNumber(String accountNumber) {
    this.accountNumber = accountNumber;
  }
  
  public void setStatus(String status) {
    this.status = status;
  }

  public void setBalance(String balance) {
    this.balance = balance;
  }
  
  // Format this user data to be written to file
  public String userAccountOuput() {
    return accountNumber + " " + userName + " " + status + " " + balance;

  }

}