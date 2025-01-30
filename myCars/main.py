from car import Car
from electric_car import ElectricCar
def main():
#def__init__(self, y, mk, md, c, p, odo, gts):
  car_1 = Car(1967,"Ford", "Mustang Gt", "green",65000,29000,15)
  print(car_1.get_description())
  car_1.read_odometer()
  car_1.update_odometer(64789)
  car_1.increment_odometer(300)
  car_1.read_odometer()

  elec_1 = ElectricCar(2022,"Tesla","model 3", "blue", 55000, 70)
  elec_1.carDescription()
  m = eval(input("How many miles have you driven?"))
  elec_1.chargeLevel(m)

  car_num = eval(input("How many cars would you like to enter?"))
  cars = []
  for i in range(car_num):
    year = eval(input("what is the year?"))
    make = input("What is the make?")
    model = input("What is the model?")
    color = input("What is the color?")
    price = eval(input("What is the price?"))
    odometer_reading = eval(input("What is the odometer reading?"))
    gas_tank_size = eval(input("What is the gas tank size"))

    car_u =Car(year,make,model,color,price,odometer_reading,gas_tank_size)
    cars.append(car_u)

  i = 1
  for car in cars:
    print("\nCar "+str(i)+":\n" + car.get_description())
    i += 1
  
main()