class bankAccount():

  def  __init__(self,bn,an,anu,b):
    self.bank_name = bn #string
    self.account_name = an #string
    self.account_number = anu #int
    self.balance = b #double/float

  def deposit(self,balance,amount):
    self.balance += amount

  def withdraw(self, balance, amount):
    self.balance -= amount

  def printAccountDetails(self):
    print("\nBank Name: " + self.bank_name + "\nAccount Name: " + self.account_name + "\nAccount Number: " + str(self.account_number) + "\nBalance: $" + str(self.balance))

  