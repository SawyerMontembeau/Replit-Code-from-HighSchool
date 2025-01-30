from pets import Pet
class Dog(Pet):

  def __init__(self, name, id, price, weight):
    super().__init__(name,id,price)
    self.__w = weight 

  def describe(self):
    print(super().describe() + "\n Is a dog who weighs " + str(self.__w))

  def speak(self):
    return "Woof"

  def move(self):
    return "walks"

