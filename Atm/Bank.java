/**
 *
 * @author Tad Kane
 */
import java.util.ArrayList;
import java.util.Random;

public class Bank {
    
    private String name;
    
    private ArrayList<User> users;
    
    private ArrayList<Account> accounts;
    
    /**
     * Create a new Bank class object with empty lists of users and accounts.
     * @param name the name of the bank.
     */
    public Bank(String name)
    {
        this.name = name;
        this.users = new ArrayList<User>();
        this.accounts = new ArrayList<Account>(); 
    }
    
    /**
     * Get the name of the bank.
     * @return the name of the bank.
     */
    public String getName() {
        return this.name;
    }
    
    /**
     * Generates a new universally unique id for a user
     * @return the uuid.
     */
    public String getNewUserUUID()
    {
        String uuid;
        Random rand = new Random();
        int length = 6;
        boolean nonUnique;
        
        //Continue looping until we get a unique user ID (uuid)
        do {
            // Generate the id number
            uuid = "";
            for(int i = 0; i<length;i++)
            {
                uuid+=((Integer)rand.nextInt(10)).toString();   //generate random number between 0 and 9, convert to Integer so we can convert to string.
            }
            //Check to see if it's unqique
//            nonUnique = false;
//            for (int j = 0; j<users.size(); j++)
//            {
//                if (uuid.equals(users.get(j)))
//                {
//                    nonUnique = true;
//                    break;
//                }
            //Or you could write the for loop like this:
            nonUnique = false;
            for (User w : users)
            {
                if(uuid.compareTo(w.getUUID())==0)      //Need to write getUUID() method.
                {
                    nonUnique = true;
                    break;
                }
            }
        }while(nonUnique);
        
        return uuid;
    }
    
    /**
     * Generates a new universally unique id for a user
     * @return the uuid.
     */
    public String getNewAccountUUID()
    {
        String uuid;
        Random rand = new Random();
        int length = 10;            //Made length 10 instead of 6 like in getNewUserUUID() b/c account #'s are typically longer 10-digit.
        boolean nonUnique;
        
        //Continue looping until we get a unique user ID (uuid)
        do {
            // Generate the id number
            uuid = "";
            for(int i = 0; i<length;i++)
            {
                uuid+=((Integer)rand.nextInt(10)).toString();   //generate random number between 0 and 9, convert to Integer so we can convert to string.
            }
            //Check to see if it's unqique
            nonUnique = false;
            for (Account a : accounts)                  //We need to look through the other Account id's, not the User id's like in getNewUserUUID()
            {
                if(uuid.compareTo(a.getUUID())==0)      //Need to write getUUID() method.
                {
                    nonUnique = true;
                    break;
                }
            }
        }while(nonUnique);
        
        return uuid;
    }
    
    /**
     * Add the incoming anAcct Account object to the Bank object accounts array list.
     * @param anAcct the account to add
     */
    public void addAccount(Account anAcct)
    {
        this.accounts.add(anAcct);
    }
    
    /**
     * Create a new User of the bank.
     * @param firstName the user's first name
     * @param lastName the user's last name
     * @param pin the user's pin
     * @return the new User object.
     */
    public User addUser(String firstName, String lastName, String pin)
    {
        // Creates a new User object and adds it to our list.
        User newUser = new User(firstName, lastName, pin, this);    // 'this' is the Bank object that is currently being used to run this addUser() method.
        
        this.users.add(newUser);// Add the newUser to your users ArrayList
        
        // Create a savings account. Banks will sign you up for a savings account when you sign up as a new user.
        // Add the new savings account to the User class accounts arraylist, and add it to the Bank accounts Arraylist.
        Account newAcct = new Account("Savings", newUser, this);
        // Add to holder and bank lists
        newUser.addAccount(newAcct);    //newUser is a User object. Use it's addAccount method to add this Account class object to the User class accounts. 
        this.accounts.add(newAcct);   //this is a Bank object. Use it's addAccount method to add this Account class object to the Bank class accounts. 
        
        return newUser;
    }
    
    /**
     * Get the User object associated with a userID and pin, if they are valid.
     * @param userID the UUID of the user to log in.
     * @param pin the pin of the user.
     * @return the User object, if the login is successful. If not successful, return null.
     */
    public User userLogin(String userID, String pin)
    {
        // Search through list of users to find the user associated with the userID
        for (User u : this.users)   //the users arraylist in the current ('this') Bank object
        
            //check that the user id is correct.
            if(u.getUUID().compareTo(userID)==0 && u.validatePin(pin))
            {
                return u;
            }
        // if we either can't find the user id, and/or the pin is wrong, then return null.
        return null;
    }
    
}