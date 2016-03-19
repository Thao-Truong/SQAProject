import java.util.*;

/* MyUserComp class is used by the sorting function in UserAccounts.java */
class MyUserComp implements Comparator<User> {
  
  @Override
  public int compare(User u1, User u2) {
    if (Integer.parseInt(u1.getAccountNumber()) > Integer.parseInt(u2.getAccountNumber())) {
      return 1;
    } else {
        return -1;
    }
  }
}