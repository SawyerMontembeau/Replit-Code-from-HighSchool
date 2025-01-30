from robot import Robot
def main():
  #1
  favorite_things = ["cats", "reading","videogames","razzberries","friends"]
  counter = 1
  for thing in favorite_things:
    print("#" + str(counter) + ". "+ thing.title())
    counter+=1

  #2
  days = eval(input("How many days do you want to enter hours for?"))
  hours = []
  for i in range(days):
    hour = eval(input("How many hours did you work on day " + str(i+1)))
    hours.append(hour)
  wage = eval(input("What is your hourly wage?"))
  total = 0
  for hour in hours:
    earnings = hour * wage
    print("You made $" + str(earnings) + " on day " + str(hours.index(hour) + 1))
    total += earnings
  print("The total you made is $" + str(total))

  #3
  people = {"Sawyer":["Boston","Portland","New York City","Detroit","Seattle"],
           "Max":["Boston","Portland","New York City","Detroit","Seattle"],
           "Sam":["Boston","Portland","New York City","Detroit","Seattle"],
           "Andrew":["Boston","Portland","New York City","Detroit","Seattle"],
           "Jordan":["Boston","Portland","New York City","Detroit","Seattle"]}

  for name,cities in people.items():
    print(name + "s favorite cities are:")
    for city in cities:
      print(str(cities.index(city)+1) +": " + city.title())

  #4
  def slope (x1,y1,x2,y2):
    slp = (y2-y1)/(x2-x1)
    print("The slope is" + str(slp))

  #5
  inches = [2.2, 9.8, 134, 32.9, 19, 2343]
  for i in range(len(inches)):
    cm = inches[i] * 2.54
    print("There are " + str(round(cm,2)) + " centimeters in " + str(inches[i]) + " inches")


  #Program 1
  def classes():
    b_classes = []
    w_classes = []
    num_classes = eval(input("How many classes do you want to enter?"))
    for i in range(num_classes):
      cls = []
      name = input("What is the name of the class?")
      cls.append(name)
      teacher = input("Who teaches the class?")
      cls.append(teacher)
      textbook = input("What is the textbook for the class?")
      cls.append(textbook)
      credits = eval(input("How many credits do you get for the class? 1 or 1/2?"))
      cls.append(credits)
      day = input("What color day is the class on?")
      cls.append(day)
      block = eval(input("What block does the class take place?"))
      cls.append(block)
      if(day.title() == "White"):
        w_classes.append(cls)
      elif(day.title() == "Blue"):
        b_classes.append(cls)
      else:
        break
        
    print("\nBLUE DAY:\n")
    for cls in b_classes:
      print("Block " + str(cls[5]) + ": " + cls[0] + " with " + cls[1] +"\nTextbook: " + cls[2] + "\nCredits: " + str(cls[3]))
    print("\nWHITE DAY:\n")
    for cls in w_classes:
      print("Block " + str(cls[5]) + ": " + cls[0] + " with " + cls[1] +"\nTextbook: " + cls[2] + "\nCredits: " + str(cls[3]))
 
  classes()

  #PROGRAM 2
  name = input("What is the name of the robot?")
  wd = eval(input("What is the wheel diameter of the robot?"))
  herbie = Robot(name,wd)
  herbie.describe()
  d = eval(input("what is the distance in inches that the robot needs to travel?"))
  print(str(round(herbie.rotations(d),3)) + " wheel rotations are needed to cover the distance entered")
  
main()