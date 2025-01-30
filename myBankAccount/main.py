from bankAccount import bankAccount
def main():

  accounts = []
  account_num = eval(input("How many accounts do you want to enter?"))
  for i in range(account_num):
    bankName = input("What is the Bank's name?")
    accountName = input("What is the account's name?")
    accountNum = eval(input("What is the account's number?"))
    bal = eval(input("What is the account's balance?"))

    account_u = bankAccount(bankName,accountName,accountNum,bal)
    accounts.append(account_u)

  #printing the total of all accounts
  total = 0
  for account in accounts:
    total += account.balance

  print("The total of all the accounts is $"+str(total))

#searching for a specific account number
  particular_account_num = eval(input("What account number are you looking for?"))
  for account in accounts:
    if(account.account_number == particular_account_num):
      account.printAccountDetails()

  #top clients lists
  topClients = []
  for account in accounts:
    if(account.balance >= 1000):
      topClients.append(account)
      
  
main()