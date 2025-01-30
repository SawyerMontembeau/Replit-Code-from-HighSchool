import java.util.*;
class Main {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    System.out.println("What is your first name?");
    String fn = scan.nextLine();
    System.out.println("What is your last name?");
    String ln = scan.nextLine();
    System.out.println("Your full name is "+fn+" "+ln);
  }
}