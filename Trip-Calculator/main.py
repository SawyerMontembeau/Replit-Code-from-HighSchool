print("Welcome to my trip calculator!This program will take in the miles driven for each of your trips and calculate how many miles you drove, how many gallons you used, and how much it costs.")

miles_1 = eval(input("what was the miles driven for 1 trip?"))
miles_2 = eval(input("what was the miles driven for trip 2?"))
miles_3 = eval(input("what was the miles driven for trip 3?"))
miles_4 = eval(input("what was the miles driven for trip 4?"))
miles_5 = eval(input("what was the miles driven for trip 5?"))

mpg = eval(input("What is the mpg of your vehicle?"))
gasPrice = eval(input("What is  the cost per gallon of gas?"))

def tripCalc(m1,m2,m3,m4,m5,efficiency,price):
  totalMiles = m1 + m2 + m3 + m4 + m5
  gallons = totalMiles/efficiency
  cost = gallons * price
  print("You have driven {0} miles, used {1:.2f} gallons of gas, and the trip has cost ${2:.2f}".format(totalMiles,gallons,cost))

tripCalc(miles_1,miles_2,miles_3,miles_4,miles_5,mpg,gasPrice)