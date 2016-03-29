import static org.junit.Assert.*;

import org.junit.Test;

public class BackEndTest {
	private BackEnd backend;
  
  @Test
  public void testWithdrawalStudent() {
    BackEnd tester = new BackEnd("transaction_withdrawal", "currrent_accounts_withdrawal");
    FileReader fr = new FileReader("master_accounts.txt");
    BufferedReader br = new BufferedReader(fr);
    String accountsLine = br.readLine();
    assertEquals("Failure...amounts are not equal", "00060.00", accountsLine.substring(29, 37));
    accountsLine = br.readLine();
    assertEquals("Failure...amounts are not equal", "00500.00", accountsLine.substring(29, 37));
  }

  // 
	@Test
  public void testBackEndEmpty() {

  }

	@Test
  public void testBackEnd() {
      fail("Not yet implemented");
  }

	@Test
  public void testWithdrawalStudent() {
    fail("Not yet implemented");
  }


	@Test
  public void testWithdrawalNonStudent() {
    String[] testTransaction = newString[] {
    	"10 Mark Stone           00000 00000.00 S ", 
			"01 Mark Stone           00010 00100.00   ",
			"00 Mark Stone           00000 00000.00   "
    }

    initializeTest(testTransaction);

    try {
    	int userIndexChanged = backend.getUserAccounts().getIndex(00010);
    	String balance = backend.getUserAccounts().getUser(userIndexChanged).getBalance();
    	Assert.assertEquals("Test failed - WithdrawalNonStudent", 00400.00, balance);
    } catch() {
    	System.out.println("Test Fail");
    }
  	
  }

	@Test
  public void testTransferStudent() {
    fail("Not yet implemented");
  }

	@Test
  public void testTransferNonStudent() {
    fail("Not yet implemented");
  }

	@Test
  public void testPaybillStudent() {
    fail("Not yet implemented");
  }

	@Test
  public void testPaybillNonStudent() {
    fail("Not yet implemented");
  }

	@Test
  public void tesDepositStudent() {
    fail("Not yet implemented");
  }

	@Test
  public void testDepositNonStudent() {
    fail("Not yet implemented");
  }

	@Test
  public void testCreate() {
    fail("Not yet implemented");
  }

	@Test
  public void testDelete() {
    fail("Not yet implemented");
  }

	@Test
  public void testDisable() {
    fail("Not yet implemented");
  }

	@Test
  public void testChangePlanStudent() {
    fail("Not yet implemented");
  }

	@Test
  public void testChangePlanNonStudent() {
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
    
    BackEnd = new Backend("mergedTransactions.txt", "maserAccounts.txt");

  }

}
