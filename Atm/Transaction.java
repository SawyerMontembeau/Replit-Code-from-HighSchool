/**
 *
 * @author Tad Kane
 */

import java.util.Date;

public class Transaction {
    
    /**
     * The amount of this transaction.
     */
    private double amount;

    /**
     * The date and time of this transaction.
     */
    private Date timestamp;
    
    /**
     * A memo of this transaction
     */
    private String memo;
    
    /**
     * The account in which the transaction was performed.
     */
    private Account inAccount;
    
    /**
     * Create a new transaction
     * @param amount The amount transacted.
     * @param inAccount The account the transaction belongs to.
     */
    public Transaction(double amount, Account inAccount)
    {
        this.amount = amount;
        this.inAccount = inAccount;
        this.timestamp = new Date();    //produces new Date object with the current date/time.
        this.memo = "";                 // No memo on this transaction, so just set it empty.
    }
    
    //overloaded constructor. Java will choose based on instantiation parameters.
    /**
     * Create a new transaction
     * @param amount The amount transacted.
     * @param memo The memo of the transaction
     * @param inAccount The account the transaction belongs to.
     */
    public Transaction(double amount, String memo, Account inAccount)
    {
        // Instead of repeating all the assignments from the two argument constructor again,
        // simply call the two argument constructor:
        this(amount, inAccount);
        
        // Then set the memo with incoming memo String.
        this.memo = memo;    
    }
    
    /**
     * Get the amount of the transaction
     * @return the amount
     */
    public double getAmount()   {
        return this.amount;
    }
    
    /**
     * Get a string summarizing this transaction
     * @return the summary string
     */
    public String getSummaryLine()  {
        if (this.amount >=0) { // if it's a deposit >=0
            return String.format("%s : $%.02f : %s", this.timestamp.toString(), 
                    this.amount, this.memo);
        } else { // if it's a withdrawl <0
            return String.format("%s : $(%.02f) : %s", this.timestamp.toString(),   //surround a number with () in accounting means it's a negative number.
                    -this.amount, this.memo);
        }           // make this.amount negative so it won't print like this $(-40.00).
    }
}
