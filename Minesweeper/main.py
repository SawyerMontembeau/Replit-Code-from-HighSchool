from graphics import *
import math
import random
import tkinter as tk


def drawbox(topLeftX,topLeftY,boxW,windowName,c):
    box = Rectangle(Point(topLeftX,topLeftY),Point(topLeftX+boxW,topLeftY+boxW))
    box.setFill(c)
    box.draw(windowName)

#def draw_o(topLeftX,topLeftY,width,windowName):

def onbox(bw,boxes,win):
  c = win.getMouse()
  for box in boxes:
    m = box[0].getCenter()
    tlx = m.getX() - (bw/2)
    tly = m.getY() - (bw/2)
    trx=tlx+bw
    bly=tly+bw
    if (trx >= c.getX()) & (c.getX() >= tlx) & (bly >= c.getY()) & (c.getY() >= tly):
      boxMid = m
      return boxMid
      return True 

def main():
  
  winX = 380
  winY = 380
  win = GraphWin("Minesweeper",winX,winY)
  box_width = 20
  boxes = []

  for boxx in range(40,340,20):
    for boxy in range(40,340,20):
      #drawbox(boxx,boxy,box_width,win,"White")
      box =[Rectangle(Point(boxx,boxy),Point(boxx+box_width,boxy+box_width))]
      boxes.append(box)
      box[0].setFill("White")
      box[0].draw(win)

  bombs = []
  for i in range(39):
    b = random.randint(0,224)
    boxes[b].append("bomb")
    bombs.append(boxes[b])

  for box in boxes:
    if box in bombs:
      if box[0].getY() == 40:
        boxes[box]
        
        
   # box_center = box[0].getCenter()
    #box_X = box_center.getX()
    #box_Y = box_center.getY()
    #box_left_x = box_X - box_width
    #box_right_x = box_X + box_width
   # box_above_y = box_Y - box_width
   # box_below_y = box_Y + box_width
    
    #if box[1] == "bomb":
    #  break
    #elif 
    
  #300 total spaces
  fail = False
  while fail==False:
    p = onbox(box_width,boxes,win)
    print(p)
    for box in boxes:
      if((p.getX() == box[0].getCenter().getX()) & (p.getY() ==box[0].getCenter().getY())):
        box[0].undraw()
        box[0].setFill("Blue")
        box[0].draw(win)
   
  
  
  

main()