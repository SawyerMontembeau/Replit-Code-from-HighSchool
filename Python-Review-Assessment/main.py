#1, 2, 3, &4
name = "Timothy"
age = 44
weight = 145.6
print("{0} is {1} years old and weighs {2}-lbs.".format(name,age,weight))

#5
n = input("What is your name?")
a = eval(input("What is your age?"))
w = eval(input("What is your weight?"))
#6
def printInfo(name, age, weight):
  print("{0} is {1} years old and weighs {2}-lbs.".format(name,age,weight))

printInfo(n,a,w)

#7
def addAge(name, age):
  #sumA = age*(age+1)/2
  #13 start
  sumA = 0
  for i in range(age):
    sumA = sumA+(i+1)
  #13 end
  print("Hello {0}! If I add up all numbers from 1 to {1}, it equals {2}.".format(name,age,sumA))

addAge(n,a)

#8
def echo():
  ans = "yes"
  while(ans != "quit"):
    wordE = input("Enter a word")
    print("{0}\n{0}".format(wordE))
    ans = input("If you want to echo another word type anything. If you want to quit type quit")

echo()
#9
gW = eval(input("What is the weight you want to be?"))
def weights(weight,goalWeight):
  if(weight==goalWeight):
    print("Congrats! You are at your goal weight!")
  elif(weight>goalWeight):
    print("You need to lose weight to get to your goal weight")
  else:
    print("You need to gain weight to reach your goal weight")

weights(w,gW)

#10
favFoods = ["potato skins", "Razzberries", "bagels","ramen","hashbrowns"]

#11
for food in favFoods:
  print("My favorite food is", food)

#12
for i in range(19777):
  if(i%2 != 0):
    print(str(i))

#13 input into addAge