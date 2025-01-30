import java.util.ArrayList;

public class Account {
    
    /**
     * The type of of the account.  Checking, savings, etc.
     */
    private String type;
    
    /**
     * The account ID number.  This is not the users account #, but rather the account number (checking, savings, etc.)
     */
    private String uuid;
    
    /**
     * The user object that owns this account.
     */
    public User holder;
    
    /**
     * The list of transactions for this account.
     */
    private ArrayList<Transaction> transactions;
    
    //CONSTRUCTOR
    /**
     * 
     * @param type
     * @param holder
     * @param theBank
     */
    public Account(String type,User holder, Bank theBank)
    {
        // Set the acount name and holder.
        this.type = type;
        this.holder = holder;
        
        // Get new account UUID.
        uuid = theBank.getNewAccountUUID();
        
        // Initialize empty transactions to a new array list.
        transactions = new ArrayList<Transaction>();
        
    }
    
    public String getUUID()
    {
        return this.uuid;
    }    
    
    /**
     * Get summary line for the account
     * @return the string summary
     */
    public String getSummaryLine()  {
        
        // first, let's get the account's balance. Instead of having 'balance' be a
        // state variable, we can just recalculate it each time based on transaction activity.
        
        double balance = this.getBalance(); //see getBalance() written below.
        
        // format the summary line based on whether the balance is negatie or not.
        if(balance >=0) {
            return String.format("%s : $%.02f : %s", this.uuid, balance, this.type);
        } else {
            return String.format("%s : ($%.02f) : %s", this.uuid, balance, this.type);
        }   
    }
    
    /**
     * Get the balance of this account by adding the amounts of the transactions.
     * @return the balance value.
     */
    public double getBalance()  {
        double balance = 0;
        for(Transaction t : this.transactions)  {
            balance += t.getAmount();   // written in the Transaction class.
        }
        return balance;
    }
    
    /**
     * Print the transaction history of the account.
     */
    public void printTransHistory() {
        //We want to print the most recent transaction, which is actually the last
        // element of the transactions Array List. So in terms of index values,we
        //would want to call transactions.size() - 1 to get the last element of the arraylist,
        // which again, was the last one entered, or the most recent one completed.
        System.out.printf("Transaction history for account %s\n", this.uuid);
        for (int i = this.transactions.size()-1; i >= 0; i--) {
            System.out.println(this.transactions.get(i).getSummaryLine());   //getSummaryLine() written in Transactions class.
        }
            System.out.println();
        }
    
    /**
     * Add a new transaction in this account
     * @param amount    the amount transacted
     * @param memo      the transaction memo
     */
    public void addTransaction(double amount, String memo) {  // this method gets implemented in the 
                                                                // addAcctTransaction method of the User class.
        // create new transaction object and add it to our list
        Transaction newTrans = new Transaction(amount, memo, this);  // 'this' is the Account class object running this method (addTransaction)
        this.transactions.add(newTrans);
    }
    
}