import random
class Player():

  def __init__(self,health,weapon):
    self.h = health
    self.w = weapon

  def damageDone (self):
    damagel = 0 #lower bound for weapon damage
    damaget = 0 #top bound for weapon damage
    if(self.w == "Sword"):
      damagel = 3
      damaget = 5
    elif(self.w == "Axe"):
      damagel = 4
      damaget = 8
    elif(self.w=="Dagger"):
      damagel = 1
      damaget = 6
    elif(self.w=="Staff"):
      damagel = 2
      damaget = 10

    dd = random.randint(damagel,damaget)
    return dd

  def returnHealth(self):
    return self.h
    