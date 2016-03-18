import java.io.*;

/* User class stores info about each user's account */
public class User {
  
  private String userName;
  private String accountNumber;
  private String status;
  private String balance;
  private String plan;
  private int numTransactions = 0;
 
/* no argument constructor for User class */
  public User() {
    
  }
  /* 
  * Constructor for User class 
  * @param userLine - string to hold each user's info
  */
  public User(String userLine) {
    accountNumber = userLine.substring(0, 4);
    userName = userLine.substring(6, 25);
    status = userLine.substring(27, 27);
    balance = userLine.substring(29, 36);
    plan = userLine.substring(38, 38);
    numTransactions = userLine.substring(40, 43);
  }

  /* Get method that returns user's name */
  public String getUserName() {
    return userName;
  }

  /* Get method that returns user's account number */
  public String getAccountNumber() {
    return accountNumber;
  }

  /* Get method that returns the status of the account (A = active; D = disabled) */
  public String getStatus() {
    return status;
  }

  /* Get method that returns the user's account balance */
  public String getBalance() {
    return balance;
  }

  /* Get method that returns the user's plan type (S = student; N = non-student) */
  public String getPlan() {
     return plan;
  }

  public int getNumTransactions() {
     return numTransactions;
  }

  /* 
  * Sets the user's name
	* @param userName - user's name
  */
  public void setUserName(String userName) {
    this.userName = userName;
  }

  /* 
  * Sets user's account number
	* @param accountNumber - user's account number
  */
  public void setAccountNumber(String accountNumber) {
    this.accountNumber = accountNumber;
  }

  /* 
  * Sets the status of user's account (A = active; D = disabled) 
	* @param status - user's account status
  */
  public void setStatus(String status) {
    this.status = status;
  }

  /* 
  * Sets the user's account balance
	* @param balance - the user's account balance
  */
  public void setBalance(String balance) {
    this.balance = balance;
  }

  /* 
  * Sets the account plan type  (S = student; N = non-student)
	* @param plan - user's account plan type
  */ 
  public void setPlan(String plan) {
    this.plan = plan;
  }

  public void incNumTransactions() {
    numTransactions++;
  }
  
  /* Formats user's data to be written to current accounts file */
  public String userAccountOuput() {
    return accountNumber + " " + userName + " " + status + " " + balance + " " + plan;

  }

  /* Formats user's data to be written to the master accounts file */
  public String masterAccountOuput() {
    return accountNumber + " " + userName + " " + status + " " + balance + " " + plan + " " + numTransactions;

  }

}