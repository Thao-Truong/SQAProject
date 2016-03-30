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
    String[] testTransaction = new String[] {
    	"10                      00000 00000.00 A ",
    	"09 Martin Lee           00060 00000.00   ",
			"00                      00000 00000.00   "
    }

    initializeTest(testTransaction);

    try {
    	int userIndexChanged = backend.getUserAccounts().getIndex(00060);
    	String status = backend.getUserAccounts().getUser(userIndexChanged).getStatus();
    	Assert.assertEquals("Test failed - Enable", "A", status);
    } catch() {
    	System.out.println("Test Fail");
    }
  }

	@Test
  public void testLoginAdmin() {
    String[] testTransaction = new String[] {
    	"10                      00000 00000.00 A ",
			"00                      00000 00000.00   "
    }

    initializeTest(testTransaction);

    try {
    	int userIndexChanged = backend.getUserAccounts().getIndex(00010);
    	String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();
    	Assert.assertEquals("Test failed - Login Admin", "A ", backend.getSession());
    } catch() {
    	System.out.println("Test Fail");
    }
  }

	@Test
  public void testLoginStandard() {
    String[] testTransaction = new String[] {
    	"10 Emily Wilson         00000 00000.00 S ",
			"00 Emily Wilson         00000 00000.00   "
    }

    initializeTest(testTransaction);

    try {
    	int userIndexChanged = backend.getUserAccounts().getIndex(00010);
    	String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();
    	Assert.assertEquals("Test failed - Login Standard", "S ", backend.getSession());
    } catch() {
    	System.out.println("Test Fail");
    }
  }

	// @Test
 //  public void testEndOfSession() {
 //    String[] testTransaction = new String[] {
 //    	"10 Emily Wilson         00000 00000.00 S ",
	// 		"00 Emily Wilson         00000 00000.00   "
 //    }

 //    initializeTest(testTransaction);

 //    try {
 //    	int userIndexChanged = backend.getUserAccounts().getIndex(00010);
 //    	String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();
 //    	Assert.assertEquals("Test failed - WithdrawalStudent", 00500.00, balance);
 //    } catch() {
 //    	System.out.println("Test Fail");
 //    }
 //  }

	
	@Test
  public void testDecisionTrue() {
    String[] testTransaction = newString[] {
    	"10 Mark Stone           00000 00000.00 S ", 
			"01 Mark Stone           00010 00100.00   ",
			"00 Mark Stone           00000 00000.00   "
    }

    initializeTest(testTransaction);

    try {
    	int userIndexLast = backend.getUserAccounts().getIndex(00010);
    	String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();

    	Assert.assertEquals("Test failed - Test Decision True", 00400.00, balance);
    } catch() {
    	System.out.println("Test Fail");
    }
  }

  @Test
  public void testDecisionFalse() {
    String[] testTransaction = newString[] {
    	"10 Mark Stone           00000 00000.00 S ", 
			"01 Mark Stone           00010 00100.00   ",
			"00 Mark Stone           00000 00000.00   "
    }

    //Account.txt is blank
    initializeTest(testTransaction, "mergedTransaction.txt", "Account.txt");

    try {
    	// int userIndexChanged = backend.getUserAccounts().getIndex(00010);
    	// String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();

    	UserAccounts userTest = backend.getUserAccounts();

    	Assert.assertTrue("Test failed - Test Decision False", userTest == null);
    } catch() {
    	System.out.println("Test Fail");
    }
  }

  @Test
  public void testLoopZero() {
    String[] testTransaction = newString[] {};

    initializeTest(testTransaction, "mergedTransaction.txt", "masterAccount.txt");

    try {
    	int userIndexChanged = backend.getUserAccounts().getIndex(00010);
    	String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();
    	Assert.assertEquals("Test failed - Loop Zero", 01300.00, balance);
    } catch() {
    	System.out.println("Test Fail");
    }
  }

  @Test
  public void testLoopOne() {
    String[] testTransaction = newString[] {
    	"10 Jennifer Clark       00000 00000.00 S "
    };

    initializeTest(testTransaction, "mergedTransaction.txt", "masterAccount.txt");

    try {
    	int userIndexChanged = backend.getUserAccounts().getIndex(00010);
    	String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();
    	Assert.assertEquals("Test failed - Loop Once", 01500.00, balance);
    } catch() {
    	System.out.println("Test Fail");
    }
  }

  @Test
  public void testLoopTwo() {
    String[] testTransaction = newString[] {
    	"10 Jennifer Clark       00000 00000.00 S ",
			"00 Jennifer Clark       00000 00000.00   "
    };

    initializeTest(testTransaction, "mergedTransaction.txt", "masterAccount.txt");

    try {
    	int userIndexChanged = backend.getUserAccounts().getIndex(00010);
    	String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();
    	Assert.assertEquals("Test failed - LoopTwice", 01500.00, balance);
    } catch() {
    	System.out.println("Test Fail");
    }
  }

  @Test
  public void testLoopMany() {
    String[] testTransaction = newString[] {
    	"10 Jennifer Clark       00000 00000.00 S ", 
			"01 Jennifer Clark       00050 00100.00   ",
			"01 Jennifer Clark       00050 00100.00   ",
			"00 Jennifer Clark       00000 00000.00   "
    };

    initializeTest(testTransaction, "mergedTransaction.txt", "masterAccount.txt");

    try {
    	int userIndexChanged = backend.getUserAccounts().getIndex(00010);
    	String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();
    	Assert.assertEquals("Test failed - Loop Many", 01300.00, balance);
    } catch() {
    	System.out.println("Test Fail");
    }
  } 


  private void initializeTest(String[] transaction, String transName, String accName) {
    
    try {
    	PrintWriter writer = new PrintWriter(transName);

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
    
    BackEnd = new Backend(transName, accName);

  }

}
