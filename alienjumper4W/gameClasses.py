#parent class will be the Sprite() class
import pygame
import numpy

class Sprite(pygame.sprite.Sprite):

  def __init__(self, image, startx, starty):
    super().__init__()
    self.image = pygame.image.load(image)
    self.rect = self.image.get_rect()

    self.rect.center = [startx,starty]

  def update(self):
    pass

  def draw(self,screen):
    screen.blit(self.image,self.rect)

class Player(Sprite):
  def __init__(self,startx,starty):
    super().__init__("p1_front.png",startx,starty)
    self.stand_image = self.image
    self.jump_image = pygame.image.load("zombie_jump.png")

    self.walk_cycle = [pygame.image.load(f"p1_walk{i:0>2}.png") for i in range(1,12)]
    self.animation_index = 0
    self.facing_left = False
    self.player_speed = 4
    self.jump_speed = 20
    self.vsp = 0 #vertical speed
    self.gravity = 1
    self.min_jump_speed = 3
    self.prev_key = pygame.key.get_pressed()

  def walk_animation(self):
    self.image = self.walk_cycle[self.animation_index]
    if self.facing_left:
      self.image = pygame.transform.flip(self.image,True, False)

    if self.animation_index < len(self.walk_cycle)-1:
      self.animation_index+=1
    else:
      self.animation_index = 0

  def jump_animation(self):
    self.image = self.jump_image
    if self.facing_left:
      self.image = pygame.transform.flip(self.image, True, False)
  
  def move(self,x,y,boxes):
    dx = x
    dy = y
    while self.check_collision(0,dy,boxes):
      dy -= numpy.sign(dy)
    while self.check_collision(dx,dy,boxes):
      dx -= numpy.sign(dx)
    self.rect.move_ip([dx,dy])

  def update(self,boxes):
    hsp = 0 #horizontal speed
    onground = self.check_collision(0,1,boxes)
    #use pygame.key.get_pressed(), generates a list of the entire keyboard and whether the kay has been pressed(1) or not(0)
    key = pygame.key.get_pressed()
    if key[pygame.K_LEFT]:
      self.facing_left = True
      self.walk_animation()
      hsp = -self.player_speed
    elif(key[pygame.K_RIGHT]):
      self.facing_left = False
      self.walk_animation()
      hsp = self.player_speed
    else:
      self.image = self.stand_image

    if key[pygame.K_UP] and onground:
      self.vsp = -self.jump_speed

    #variable height jumping
    if self.prev_key[pygame.K_UP] and not key[pygame.K_UP]:
      if self.vsp < -self.min_jump_speed:
        self.vsp = -self.min_jump_speed

    self.prev_key = key

    #gravity
    if self.vsp<10 and not onground: # 9.8m/s^2 rounded up
      self.jump_animation()
      self.vsp+=self.gravity

      #stop fallig when the ground is reached
    if self.vsp > 0 and onground:
      self.vsp = 0

    #movement
    self.move(hsp,self.vsp,boxes)

  def check_collision(self, x, y, boxes):
    self.rect.move_ip([x,y])
    collide = pygame.sprite.spritecollideany(self, boxes)
    self.rect.move_ip([-x, -y])
    return collide
    

class Box(Sprite):
  def __init__(self,startx,starty):
    super().__init__("boxAlt.png",startx,starty)