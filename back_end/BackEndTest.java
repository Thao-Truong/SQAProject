import static org.junit.Assert.*;

import org.junit.Test;

public class BackEndTest {
	private BackEnd backend;
  
  // @Test
  // public void testWithdrawalStudent() {
  //   BackEnd tester = new BackEnd("transaction_withdrawal", "currrent_accounts_withdrawal");
  //   FileReader fr = new FileReader("master_accounts.txt");
  //   BufferedReader br = new BufferedReader(fr);
  //   String accountsLine = br.readLine();
  //   assertEquals("Failure...amounts are not equal", "00060.00", accountsLine.substring(29, 37));
  //   accountsLine = br.readLine();
  //   assertEquals("Failure...amounts are not equal", "00500.00", accountsLine.substring(29, 37));
  // }

  // 
	
	@Test
  public void testWithdrawalStudent() {
    String[] testTransaction = new String[] {
    	"10 Emily Wilson         00000 00000.00 S ", 
			"01 Emily Wilson         00020 00500.00   ",
			"00 Emily Wilson         00000 00000.00   "
    };

    initializeTest(testTransaction, "mergedTransactioin.txt", "masterAccount.txt");

    try {
    	int userIndexChanged = backend.getUserAccounts().getIndex(00020);
    	String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();
    	Assert.assertEquals("Test failed - WithdrawalStudent", 00500.00, balance);
    } catch() {
    	System.out.println("Test Fail");
    }
  }


  // Tests statement coverage for Withdrawal, making sure to hit the statments with a nonstudent plan and balance > 0
	@Test
  public void testWithdrawalNonStudent() {
    String[] testTransaction = new String[] {
    	"10 Mark Stone           00000 00000.00 S ", 
			"01 Mark Stone           00010 00020.00   ",
			"00 Mark Stone           00000 00000.00   "
    };

    initializeTest(testTransaction, "mergedTransaction.txt", "masterAccount.txt");

    try {
    	int userIndexChanged = backend.getUserAccounts().getIndex(00010);
    	String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();
    	Assert.assertEquals("Test failed - WithdrawalNonStudent", 00080.00, balance);
    } catch() {
    	System.out.println("Test Fail");
    }
  	
  }

	@Test
  public void testTransferStudent() {
    String[] testTransaction = new String[] {
    	"10 Emily Wilson         00000 00000.00 S ", 
			"02 Emily Wilson         00020 00100.00   ",
			"00 Emily Wilson         00000 00000.00   ",
      "10 Mark Stone           00000 00000.00 S ",
      "02 Mark Stone           00010 00100.00   ",
      "10 Mark Stone           00000 00000.00   "
    };
  }
  initializeTest(testTransaction, "mergedTransaction.txt", "masterAccount.txt");

    try {
    	int userIndexChanged = backend.getUserAccounts().getIndex(00020);
    	String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();
    	Assert.assertEquals("Test failed - TransferStudent", 00400.00, balance);
    } catch() {
    	System.out.println("Test Fail");
    }

	@Test
  public void testTransferNonStudent() {
  String[] testTransaction = new String[] {
      "10 Mark Stone           00000 00000.00 S ",
      "02 Mark Stone           00010 00200.00   ",
      "10 Mark Stone           00000 00000.00   ",
      "10 Emily Wilson         00000 00000.00 S ", 
			"02 Emily Wilson         00020 00200.00   ",
			"00 Emily Wilson         00000 00000.00   ",
		  
    };
  }  
  initializeTest(testTransaction, "mergedTransaction.txt", "masterAccount.txt");

    try {
    	int userIndexChanged = backend.getUserAccounts().getIndex(00010);
    	String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();
    	Assert.assertEquals("Test failed - TransferNonStudent", 00100.00, balance);
    } catch() {
    	System.out.println("Test Fail");
    } 
  }

	@Test
  public void testPaybillStudent() {
     String[] testTransaction = new String[] {
    	"10 Emily Wilson         00000 00000.00 S ", 
			"03 Emily Wilson         00020 00150.00   ",
			"00 Emily Wilson         00000 00000.00   "
    };

    initializeTest(testTransaction, "mergedTransaction.txt", "masterAccount.txt");

    try {
    	int userIndexChanged = backend.getUserAccounts().getIndex(00020);
    	String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();
    	Assert.assertEquals("Test failed - PayBillStudent", 00350.00, balance);
    } catch() {
    	System.out.println("Test Fail");
    }
  }

	@Test
  public void testPaybillNonStudent() {
    String[] testTransaction = new String[] {
    	"10 Mark Stone           00000 00000.00 S ", 
			"03 Mark Stone           00020 00350.00   ",
			"00 Mark Stone           00000 00000.00   "
    };

    initializeTest(testTransaction, "mergedTransaction.txt", "masterAccount.txt");

    try {
    	int userIndexChanged = backend.getUserAccounts().getIndex(00010);
    	String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();
    	Assert.assertEquals("Test failed - PayBillNonStudent", 00100.00, balance);
    } catch() {
    	System.out.println("Test Fail");
    }
  }

	@Test
  public void testDepositStudent() {
    String[] testTransaction = new String[] {
    	"10 Emily Wilson         00000 00000.00 S ", 
			"04 Emily Wilson         00020 00200.00   ",
			"00 Emily Wilson         00000 00000.00   "
    };

    initializeTest(testTransaction, "mergedTransaction.txt", "masterAccount.txt");

    try {
    	int userIndexChanged = backend.getUserAccounts().getIndex(00020);
    	String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();
    	Assert.assertEquals("Test failed - DepositStudent", 00700.00, balance);
    } catch() {
    	System.out.println("Test Fail");
    }
  }

	@Test
  public void testDepositNonStudent() {
    String[] testTransaction = new String[] {
    	"10 Mark Stone           00000 00000.00 S ", 
			"04 Mark Stone           00010 00050.00   ",
			"00 Mark Stone           00000 00000.00   "
    };

    initializeTest(testTransaction, "mergedTransaction.txt", "masterAccount.txt");

    try {
    	int userIndexChanged = backend.getUserAccounts().getIndex(00010);
    	String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();
    	Assert.assertEquals("Test failed - DepositNonStudent", 00150.00, balance);
    } catch() {
    	System.out.println("Test Fail");
    }
  }

	@Test
  public void testCreate() {   //not sure how to do the test for this, going home...will try at home...
    
  }

	@Test
  public void testDelete() {
    fail("Not yet implemented");  //not sure how to do the test for this
  }

	@Test
  public void testDisable() {       //not sure how to do the test for this
    fail("Not yet implemented");
  }

	@Test
  public void testChangePlanStudent() {  //not sure how to do the test for this
    fail("Not yet implemented");
  }

	@Test
  public void testChangePlanNonStudent() { //up to here
    fail("Not yet implemented");
  }

	@Test
  public void testEnable() {
    fail("Not yet implemented");
  }

	@Test
  public void testLoginAdmin() {
    fail("Not yet implemented");
  }

	@Test
  public void testLoginStandard() {
    fail("Not yet implemented");
  }

	@Test
  public void testEndOfSession() {
    fail("Not yet implemented");
  }

	@Test
  public void testGerneatedNumberLength() {
    fail("Not yet implemented");
  }

	@Test
  public void testGeneratedNumberDoesNotExist() {
    fail("Not yet implemented");
  }

	
	@Test
  public void testDecisionTrue() {
    fail("Not yet implemented");
  }

  @Test
  public void testDecisionFalse() {
    fail("Not yet implemented");
  }

  @Test
  public void testLoopAZero() {
    fail("Not yet implemented");
  }

  @Test
  public void testLoopAOne() {
    fail("Not yet implemented");
  }

  @Test
  public void testLoopATwo() {
    fail("Not yet implemented");
  }

  @Test
  public void testLoopAMany() {
    fail("Not yet implemented");
  }

  @Test
  public void testLoopBZero() {
    fail("Not yet implemented");
  }

  @Test
  public void testLoopBOne() {
    fail("Not yet implemented");
  }

  @Test
  public void testLoopBTwo() {
    fail("Not yet implemented");
  }

  @Test
  public void testLoopBMany() {
    fail("Not yet implemented");
  }  


  private void initializeTest(String[] transaction) {
    
    try {
    	PrintWriter writer = new PrintWriter("mergedTransactions.txt");

    	for (String trans in transaction) {
    		if (writer != null) {
    			writer.println(trans);
    		}
    	}
    	writer.close();
    	
      consoleWriter = new PrintStream(consoleFileName);
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }
    
    BackEnd = new Backend("mergedTransactions.txt", "masterAccounts.txt");

  }

}
