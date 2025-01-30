class Property():
  """A Class that models a property in monopoly"""

  def __init__(self, space, name, price, color, rent, cHotel,rHotel, value):
    self.space = space
    self.name = name
    self.price = price
    self.bought = False
    self.color = color
    self.rent = rent
    self.cHotel = cHotel
    self.rHotel = rHotel
    self.value = value

  def buy(self):
    return self.price

  def get_description(self):
    print("Property:",self.name,"\nPrice:",str(self.price),"\nBought?",self.bought)

class Player():
  def __init__(self, piece):
    self.piece = piece
    self.money = 1500
    self.space = 0
    self.properties = []

  def buy(self,property):
    self.money -= property.price