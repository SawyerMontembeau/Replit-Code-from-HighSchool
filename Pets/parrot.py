from pets import Pet
class Parrot(Pet):

  def __init__(self, name, id, price, type, favFood):
    super().__init__(name,id,price)
    self.__t = type
    self.__ff = favFood 

  def describe(self):
    print(super().describe() +"\n A" 
 + self.__t + " Parrot whos favorite food is " + self.__ff)

  def speak(self):
    return "Squak!"

  def move(self):
    return "flies"

