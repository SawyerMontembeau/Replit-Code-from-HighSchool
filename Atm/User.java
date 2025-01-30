/**
 *
 * @author Tad Kane
 */
import java.util.ArrayList;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.logging.Level;
import java.util.logging.Logger;


public class User {
    
    //The user's first name.
    public String firstName;
            
    //The user's last name.
    public String lastName;
    
    //The ID number of the user.
    public String uuid;
    
    //The MD5 hash of the user's pin number.
    private byte pinHash[];
    
    //The list of accounts for this user.
    private ArrayList<Account> accounts;
    
    // Constructor
    /*****
     * Create a new User.
     * @param first The user's first name.
     * @param last  The user's last name.
     * @param pin   The user's account pin number.
     * @param theBank The Bank object that the user is a customer of.
     */
    
    public User(String first, String last, String pin, Bank theBank)   //Note that the Bank class has an Account accounts state variable.
    {
        //SET USER'S NAME
        firstName = first;
        lastName = last;
        
        //STORE THE 'pin' MD5 HASH, RATHER THAN THE ORIGINAL VALUE FOR SECURITY REASONS.
        
        // The String object 'pin' is represented by a number of bytes or a byte string or an array of bytes
        try {                              // We are taking the bytes from our 'pin' parameter String object, and we are "digesting" them 
            MessageDigest md = MessageDigest.getInstance("MD5");    //use the digest() method from the MessageDigest class.
            pinHash = md.digest(pin.getBytes());                    //We take the String parameter 'pin' and get its byte representation through the MD5 algorithm.
        } catch (NoSuchAlgorithmException ex) {                     //This will give us a new array of bytes that we store in the state variable 'pinHash'.
            System.err.println("error, caught NoSuchAlgorithmException.");
            Logger.getLogger(User.class.getName()).log(Level.SEVERE, null, ex);
            System.exit(1);
        }
        
        //GET A NEW, UNIQUE UNIVERSAL ID NUMBER FOR THE USER.
        this.uuid = theBank.getNewUserUUID();
        
        //CREATE EMPTY LIST OF ACCOUNTS.
        this.accounts = new ArrayList<Account>();
        
        //PRINT LOG MESSAGE
        System.out.printf("New user %s, %s user with ID %s created.\n", lastName, firstName, uuid);      
            
    }
    
    /**
     * Return the user's first name.
     * @return first name.
     */
    public String getFirstName() {
        return this.firstName;
    }
    /**
     * getter method to return the private state variable uuid, 
     * Called in Bank class inside getNewUserUUID() method. 
     * @return uuid
     */
    public String getUUID()
    {
        return this.uuid;
    }
    
    /**
     * Add an account for the user.
     * @param anAcct the account to add.
     */
    public void addAccount(Account anAcct)
    {
        this.accounts.add(anAcct);
    }           
    
    /**
     * Check whether the given pin matches the true user's pin.
     * @param aPin the pin to check
     * @return whether the pin is valid or not.
     */
    public boolean validatePin(String aPin)
    {
        try {                              
            MessageDigest md = MessageDigest.getInstance("MD5");   
            // Compare the User object's pinHash to the pin hash created by md.digest(for the incoming aPin).
            return MessageDigest.isEqual(this.pinHash, md.digest(aPin.getBytes())); 
                               
        } catch (NoSuchAlgorithmException ex) {                     
            System.err.println("error, caught NoSuchAlgorithmException.");
            Logger.getLogger(User.class.getName()).log(Level.SEVERE, null, ex);
            System.exit(1);
        }
        
        return false;   // We just need to include this return statement because the we specified a return to the method.        
    }                   // Java needs to see a return after the try catch, even though we know the try catch will return what we want. Just java housekeeping here. 
    
    /**
     * Print summaries for the accounts of this user.
     */
    public void printAccountsSummary()  {
        System.out.printf("\n\n%s's accounts summary.\n",this.firstName);
        for (int i = 0; i < this.accounts.size(); i++)
        {
            System.out.printf("  %d) %s\n", i+1, this.accounts.get(i).getSummaryLine());  // getSummaryLine() written in Accounts class.
        }
        System.out.println();
    }
    
    /**
     * Get the number of accounts of the user.
     * @return number of accounts.
     */
    public int numAccounts()    {
        return this.accounts.size();
    }
    
    /**
     * Print transaction history for a particular account.
     * @param acctIndex the index of the account to use.
     */
    public void printAcctTransHistory(int acctIndex)    {
        this.accounts.get(acctIndex).printTransHistory();   //We really want this account transaction history
                                                            // printing from the Account class. so we will write
    }                                                       //printTransHistory() method in the Accounts class.

    /**
     * Get the balance of a particular account
     * @param acctIndex the index of the account to use
     * @return balance of the particular account
     */
    public double getAcctBalance(int acctIndex) {
        return this.accounts.get(acctIndex).getBalance();
    }
    
    /**
     * Get the UUID of a particular account
     * @param acctIndex the index of the account to use
     * @return          the UUID of the account
     */
    public String getAcctUUID(int acctIndex) {
        return this.accounts.get(acctIndex).getUUID();
    }
    
    public void addAcctTransaction(int acctIndex, double amount, String memo) {
        this.accounts.get(acctIndex).addTransaction(amount, memo);  //addTransaction written in Accounts class
    }
}