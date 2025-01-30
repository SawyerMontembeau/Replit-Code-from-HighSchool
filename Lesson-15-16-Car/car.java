public class car{
  
  public int year;
  public String color;
  public double mileage;
  public double feulTank;
  public double mpg;
  public String make;
  public String model;
  public double price;
  public int cylinders;

public car(int year, String col, double mile, double feul, double mpg,  String make, String mod, double pr, int cyl)
  {
  this.year = year;
  color = col;
  mileage = mile;
  feulTank = feul;
  this.mpg = mpg;
  this.make = make;
  model = mod;
  price = pr;
  cylinders = cyl;
  }

public void printMyCar()
{
System.out.println("I love your"+ year + " " + make + " " + model + "! \n" + "From looking at the odometer, I can tell it has " + mileage + "-miles. The gas mileage o this car is " + mpg + " miles per gallon\nYour For Sale sign says that it costs $" + price);
}

public double takeTrip(double gasPrice, double miles)
{
  double tripGallons = 2*miles / mpg;
  double tripCost = tripGallons * gasPrice;
  return tripCost;
}

}