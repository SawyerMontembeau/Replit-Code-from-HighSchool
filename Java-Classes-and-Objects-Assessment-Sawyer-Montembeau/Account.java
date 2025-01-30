import java.text.NumberFormat; //2a

public class Account{

private int acctNumber;  //2b
private double balance;
public String name;
private String address;
private final double RATE = 0.035;
private NumberFormat fmt = NumberFormat.getCurrencyInstance();

public Account(int an, double b, String n, String a){  //2c
  acctNumber = an;
  balance = b;
  name = n;
  address = a;
}

public double deposit(double amount){ //2d
  if(amount < 0){
    out.println("Error: Deposit amount is invalid.\nAccount Number: " + acctNumber + "\nDeposited amount: " + amount);
  }else{
    balance += amount;
  }
  return balance;
}

public double withdraw(double amount, double fee){  //2e
  amount += fee;
  if(amount < 0){
    out.println("Error: Withdraw amount is invalid.\nAccount Number: " + acctNumber + "\nWithdrawed Amount: " + amount);
  }else if(amount > balance){
    System.out.println("Error: Insufficient Funds");
  }else{
    balance -= amount;
  }
  return balance;
}

public double addInterest(){  //2f
  balance *= RATE;
  return balance;
}

public double getBalance(){ //2g
  return balance;
}

public int getAccountNumber(){  //2h
return acctNumber;
}

public String toString(){  //2i
  return (acctNumber + "\t" + name + "\t" + fmt.format(balance));
}

}