name = "Sawyer"
age = 17
height = 6
weight=145.2
print("Hello",name.title()+" you are",str(age)+" years old, and are "+str(height)+" ft tall")

print("Hello",name.title(),"you are",age,"years old, and weigh",weight,"-lbs")

print("Hello {0} you are {1} years old, and weigh {2:.2f}-lbs".format(name,age,weight))

# 3 types of formatting for print statements

weightA = 110.2
weightB = 344.22
weightC = 444.12

print("The first weight is",str(weightA)+"-lbs. The second weight is",str(weightB)+"-lbs. The third weight is",str(weightC)+"-lbs." )

print("The first weight is " + str(weightA) + "-lbs. The second weight is " + str(weightB)+"-lbs. The third weight is" + str(weightC)+"-lbs." )

print("The first weight is {0}-lbs. The second weight is {1}-lbs. The third weight is {2}-lbs.".format(weightA,weightB,weightC))
#comments show how to take input for int or float
length = 5.3 #eval(input("What is the length?"))
width = 10.5 #eval(input("What is the width?"))

print("The length {0} ft times the width {1} ft = 55.65 square ft".format(length,width))

def calcAvgGrade(g1,g2,g3,g4,g5):
  avgGrade = (g1 + g2 + g3 + g4 + g5) / 5
  print("The Average grade is",avgGrade)

calcAvgGrade(100,99,95,89,100)

def tripCost(miles,mpg,gas):
  cost = (miles/mpg)*gas
  print("The cost is ${0:.2f}".format(cost))

tripCost(500,50,30)


#lists
numbers = [1,2,5,9,12]

def addNumbers(myListOfNumbers):
  total = 0
  for number in myListOfNumbers:
    total = total + number
  print("This is your total of all numbers {0:.1f}".format(total))

addNumbers(numbers)

#exercise
#numTrips = eval(input("How many trips have you taken?"))
#tripList = []
#for trip in tripList: