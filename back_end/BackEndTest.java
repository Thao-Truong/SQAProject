import static org.junit.Assert.*;

import org.junit.Test;

public class BackEndTest {
  
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

	@Test
    public void testBackEndEmpty() {
        fail("Not yet implemented");
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
        fail("Not yet implemented");
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




}
