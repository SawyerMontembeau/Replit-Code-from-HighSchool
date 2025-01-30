class Battery():
  """models an EV car battery"""
  def __init__(self,bs):
    self.battery_size = bs
    self.battery_range_factor = 3.3

  def describe_battery(self):
    print("This has a "+ str(self.battery_size) + "-kW battery.")

  def get_range(self):
    "Tells how far the battery can go based on the size and range factor"
    message = "This car can go approximately {0,.1f} miles on a single charge".format(self.battery_size * self.battery_range_factor)
    print(message)

  
