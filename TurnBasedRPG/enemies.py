import random
class Enemy():

  def __init__(self,name, enemy_health, low_bound_enemy_damage,top_bound_enemy_damage):
    self.n = name
    self.eh = enemy_health
    self.lbed = low_bound_enemy_damage
    self.tbed = top_bound_enemy_damage

  def describe(self):
    print("The " + self.n + " has " + str(self.eh) + " health points and does damage in between a range of " + str(self.lbed) + " to " + str(self.tbed))

  def damageDone(self):
    dd = random.randint(self.lbed,self.tbed)
    return dd

  def returnHealth(self):
    return self.eh

  def returnName(self):
    return self.n
