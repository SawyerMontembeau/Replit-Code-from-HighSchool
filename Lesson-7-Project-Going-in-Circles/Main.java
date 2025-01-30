import java.util.*;
class Main {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    System.out.println("Enter the area of the circle");
    double area = scan.nextDouble();
    double PI = Math.PI;
    System.out.println("Your circle's radius is "+Math.sqrt(area/PI));
  }
}