from players import Player
from missions import Mission
from enemies import Enemy
import random
def main():
  #This program will be a classic RPG style game. The User will get a choice of weapon and will go on a mission, defeating enemies. There will be a leveling system that will increase health upon killing a certain number of enemies. Once missions are finished new ones may be unlocked(longterm). There will most likely be some for of hub world, where there is a shop and a place to choose a mission

  #FUNCTIONS:
#Item Shop function(not complete) - intended to take in parameter of players money and allow them to make transactios
  item_Shop = ["Potion"]
  def shop(m):
    print("Welcome to the Shop!")
  
    if(m <= 0):
      print("You have no money. GET OUT!\n")
    #global inTown = True
    #global inShop = False
    else:
      print("What would you like to buy? You have", m, "gold")
      for item_s in item_Shop:
        print("#" + str(item_Shop.index(item_s)+1)+":", item_s)

#mission 1  
  def mission_1(dl,dt,h,th):
    print("\nYou have entered the first mission in Wrymwood Forest\n")
    print("You see a goblin, do you fight it?")
    fg = input("\nYes or No\n")

    if(fg.title() == "Yes"):
      fight(dl,dt,h,th,"goblin",10,10,3,5)
  
  
  #if(h <= 0):
    #print("You died! Sending you back to town")
  
#fight
#Takes in parameters of user damage(lower and top bounds), player health & total health, enemy name, enemy health & total enemy health, and enemy damage(under and top bounds)
  def fight(dl,dt,h,th,en,eh,teh,deu,det):
    f_options = ["fight","item","defend"]
    health = h
    enemy_health = eh
  #detect when player or enemy dies
    dead = False
    enemyDead = False
    if(health <= 0):
      dead = True
      #print("\nYOU DIED\n")  NOT WORKING YET
    if(enemy_health <=0):
      enemyDead = True
    #print("\nYOU WON\n")   NOT WORKING YET

   #need to end fight when player or enemy health <= 0
    if(dead != True and enemyDead != True):
      while(health > 0 and enemy_health > 0):
        print("\n"+en.upper()+" HEALTH = "+str(enemy_health)+"/"+str(teh))
        print("\nYOU\tHEALTH = "+str(health)+"/"+str(th))
        print("\nWhat do you want to do?")
        for option in f_options:  
          print("#"+str(f_options.index(option)+1)
          +":"+option+"\t")
        option = eval(input("Enter the number of the option "))
        if(option==1):
          end = random.randint(deu,det)#Enemy Damage, rand num of lower and upper range
          td = random.randint(dl,dt)#Turn damage, damage done on this turn
          enemy_health = enemy_health-td
          health = health-end
          print("\nYou Attacked!\nThe "+en,"did   "+str(end),"Damage\nYou did "+str(td),"Damage")
        elif(option==2):
          print("NOT COMPLETED")
      #Items not implemented yet
        elif(option==3):#enemy does less damage(may implement player recover a little health)
          end = random.randint(deu,det)
        endd = end-random.randint(2,3)#Enemy Damge Defend
        health = health-endd
        print("\nYou Defended!\nThe "+en,"did",str(endd),"Damage")
    
    
#enemies - list of dictionaries of enemies
enemies = []
#Main Program
weapons = ["Sword", "Axe", "Dagger", "Magic Staff"]

for weapon in weapons:
   print("Weapon #" + str(weapons.index(weapon)+1)+":", weapon)
weapon = input("Welcome to your new adventure. Pick your weapon by name!").title()

health = 20
you = Player(health,weapon)

#basic variables
money = 0
inTown=True
inShop = False
inMission_1 = False
hub_options = ["shop", "mission 1"]#list of all options from "town"

#losing all health means getting sent to town
if(health == 0):
  print("You died! Sending you back to town")
  inTown = False

#hub world/"town", place where options are selected
while(inTown==True):
  print("\nYou are in Town\n")
  
  for option in hub_options:
   print("#" + str(hub_options.index(option)+1)+":", option)
  h_choice = eval(input("What would you like to do? answer by number."))
  if(h_choice == 1):
    inTown = False
    inShop = True
  elif(h_choice == 2):
    inTown = False
    inMission_1 = True

  while(inShop == True):
    shop(money)
    inShop = False
    inTown = True

  while(inMission_1 == True):
    mission_1 = Mission("Wrymwood Forest",1,"Goblin",10,3,5,health,weapon,100)
    mission_1.describeMission()
    mission_1.fight()
    inMission_1 = False
    inTown = True