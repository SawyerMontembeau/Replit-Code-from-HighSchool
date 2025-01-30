from monopoly import *
def main():
  #create a list called board that holds property objects
  #Create a list called players that holds player objects
  #create 5 monopoly properties and add to board
  #ask the user how many players and set up a for loop to ask which piece they want and create the players and add them to players list
  board = []
  players = []

 # num = eval(input("How many properties do you want to enter?"))
  #for i in range(num):
   # s = eval(input("What number space is the property on?"))
  #  n = input("What is the name of the property?")
   # p = eval(input("What is the price?"))
    #c = input("What is the Color?")
   # r = eval(input("What is the rent?"))
   # hC = eval(input("What is the hotel's price?"))
   # hR = eval(input("What is the Hotel's rent?"))
   # v = eval(input)
   # prop = Property(s,n,p,c,r,hC,hR,v)

  med_ave = Property(1,"Mediterranian Avenue",150,"blue",50,100,200,75)
  board.append(med_ave)
  bal_ave = Property(2,"Baltic Avenue",150,"blue",50,100,200,75)
  board.append(bal_ave)
  boardwalk = Property(3,"boardwalk",150,"blue",50,100,200,75)
  board.append(boardwalk)
  cent_park = Property(4,"Central Park",150,"blue",50,100,200,75)
  board.append(cent_park)
  ver_ave = Property(5,"Vermont Avenue",150,"blue",50,100,200,75)
  board.append(ver_ave)
  pac_ave = Property(6,"Pacific Avenue",150,"blue",50,100,200,75)
  board.append(pac_ave)
  marv_gar = Property(7,"Marvin Gardens",150,"blue",50,100,200,75)
  board.append(marv_gar)
  ill_ave = Property(8,"Illinois Avenue",150,"blue",50,100,200,75)
  board.append(ill_ave)
  ken_ave = Property(9,"Kentucky Avenue",150,"blue",50,100,200,75)
  board.append(ken_ave)
  ny_ave = Property(10,"New York Avenue",150,"blue",50,100,200,75)
  board.append(ny_ave)
  
    
  pieces = ["shoe","dog","car","boat","candlestick"]
  amt = eval(input("How Many players do you want to add?"))
  for player in range(amt):
    for piece in pieces:
      print(piece)
      p = input("What piece do you want?")
      while p not in pieces:
        p = input("What piece do you want?")
      pl = Player(p)
      players.append(player)
      pieces.remove(p)

    
  #add new yor avenue to player 1's list of properties
  players[0].properties.append(board[9])
  print(players[0].properties[0].get_description())

  bp = input("What property do you want to buy?")
  for x in board:
    if(bp == x.name):
      print("The property is available.", x.name,"costs",x.price)
    
main()