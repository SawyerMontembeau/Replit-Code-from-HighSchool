from graphics import *
import random
def main():
#Draw a Window 
#Draw a rectangle in that window and color it 
#move rectangle around with mouse clicks

  # Create a gGraphWin class object called win.
  win = GraphWin("Moving_Squares", 400, 400)
  x1 = 50
  y1 = 50
  x2 = 200
  y2 = 200

  #Create a rectangle class object called rect
  rect = Rectangle(Point(x1 , y1), Point(x2 , y2)) 
  rect.setOutline("Purple")
  rect.setFill("Blue")
  rect.draw(win)

  #move rectangle around mouse click 6 times, with random color
  for i in range(6):
    p = win.getMouse()
    c = rect.getCenter()
    dx = p.getX() - c.getX()
    dy = p.getY() - c.getY()
    r = random.randint(0,255)
    g = random.randint(0,255)
    b = random.randint(0,255)
    rect.setFill(color_rgb(r,g,b))
    rect.move(dx,dy)
    
  
  
  #draw new rectangle 4 times around mouse
  for i in range(4):
  
    c = win.getMouse()
    #c.getX()
    #c.getY()

    #p1 is the upper left hand corner  
    p1 = Point(c.getX()-((x2-x1)/2),c.getY()-((y2-y1)/2))
    #p2 is the lower left corner
    p2 = Point(c.getX()+((x2-x1)/2),c.getY()+((y2-y1)/2))

    rect = Rectangle(p1,p2)
    rect.setFill("Red")
    rect.draw(win)

main()