#number 1
classes = ["Math","Science", "English", "History", "Art", "PE"]

# number 2
friends = ["Max", "Fletcher", "Flynn", "Andrew", "Mat"]

#number 3

grades = []
grades.append(100)
grades.append(95)
grades.append(97)
grades.append(92)
grades.append(89)
grades.append(100)

#number 4
favFoods = []
favFoods.append("French Fries")
favFoods.append("Potato skins")
favFoods.append("BLT's")
favFoods.append("Razzberries")
favFoods.append("Ramen")

#number 5
novels = ["Lord of the Rings", "Eragon", "Dune", "No Longer Human"]
for novel in novels:
  print("One of my favorite novels is",novel)

#number 6
weapons = ["Sword", "Bow and Arrow", "Battleaxe", "Magic Staff", "Throwing Knives", "Spear"]
for weapon in weapons:
  print("Weapon #" + str(weapons.index(weapon)+1)+":", weapon)

#number 7
ans = "yes"
while(ans == "yes"):
  numInput = eval(input("Enter a Number greater than 20"))
  if(numInput > 20):
    for num in range(numInput):
     print(str(num + 1))
    ans = "no"
  else:
   print("The Number you entered was not greater than 20")
   ans = input("Would you like to enter a new number? yes or no").lower()

#number 8
numIn = eval(input("Enter a Number greater than 50"))

for num in range(numIn):
  num = num * 2
  print(str(num))