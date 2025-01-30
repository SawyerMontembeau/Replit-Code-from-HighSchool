class Pet():

  def __init__(self,name,id,price):
    self.__name = name
    self.id = id
    self.price = price

  def getName(self):
    return self.__name
    

  def describe(self):
    return "\nName: " + self.__name + "\nId: " + str(self.id) + "\nPrice: $" + str(self.price)

  def speak(self):
    pass

  def move(self):
    pass

  def purchase(self):
    print("Your new pet named " + self.__name + " costs $" + str(self.price))