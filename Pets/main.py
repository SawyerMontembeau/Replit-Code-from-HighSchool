from pets import Pet
from parrot import Parrot
from dog import Dog
from snake import Snake
def main():

  animals = []
  fido = Dog("Fido", 33342, 80, 30)
  animals.append(fido)
  fido.describe()
  print(fido.speak())
  print(fido.move())

  cheep = Parrot("Cheep", 11245,30,"Macaw", "banana")
  animals.append(cheep)
  cheep.describe()
  print(cheep.speak())
  print(cheep.move())

  clyde = Snake("Clyde",99654,60,14)
  animals.append(clyde)
  clyde.describe()
  print(clyde.speak())
  print(clyde.move())

  print("\n")

  total = 0
  for animal in animals:
    animal.purchase()
    total += animal.price

  print("\nThe total of all of the pets is $" + str(total))

main()