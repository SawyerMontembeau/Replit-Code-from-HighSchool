import random
from graphics import *

def drawDice(topLeftX,topLeftY,diceW,windowName):
  dice = Rectangle(Point(topLeftX,topLeftY),Point(topLeftX+diceW,topLeftY+diceW))
  dice.setFill("White")
  dice.draw(windowName)

def drawOneDot(topLeftX,topLeftY,diceW,windowName):
  dot = Circle(Point(topLeftX+diceW/2,topLeftY+diceW/2),10)
  dot.setFill("Black")
  dot.draw(windowName)

def drawTwoDots(topLeftX,topLeftY,diceW,windowName):
  dot_1 = Circle(Point(topLeftX+diceW/4,topLeftY+diceW/4),10)
  dot_2 = Circle(Point(topLeftX+diceW*(3/4),topLeftY+diceW*(3/4)),10)
  dot_1.setFill("Black")
  dot_2.setFill("Black")
  dot_1.draw(windowName)
  dot_2.draw(windowName)

def drawTwoDotsOpposite(topLeftX,topLeftY,diceW,windowName):
  dot_1 = Circle(Point(topLeftX+diceW/4,topLeftY+diceW*(3/4)),10)
  dot_2 = Circle(Point(topLeftX+diceW*(3/4),topLeftY+diceW/4),10)
  dot_1.setFill("Black")
  dot_2.setFill("Black")
  dot_1.draw(windowName)
  dot_2.draw(windowName)

def main():
  win = GraphWin("Rolling Dice", 800,400)

  
  topLeftX = 100
  topLeftY = 100
  diceWidth = 100
  space = 25
  score = 0

  #1 die
  drawDice(topLeftX,topLeftY,diceWidth,win)
  #drawOneDot(topLeftX,topLeftY,diceWidth,win)

  
  #2 die
  drawDice(topLeftX+diceWidth+space,topLeftY,diceWidth,win)
  #drawTwoDots(topLeftX+diceWidth+space,topLeftY,diceWidth,win)

  
  #3 die
  drawDice(topLeftX+diceWidth*2+space*2,topLeftY,diceWidth,win)
  #drawOneDot(topLeftX+diceWidth*2+space*2,topLeftY,diceWidth,win)
  #drawTwoDots(topLeftX+diceWidth*2+space*2,topLeftY,diceWidth,win)

  
  #4 die
  drawDice(topLeftX+diceWidth*3+space*3,topLeftY,diceWidth,win)
  #drawTwoDots(topLeftX+diceWidth*3+space*3,topLeftY,diceWidth,win)
  #drawTwoDotsOpposite(topLeftX+diceWidth*3+space*3,topLeftY,diceWidth,win)

  
  #5 die
  drawDice(topLeftX+diceWidth*4+space*4,topLeftY,diceWidth,win)
  #drawOneDot(topLeftX+diceWidth*4+space*4,topLeftY,diceWidth,win)
  #drawTwoDots(topLeftX+diceWidth*4+space*4,topLeftY,diceWidth,win)
  #drawTwoDotsOpposite(topLeftX+diceWidth*4+space*4,topLeftY,diceWidth,win)

  

  for i in range(5):
    dieChoice = random.randint(1,5)
    if(i!=0):
      if(dieChoice == 1):
        drawOneDot(topLeftX+(diceWidth*(i))+(space*(i)),topLeftY,diceWidth,win)
        score+=1
      elif(dieChoice == 2):
        drawTwoDots(topLeftX+(diceWidth*(i))+(space*(i)),topLeftY,diceWidth,win)
        score+=2
      elif(dieChoice == 3):
        drawOneDot(topLeftX+(diceWidth*(i))+(space*(i)),topLeftY,diceWidth,win)
        drawTwoDots(topLeftX+(diceWidth*(i))+(space*(i)),topLeftY,diceWidth,win)
        score+=3
      elif(dieChoice == 4):
        drawTwoDots(topLeftX+(diceWidth*(i))+(space*(i)),topLeftY,diceWidth,win)
        drawTwoDotsOpposite(topLeftX+(diceWidth*(i))+(space*(i)),topLeftY,diceWidth,win)
        score+=4
      elif(dieChoice == 5):
        drawOneDot(topLeftX+(diceWidth*(i))+(space*(i)),topLeftY,diceWidth,win)
        drawTwoDots(topLeftX+(diceWidth*(i))+(space*(i)),topLeftY,diceWidth,win)
        drawTwoDotsOpposite(topLeftX+(diceWidth*(i))+(space*(i)),topLeftY,diceWidth,win)
        score+=5
    else:
      if(dieChoice == 1):
        drawOneDot(topLeftX,topLeftY,diceWidth,win)
        score+=1
      elif(dieChoice == 2):
        drawTwoDots(topLeftX,topLeftY,diceWidth,win)
        score+=2
      elif(dieChoice == 3):
        drawOneDot(topLeftX,topLeftY,diceWidth,win)
        drawTwoDots(topLeftX,topLeftY,diceWidth,win)
        score+=3
      elif(dieChoice == 4):
        drawTwoDots(topLeftX,topLeftY,diceWidth,win)
        drawTwoDotsOpposite(topLeftX,topLeftY,diceWidth,win)
        score+=4
      elif(dieChoice == 5):
        drawOneDot(topLeftX,topLeftY,diceWidth,win)
        drawTwoDots(topLeftX,topLeftY,diceWidth,win)
        drawTwoDotsOpposite(topLeftX,topLeftY,diceWidth,win)
        score+=5

  print("The Score is:",str(score))
main()