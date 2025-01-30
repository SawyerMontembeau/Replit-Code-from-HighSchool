from car import Car
from battery import Battery
class ElectricCar(Car):
  """Child class of car class"""

  def __init__(self, y, mk, md, c, p, batteryS):
    #very first thing to do is call contructor from parent or "super" class
      #super().__init__(y, mk, md, c, p, odo, gts)
    self.year = y
    self.make = mk
    self.model = md
    self.color = c
    self.price = p
    #now assign the child class attribute[s]
    self.battery= Battery(batteryS) #attribute of the electric car is a battery object
    self.batteryCharge = 1#current charge on battery 1 = 100%

  def carDescription(self):
    print("\nYear: "+str(self.year)+"\nMake: "+self.make+"\nModel: "+self.model+"Color: "+self.color+"\nPrice: $"+str(self.price))

  def chargeLevel(self, miles):
    """Based on how many miles you've driven, calculate and change the attribute self.batteryCharge. Use the range_factor of the battery"""
    print("Your current battery Charge is " + str(self.batteryCharge))
    self.batteryCharge -= miles/(self.battery.battery_range_factor * self.battery.battery_size)
    print("You drove " + str(miles) + " miles and your charge is now " + str(self.batteryCharge))

  def chargeCar(self, chargingPoint):
    """will take in slow, fast, superfast as string, and convert it to a number, and divide that number by the battery size to get charge time. slow = 3.7 kWhs per hour, fast = 22 and superfast = 50. Base the charging time off of self.battryCharge which is the current charge level of the car"""
    chrg_spd = 0
    if(chargingPoint.upper() == "Slow"):
      chrg_spd = 3.7
      print("It will take you {0:.2f}".format(self.battery.battery_size * (1- self.batteryCharge)/chrg_spd))
    elif(chargingPoint.upper() == "Fast"):
      chrg_spd = 22
      print("It will take you {0:.2f}".format(self.battery.battery_size * (1- self.batteryCharge)/chrg_spd))
    elif(chargingPoint.upper() == "Superfast"):
      chrg_spd = 50
      print("It will take you {0:.2f}".format(self.battery.battery_size * (1- self.batteryCharge)/chrg_spd))
    else:
      print("You didn't enter the right Charging point")

    
    
    
    
    
  