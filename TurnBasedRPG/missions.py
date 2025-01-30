from enemies import Enemy
from players import Player
import random
class Mission():

  def __init__(self, location, num, enemy_n, enemy_h, enemy_lbed, enemy_tbed, p_health, p_weapon, reward):
    self.l = location
    self.n = num
    self.enemy = Enemy(enemy_n,enemy_h,enemy_lbed,enemy_tbed)
    self.player = Player(p_health,p_weapon)
    self.r = reward

  def describeMission(self):
    print("\nMission #" + str(self.n) + " takes place in the " + self.l + ". The enemies you will encounter are " + self.enemy.returnName() + "s. The reward for completing the mission is " + str(self.r) + " gold\n")

  def giveReward(self):
    return self.r


  def fight(self):
    f_options = ["fight","item","defend"]
    thealth = self.player.returnHealth()
    h = thealth #displays total health
    tenemy_health = self.enemy.returnHealth()
    eh = tenemy_health #displayes total enemy health
    en = self.enemy.returnName()
    #detect when player or enemy dies
    dead = False
    enemyDead = False
    if(h <= 0):
      dead = True
      #print("\nYOU DIED\n")  NOT WORKING YET
    if(eh <=0):
      enemyDead = True
      #print("\nYOU WON\n")   NOT WORKING YET

     #need to end fight when player or enemy health <= 0
    if(dead != True and enemyDead != True):
      while(h > 0 and eh > 0):
        print("\n"+en.upper()+" HEALTH = "+str(eh)+"/"+str(tenemy_health))
        print("\nYOU\tHEALTH = "+str(h)+"/"+str(thealth))
        print("\nWhat do you want to do?")
        for option in f_options:  
          print("#"+str(f_options.index(option)+1)
        +":"+option+"\t")
        option = eval(input("Enter the number of the option "))
        if(option==1):
          end = self.enemy.damageDone()#Enemy Damage, rand num of lower and upper range
          td = self.player.damageDone()#Turn damage, damage done on this turn
          eh = eh-td
          h = h-end
          print("\nYou Attacked!\nThe "+en,"did   "+str(end),"Damage\nYou did "+str(td),"Damage")
          if(h <= 0):
            dead = True
            print("\nYOU DIED\n")
            return 0
          if(eh <=0):
            enemyDead = True
            print("\nYOU WON\n")
            return 1
        elif(option==2):
          print("NOT COMPLETED")
        #Items not implemented yet
        elif(option==3):#enemy does less damage(may implement player recover a little health)
          end = self.enemy.damageDone()
          endd = end-random.randint(2,3)#Enemy Damge Defend
          h = h-endd
          print("\nYou Defended!\nThe "+en,"did",str(endd),"Damage")
          if(h <= 0):
            dead = True
            print("\nYOU DIED\n")
            return 0
          if(eh <=0):
            enemyDead = True
            print("\nYOU WON\n")
            return 1
    
    
  