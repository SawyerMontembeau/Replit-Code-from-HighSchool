import java.util.*;
import java.util.ArrayList;

class Main {
  public static void main(String[] args) {
    
  Account acct1 = new Account(11, 1020.30, "Jeffery White", "36 Main St.");  //3a
  Account acct2 = new Account(13, 970.00, "Tom Brown", "41 Feather St.");
  Account acct3 = new Account(14, 820.40, "Alice Smith", "12 Moose Rd.");
  Account acct4 = new Account(19, 800.00, "Jane Doe", "26 Spring St.");
  Account acct5 = new Account(26, 650.50, "Bill Green", "6 River Rd.");  

  ArrayList<Account> accounts = new ArrayList<Account>(); //3b

  acct1.deposit(25.85); //3c

  double acct2Balance = acct2.deposit(500.00); //3d

  System.out.println("The balance of " + accounts.get(1).name + "'s account is: " + acct2Balance); //3e

  acct2Balance = acct2.withdraw(600,2.00);  //3f

  acct3.withdraw(800, 0.00); //3g

  for(int i = 0; i < accounts.size(); i++){   //3h
    accounts.get(i).addInterest();
    System.out.println(accounts.get(i).toString());
  }

  }
}