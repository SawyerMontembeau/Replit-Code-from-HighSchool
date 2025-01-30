import java.util.*;
class Main {
  public static void main(String[] args) {
    //This program will have the user enter parameters for a house and compare it to other houses to determine if there are any houses they would also like.

ArrayList<House> listings = new ArrayList<House>();
House house1 = new House("20 Fletcher St.", 4, 2, 1984, 1500, "electric", 300000);
listings.add(house1);
House house2 = new House("16 Spring rd.", 3, 1, 1950, 1200, "oil", 250000);
listings.add(house2);
House house3 = new House("36 Long St.", 5, 3, 1973, 2000, "electric", 350000);
listings.add(house3);
House house4 = new House("42 March rd.", 1, 1, 1962, 750, "oil", 150000);
listings.add(house4);
House house5 = new House("9 Green St.", 2, 1, 2001, 1000, "electric", 200000);
listings.add(house5); // houses that are compared to users inputs

Scanner scan = new Scanner(System.in);
String ans = "yes";

do;

System.out.println("");

while(ans.equalsIgnoreCase("yes"));
  }
}