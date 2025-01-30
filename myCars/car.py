"""A Module that contains the car class"""

class Car():
  """A simple attempt to represent a car"""

  wheels = 4
#constructor
  def __init__(self, y, mk, md, c, p, odo, gts):
    """This special kind of method initializes attributes to describe a car"""
    self.year = y #int
    self.make = mk #string
    self.model = md #string
    self.color = c #string
    self.price = p #double/float
    self.feul_level = 0 #double/float
    self.odometer_reading = odo #double/float
    self.gas_tank_size = gts #double/float

  def get_description(self):
    """return all the values of the objects attributes"""
    descrip = "Year: "+str(self.year)+"\nMake: "+self.make+"\nModel: "+self.model+"Color: "+self.color+"\nPrice: $"+str(self.price)+"\nFeul Level: "+str(self.feul_level)+"\nOdometer Reading: "+str(self.odometer_reading)+"\nGas Tank Size: "+str(self.gas_tank_size)
    return descrip

  def read_odometer(self):
    """Print a statement showing the car's current mileage/odometer reading. One line of code"""
    print("this car has " + str(self.odometer_reading) + " miles on it.")

  def update_odometer(self,mileage):
    """Set the odometer reading to the given value. Reject if smaller than original"""
    if mileage < self.odometer_reading:
      print("The milage you entered is less than the current mileage")
    else:
      self.odometer_reading = mileage

  def increment_odometer(self, miles):
    """increase odometer miles by new miles driven"""
    self.odometer_reading += miles

  def feul_up(self):
    self.feul_level = self.gas_tank_size

  def get_gas(self, gallons):
    if(self.feul_level + gallons > self.gas_tank_size):
      print("That is too much gas, the tank will overflow")
    else:
      self.feul_level += gallons

  def change_color(self, color):
    if(self.color.Upper() == color.Upper()):
      print("That is the same color as it already was")
    else:
      self.color = color
    
