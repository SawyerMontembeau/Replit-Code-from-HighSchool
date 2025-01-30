import pygame
from gameClasses import *
# set up some global CONSTANTS
#set up the game screen width and height and color
WIDTH = 400
HEIGHT = 300
BACKGROUND = (85, 2, 102
             )
def main():
  pygame.init()

  screen = pygame.display.set_mode((WIDTH,HEIGHT))
  clock = pygame.time.Clock()

  #make a player class object
  player = Player(200,210)

  #Create a list of box objects. but in pygame we make what is called a group rather than a list
  boxes = pygame.sprite.Group()
  for box in range(0,400,70):
    boxes.add(Box(box,300))

  boxes.add(Box(330,230))
  boxes.add(Box(100,70))

  while True:
    pygame.event.pump()
    player.update(boxes)

    screen.fill(BACKGROUND)
    player.draw(screen)
    boxes.draw(screen)

    pygame.display.flip()

    clock.tick(60)
    
main()