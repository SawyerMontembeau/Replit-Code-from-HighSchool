/**
 *
 * @author Tad Kane
 */
import java.util.Scanner;

//import java.io.IOException;
//import jline.TerminalFactory;
//import jline.console.ConsoleReader;
 import java.lang.Object;
 
class Main {
  
    public static void main(String[] args) {
        
        // initialize Scanner object
        Scanner input = new Scanner(System.in);
        
        // init Bank object
        Bank theBank = new Bank("Kennebunk Savings Bank");
        
        // add a user to the bank which also adds a savings account.
        User aUser = theBank.addUser("Richard", "Kane", "1234");  // makes a new User object. 
        //The .addUser method of the Bank class actually calls the constructor of the User class,
        // and sends in this Bank object into the constructor. So make a Bank object, and use it ('this')
        // when making the User object.
        //We are just hardcoding info into the .addUser method, but after you debug the program, 
        // you could ask for this information from the user in the form of a Scanner object & .next
        
        // add a checking account
        Account newAccount = new Account("Checking", aUser, theBank);
        aUser.addAccount(newAccount);   //add the new checking account to the users accounts.
        theBank.addAccount(newAccount); //add the new checking account to the 
        
        User curUser;
        while(true) {
            //stay in the login prompt until login is succesful.
            curUser = Main.mainMenuPrompt(theBank, input);   
                    //pass our scanner object 'input' into the function b/c we
                    // can't have multiple scanners being used with System.in.
                                                            
            //stay in main menu until user quites.
            Main.printUserMenu(curUser, input);
            
        }
    }
    public static User mainMenuPrompt(Bank theBank, Scanner input)  {
        
        //initialize
        String userID;
        String pin;
        User authUser;
        
        //prompt the user for user id/pin combo until a correct one is reached.
        do {
            System.out.printf("\nWelcome to %s\n\n", theBank.getName());
            System.out.print("Enter user ID: ");
            userID = input.nextLine(); //new jline.ConsoleReader().readLine(new Character('*'));
            System.out.print("Enter user pin: ");
            pin = input.nextLine(); //new jline.ConsoleReader().readLine(new Character('*'));
            
            //try and get the User object corresponding to the user id & pin combo.
            authUser = theBank.userLogin(userID, pin);
            if (authUser == null) {
                System.out.println("Incorrect user id/pin combo. Please try again.");
            }
                    
        }while(authUser==null);     //Continue looping until success id/pin combo login.
        
        return authUser;
    }
    
    public static void printUserMenu(User theUser, Scanner input)   {
        
        //print a summary of the user's accounts.
        theUser.printAccountsSummary();
        
        //init
        int choice;
        
        //user menu
        do {
            System.out.printf("Welcome %s, what would you like to do? \n", theUser.getFirstName());
            System.out.println("  1) Show account transaction history");
            System.out.println("  2) Withdraw");
            System.out.println("  3) Deposit");
            System.out.println("  4) Transfer");
            System.out.println("  5) Quit");
            System.out.println();
            System.out.print("Enter a choice: ");
            choice = input.nextInt();
            
            if(choice <1 || choice >5)
                System.out.println("Invalid choice. Please choose 1-5.");
            
        }while(choice <1 || choice >5);
        
        // process the choice.
        switch(choice){
            case(1):
                Main.showTransactionHistory(theUser, input);  //showTransactionHistory() is a static method, so 
                break;                                       // just need to call the class name Atm, and not an object to use it.
            case(2):
                Main.withdrawFunds(theUser, input);
                break;
            case(3):
                Main.depositFunds(theUser, input);
                break;
            case(4):
                Main.transferFunds(theUser, input);
                break;
            case(5):
                //gobble up rest of previous input scanner
                input.nextLine();
                break;
        }
        //print the menu again as long as they don't enter 5 for a choice.
        // Use recursion to call the function again.
        if(choice != 5)
            Main.printUserMenu(theUser, input);
    }
    
    /**
     * Show the transaction history for an account.
     * @param theUser  the logged-in User object
     * @param input the Scanner object used for user input 
     */
    public static void showTransactionHistory(User theUser, Scanner input)   {
        
        int theAcctIndex;
        
        //get account whose transaction history to look at.
        do {
            System.out.printf("Enter the number (1-%d) of the account\n"+
                    "whose transactions you want to see: ",theUser.numAccounts()); // numAccounts() method returns //how many accounts the user has.
            theAcctIndex = input.nextInt()-1;    //need to subtract 1 so we get an index value. For example, if they
                                                    // entered '1' that would be the first account in the array list,
                                                    // so you would want to call index value 0, or 1-1 = 0.
            if (theAcctIndex < 0 || theAcctIndex > theUser.numAccounts())  { //numAccounts written in User class.
                System.out.println("Invalid account. Please try again.");
            }
                
        }while(theAcctIndex < 0 || theAcctIndex > theUser.numAccounts());    
        
        // print the transaction history.
        theUser.printAcctTransHistory(theAcctIndex);
    }    
    
    /**
     * Process transferring funds from one account to another
     * @param theUser   the logged-in User object
     * @param input     the Scanner object used for user input
     */
    public static void transferFunds(User theUser, Scanner input) {
        // We need to know which account we are transferring from and to.
        // Inits
        int fromAcctIndex;
        int toAcctIndex;
        double amount;
        double acctBalance;
        
        // get the account to transfer from.
        do {
            System.out.printf("Enter the number (1-%d) of the acccount that you"+
                    " want to transfer funds from: ", theUser.numAccounts());
            fromAcctIndex = input.nextInt()-1; //-1 because we want to he index value, and they are entering just the number of the account.
            if (fromAcctIndex < 0 || fromAcctIndex > theUser.numAccounts()) {
                System.out.println("Invalid entry. Please try again.");
            }
        }while(fromAcctIndex < 0 || fromAcctIndex > theUser.numAccounts());
        
        acctBalance = theUser.getAcctBalance(fromAcctIndex);
        
        // get the account to transfer to.
        do {
            System.out.printf("Enter the number (1-%d) of the acccount that you"+
                    " want to transfer funds to: ", theUser.numAccounts());
            toAcctIndex = input.nextInt()-1; //-1 because we want to he index value, and they are entering just the number of the account.
            if (toAcctIndex < 0 || toAcctIndex > theUser.numAccounts()) {
                System.out.println("Invalid entry. Please try again.");
            }
        }while(toAcctIndex < 0 || toAcctIndex > theUser.numAccounts());
        
        // get the amount to transfer
        do {
            System.out.printf("Enter the amount to transfer? (max = $%.02f) : $", acctBalance);
            amount = input.nextDouble();
            if (amount < 0)
                System.out.println("Amount must be greater than 0.");
            else if(amount > acctBalance)
                System.out.printf("Amount must not be greater than balance of $.02f.", acctBalance);
            
        }while(amount < 0 || amount > acctBalance);
        
        // finally, make the transfer
        theUser.addAcctTransaction(fromAcctIndex, -1*amount, 
                String.format("Transfer to account %s", theUser.getAcctUUID(toAcctIndex))); //subtract money from account
        theUser.addAcctTransaction(toAcctIndex, amount, 
                String.format("Transfer to account %s", theUser.getAcctUUID(fromAcctIndex))); //subtract money from account         
        
    }
    
    /**
     * Process a fund withdraw from an account
     * @param theUser   the logged-in User object
     * @param input     the Scanner object user for user input
     */
    public static void withdrawFunds(User theUser, Scanner input) {
        // Inits
        int fromAcctIndex;
        double amount;
        double acctBalance;
        String memo;
        // get the account to withdraw from.
        do {
            System.out.printf("Enter the number (1-%d) of the acccount that you"+
                    " want to WITHDRAW funds from: ", theUser.numAccounts());
            fromAcctIndex = input.nextInt()-1; //-1 because we want to he index value, and they are entering just the number of the account.
            if (fromAcctIndex < 0 || fromAcctIndex > theUser.numAccounts()) {
                System.out.println("Invalid entry. Please try again.");
            }
        }while(fromAcctIndex < 0 || fromAcctIndex > theUser.numAccounts());
        acctBalance = theUser.getAcctBalance(fromAcctIndex);
        
        // get the amount to WITHDRAW
        do {
            System.out.printf("Enter the amount to WITHDRAW (max = $%.02f) : $", acctBalance);
            amount = input.nextDouble();
            if (amount < 0)
                System.out.println("Amount must be greater than 0.");   // a negative withdraw is like a deposit.
            else if(amount > acctBalance)
                System.out.printf("Amount must not be greater than balance of $.02f.", acctBalance);
            
        }while(amount < 0 || amount > acctBalance);
        
        //gobble up rest of previous input scanner
        input.nextLine();
        
        // get the memo
        System.out.print("Enter the memo: ");
        memo = input.nextLine();
        
        // do the WITHDRAW
        theUser.addAcctTransaction(fromAcctIndex, -1*amount, memo);
    }
    
    /**
     * Process a fund deposit to an account
     * @param theUser   the logged-in User object
     * @param input     the Scanner object used for user input
     */
    public static void depositFunds(User theUser, Scanner input) {
                
         // Inits
        int toAcctIndex;
        double amount;
        double acctBalance;
        String memo;
        // get the account to withdraw from.
        do {
            System.out.printf("Enter the number (1-%d) of the acccount that you"+
                    " want to DEPOSIT funds in: ", theUser.numAccounts());
            toAcctIndex = input.nextInt()-1; //-1 because we want to he index value, and they are entering just the number of the account.
            if (toAcctIndex < 0 || toAcctIndex > theUser.numAccounts()) {
                System.out.println("Invalid entry. Please try again.");
            }
        }while(toAcctIndex < 0 || toAcctIndex > theUser.numAccounts());
        acctBalance = theUser.getAcctBalance(toAcctIndex);
        
        // get the amount to DEPOSIT
        do {
            System.out.printf("Enter the amount to DEPOSIT (max = $%.02f) : $", acctBalance);
            amount = input.nextDouble();
            if (amount < 0)
                System.out.println("Amount must be greater than 0.");   //a negative deposit is like a withdraw
//            else if(amount > acctBalance)
//                System.out.printf("Amount must not be greater than balance of $.02f.", acctBalance);
            
        }while(amount < 0);
        
        //gobble up rest of previous input scanner
        input.nextLine();
        
        // get the memo
        System.out.print("Enter the memo: ");
        memo = input.nextLine();
        
        // do the deposit
        theUser.addAcctTransaction(toAcctIndex, amount, memo);
    }
                                                
}