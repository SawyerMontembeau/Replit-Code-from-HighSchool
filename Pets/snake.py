from pets import Pet
class Snake(Pet):

  def __init__(self, name, id, price, length):
    super().__init__(name,id,price)
    self.__l = length 

  def describe(self):
    print(super().describe() +"\n a Snake who is " + str(self.__l) + " inches long")

  def speak(self):
    return "Sssssss"

  def move(self):
    return "slithers"
