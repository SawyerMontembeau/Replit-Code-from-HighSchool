from graphics import *
import random
import math
def main():

  winX = 600
  winY = 600
  radius = 50
  win = GraphWin("Darts", winX, winY)
  center = Point(winX/2, winY/2)
  
  whiteCircle = Circle(center,radius*5)
  whiteCircle.setOutline("Black")
  whiteCircle.setFill("White")
  whiteCircle.draw(win)
  
  blackCircle = Circle(center,radius*4)
  blackCircle.setOutline("Black")
  blackCircle.setFill("Black")
  blackCircle.draw(win)

  blueCircle = Circle(center,radius*3)
  blueCircle.setOutline("Black")
  blueCircle.setFill("Blue")
  blueCircle.draw(win)

  redCircle = Circle(center,radius*2)
  redCircle.setOutline("Black")
  redCircle.setFill("Red")
  redCircle.draw(win)

  yellowCircle = Circle(center,radius)
  yellowCircle.setOutline("Black")
  yellowCircle.setFill("Yellow")
  yellowCircle.draw(win)


  
  #Solution

#We need two while loops. first is to keep playing more games of darts, Second while loop is to keep playing a game untill winning score
  gameOver = False
  ans = "Yes"

  while(ans == "Yes"):
    blueDartsScore = 0
    redDartsScore = 0
    while(blueDartsScore<100 and redDartsScore<100):
      print("Player 1: Click the mouse to throw your dart!")
      win.getMouse()
      blueDartCenter = Point(winX/2, winY/2)
      positions = [-1, 1]
      positionX = random.choice(positions)
      positionY = random.choice(positions)

      blueDartX = random.randint(0,radius*5)*positionX
      blueDartY = random.randint(0,radius*5)*positionY

      #define blue dart center at center of board with radius of 4
      blueDart = Circle(blueDartCenter,4)
      blueDart.move(blueDartX,blueDartY)
      blueDart.setFill("Blue")
      blueDart.draw(win)

      blueDartRadius = math.sqrt(math.pow(blueDartX,2) + math.pow(blueDartY,2))

      if(blueDartRadius <= radius):
        print("You scored a Bullseye! You got 50 points!")
        blueDartsScore += 50
      elif(blueDartRadius <= radius*2 and blueDartRadius>radius):
        print("You scored in the Red zone! You got 30 points!")
        blueDartsScore += 30
      elif(blueDartRadius <= radius*3 and blueDartRadius>radius*2):
        print("You scored in the Blue zone! You got 20 points!")
        blueDartsScore += 20
      elif(blueDartRadius <= radius*4 and blueDartRadius>radius*3):
        print("You scored in the Black zone! You got 8 points!")
        blueDartsScore += 8
      elif(blueDartRadius <= radius*5 and blueDartRadius>radius*4):
        print("You scored in the white zone! You got 2 points!")
        blueDartsScore += 2
      else:
        print("You didn't hit the board!")

      #red darts
      if(blueDartsScore <= 100):
        print("Player 2: Click the mouse to throw your dart!")
        win.getMouse()
    
        redDartCenter = Point(winX/2, winY/2)
    
        redDartX = random.randint(0,radius*5)*positionX
        redDartY = random.randint(0,radius*5)*positionY

      #define red dart center at center of board with radius of 4
        redDart = Circle(redDartCenter,4)
        redDart.move(redDartX,redDartY)
        redDart.setFill("Red")
        redDart.draw(win)

        redDartRadius = math.sqrt(math.pow(redDartX,2) + math.pow(redDartY,2))

        if(redDartRadius <= radius):
          print("You scored a Bullseye! You got 50 points!")
          redDartsScore += 50
        elif(redDartRadius <= radius*2 and redDartRadius>radius):
          print("You scored in the Red zone! You got 30 points!")
          redDartsScore += 30
        elif(redDartRadius <= radius*3 and redDartRadius>radius*2):
          print("You scored in the Blue zone! You got 20 points!")
          redDartsScore += 20
        elif(redDartRadius <= radius*4 and redDartRadius>radius*3):
          print("You scored in the Black zone! You got 8 points!")
          redDartsScore += 8
        elif(redDartRadius <= radius*5 and redDartRadius>radius*4):
          print("You scored in the white zone! You got 2 points!")
          redDartsScore += 2
        else:
          print("You didn't hit the board!")

    #dont let player 2 go if player has already scored 100+
    #print current scores after each player throws
      print("\nPlayer 1 has",str(blueDartsScore),"points\nPlayer 2 has",str(redDartsScore),"points\n")
    #you need to tell who won the game
  
    if(blueDartsScore>=100):
      print("Player 1 Wins!")
    elif(redDartsScore>=100):
      print("Player 2 Wins!")
    
    #ask if they want to play again
    ans = input("Do You want to play again?\tYes or No").title()
    
main()