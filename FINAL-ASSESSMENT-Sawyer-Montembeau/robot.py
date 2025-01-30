class Robot():

  def __init__(self,name,wheel_diameter):
    self.name = name
    self.wheel_diameter = wheel_diameter

  def describe(self):
    print("\nNAME: " + self.name + "\nWHEEL DIAMETER: " + str(self.wheel_diameter))

  def rotations(self,distance):
    circumference = self.wheel_diameter * 3.14
    rot_num = distance/circumference
    return(rot_num)