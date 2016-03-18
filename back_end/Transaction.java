import java.io.*;

/* 
* Transaction class keeps track of each individual transaction
* and the actions in regards to it
*/
public class Transaction { 
	private String code;
	private String accountName;
	private String accountNumber;
	private String funds;
	private String misc;

	/*
	* Constructor for transaction class that takes a transaction line and 
	* stores them to the appropriate variable
	*
	* @param transactionLine - A single line from the transaction file
	*/
  public Transaction (String transactionLine){
  	code = transactionLine.substring(0, 2);
  	accountName = transactionLine.substring(3, 23);
  	accountNumber = transactionLine.substring(24, 29);
  	funds = transactionLine.substring(30, 38);
  	misc = transactionLine.substring(39, 41);
  }

  /* @return code - returns the transaction's code */
  public String getCode(){
  	return code;
  }

 /* @return accountName - returns the accountName that corresponds to the transaction */
  public String getName(){
  	return accountName;
  }

 /* @return accountNumber - returns the accountNumber that corresponds to the transaction */
  public String getNumber(){
  	return accountNumber;
  }

 /* @return funds - returns the funds that corresponds to the transaction */
  public String getFunds(){
  	return funds;
  }

 /* @return accountMisc - returns the miscallaneous data that corresponds to the transaction */
  public String getMisc(){
  	return misc;
  }
}