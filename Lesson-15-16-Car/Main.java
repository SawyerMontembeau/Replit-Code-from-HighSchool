import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    String answer = "yes";

  

    System.out.println("Year:");
    int yr = input.nextInt();
    System.out.println("color:");
    String cr = input.nextLine();
    System.out.println("Mileage:");
    double mg = input.nextDouble();
    System.out.println("Tank Capacity:");
    double tank = input.nextDouble();
    System.out.println("Efficiency:");
    double mpg = input.nextDouble();
    System.out.println("Make:");
    String mk = input.nextLine();
    System.out.println("Model:");
    String mod = input.nextLine();
    System.out.println("Price:");
    double pr = input.nextDouble();
    System.out.println("Cylinders:");
    int cyl = input.nextInt();

    car sawyerCar = new car(yr,cr,mg,tank,mpg,mk,mod,pr,cyl);
  
    sawyerCar.printMyCar();
    System.out.println("How many miles in your trip?");
    double miles = input.nextDouble();
    System.out.println("Price of gas per gallon?");
    double price = input.nextDouble();
    System.out.println("Your roundtrip cost for gas is: $" + sawyerCar.takeTrip(price, miles));

  }
}