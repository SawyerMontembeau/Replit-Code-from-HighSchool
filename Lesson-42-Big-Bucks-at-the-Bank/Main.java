import java.io.*;
import java.util.*;
import java.text.*;
class Main {
  public static void main(String[] args) {
NumberFormat formatter = NumberFormat.getNumberInstance();
formatter.setMinimumFractionDigits(2);
formatter.setMaximumFractionDigits(2);
String name;  

ArrayList aryLst = new ArrayList();

do
{
Scanner kbReader = new Scanner(System.in);
System.out.print("Please enter the name to whom the account belongs.(\"Exit\" to abort)");

name = kbReader.nextLine( );
if( !name.equalsIgnoreCase("EXIT") )
{
System.out.print("Please enter the amount of the deposit. ");
double amount = kbReader.nextDouble();
System.out.println(" "); //gives an eye-pleasing blank line

BankAccount account = new BankAccount(name, amount);
aryLst.add(account);

}

}while(!name.equalsIgnoreCase("EXIT"));
//Search aryList and print out the name and amount of the largest bank account
BankAccount ba = aryLst.get(0);
double mBalance = ba.balance;
String mName = ba.name;

for(int j = 1; j < aryLst.size( ); j++)
{
BankAccount bnka = aryLst.get(j);   
double bal = bnka.balance;
String na = bnka.name;
if(bal > mBalance)
{
mBalance = bal;
mName = na;
}
}
System.out.println("The bank account with the most money is " + mName + "'s.");
System.out.println("The account has $" + mBalance);
  }
}