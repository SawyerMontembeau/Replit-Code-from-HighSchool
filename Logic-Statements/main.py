# number 1
price = eval(input("What is the price of the car?"))

if(price<=10000):
  print("I will buy it!")
else:
  print("That is too expensive")

#number 2
age = eval(input("What is your age?"))

if(age>=15):
  print("You are old enough to take driver's ed")
else:
  print("You are not old enough yet to enroll in dirver's ed")

#number 3
grade = eval(input("Enter a number grade out of 100"))

if(grade>=90):
  print("You entered a number grade of",grade,"Your letter grade is an A")
elif(grade>=80):
  print("You entered a number grade of",grade,"Your letter grade is a B")
elif(grade>=70):
  print("You entered a number grade of",grade,"Your letter grade is a C")
else:
  print("You entered a number grade of",grade,"Your letter grade is a D")

#number 4
weapon = eval(input("Enter the number of the weapon you want! \n1.Sword  2.Bow and Arrow  3.Battleaxe  4.Magic Staff"))

if(weapon == 1):
  print("You picked the Sword! You managed to chop the zombie's legs off and run away!")
elif(weapon == 2):
  print("You picked the Bow and Arrow! You desparately shoot but the zombie is unfazed. You Died")
elif(weapon == 3):
  print("You picked the Battleaxe! With a heavy swing you split the zombie in twain!")
elif(weapon == 4):
  print("You picked the Magic Staff! Unfortunatley this isn't some fantasy world, and that's just a glorified stick. You Died")
else:
  print("You did not pick a weapon. You Died")

#number 5
number = 2

while(number<=30):
  print(str(number))
  number = number+2

#number 6
total = 0
answer = "yes"

while(answer == "yes"):
  number = eval(input("Enter a number"))
  total = total+number

  answer = input("Do you want to answer another number yes or no")

print(str(total))

#7
ans = "yes"
groLst = []

while(ans == "yes"):
  item = input("Enter an item for your grocery list\n").lower()

  if(item in groLst):
    print("This item is already in the list\n")
  else:
    groLst.append(item)

  ans = input("Do you want to enter another item? yes or no").lower()

print("\nYour Grocery list is:\n")
for i in range(len(groLst)):
  print(groLst[i].title())
