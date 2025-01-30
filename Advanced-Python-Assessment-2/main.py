def main():
  # number 1
  names = ["sawyer","max","matt","fletcher","flynn"]

  for name in names:
    print(name.title() + " is a Student")

  #number 2
  print("\n")
  states = {"ME":"Chickadee",
            "AR":"Mockingbird",
            "CT":"American Robin",
            "HI":"Nene",
            "OH":"Northern Cardinal"
          }

  for key in states:
    print("The State bird of " + key + " is the " + states[key])

  #number 3
  print("\n")
  person = {"name":"Sawyer Montembeau",
         "age":"17",
         "friends":["Max Aiello","Matt Durcan","Andrew Atwater","Fletcher Crean","Flynn Crean"]
  }

  print(person["name"].title())
  print(person["age"])
  for friend in person["friends"]:
    print(friend + " is friends with " + person["name"])

  #number 4
  print("\n")
  movie = {"name":"Batman",
           "showtimes":["12:30pm","2:00pm","3:45pm","5:00pm","7:30pm"],
           "theater":"D",
           "rating":"4"
  }

  print(movie["name"].title())
  print(movie["theater"])
  print(movie["rating"] + " stars")

  for showtime in movie["showtimes"]:
    print("Showtime " + str(movie["showtimes"].index(showtime) + 1) + " - " + showtime)

  #number 5
    print("\n")
  cars = [
    {"make":"Ford",
     "model":"F150",
     "year":"2016",
     "price":"25000"
    },
    {"make":"Toyota",
     "model":"Tundra",
     "year":"2018",
     "price":"30000"
    },
    {"make":"Nissan",
     "model":"Ultima",
     "year":"2012",
     "price":"20000"
    },
    {"make":"Tesla",
     "model":"Model 3",
     "year":"2022",
     "price":"45000"
    }
  ]

  for car in cars:
    print("Car " + str(cars.index(car) + 1))
    for key in car:
      print(key + ": " + car[key])
main()
  