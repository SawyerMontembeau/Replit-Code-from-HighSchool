import java.util.*;
class Main {
  public static void main(String[] args) {
  Scanner scan = new Scanner(System.in);
  Scanner again = new Scanner(System.in);
  String yn;
do{
  System.out.println("What is your Income?");
  double income = scan.nextDouble();

  if(income <750){
    System.out.println("Your due tax is $"+(0.01*income));
  }else if (income <2250){
    System.out.println("Your due tax is $"+(7.50+0.02*(income-750)));
  }else if (income <3750){
    System.out.println("Your due tax is $"+(37.50+0.03*(income-2250)));
  }else if (income <5250){
    System.out.println("Your due tax is $"+(82.50+0.04*(income-3750)));
  }else if (income<7000){
    System.out.println("Your due tax is $"+(142.50+0.05*(income-5250)));
  }else if(income>=7000){
    System.out.println("Your due tax is $"+ (230+0.06*(income-7000)));
  }
  
  System.out.println("Do you want to enter another income?\n YES or NO");
  yn = again.nextLine();
  yn = yn.toLowerCase();

}while(yn.equals("yes"));
  }
}