import java.util.*;
class Main {
  public static void main(String[] args) {
    String[] used = {"harta", "hartm", "harty"};
    UserName person2 = new UserName("mary", "hart");
    System.out.print(person2.setAvailableUserNames(used));
  }
}