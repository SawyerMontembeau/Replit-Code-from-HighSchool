import java.util.*;
class Main {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    System.out.println("Enter the name of who the account belongs to");
    String name = scan.nextLine();

    System.out.println("Enter the initial balance of the account");
    double iBalance = scan.nextDouble();

    BankAccount myAccount = new BankAccount(iBalance, name);
    myAccount.deposit(505.22);
    System.out.println(myAccount.balance);
    myAccount.withdraw(100);

    System.out.println("The " + name + " Account balance is $" + myAccount.balance);
  }
}