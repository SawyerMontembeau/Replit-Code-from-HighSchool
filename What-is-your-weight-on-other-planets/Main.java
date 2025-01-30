import java.util.*;
class Main {
  public static void main(String[] args) {
    System.out.println("What is your weight on Earth? ");
    Scanner scan = new Scanner(System.in);
    double weight = scan.nextDouble();

    System.out.println("1. Voltar\n2. Krypton\n3. Fertos\n4. Servontos");
    System.out.println("Which planet do you want to visit? ");
int planet = scan.nextInt();
switch (planet)
{
  case 1://Voltar
  System.out.println("You weigh " + (weight*0.091) + " on Voltar!");
  break;
case 2://Krypton
  System.out.println("You weigh " + (weight*0.720) + " on Krypton!");
  break;
  case 3://Fertos
  System.out.println("You weigh " + (weight*0.865) + " on Fertos!");
  break;
  case 4://Servontos
  System.out.println("You weigh " + (weight*4.612) + " on Servontos!");
  break;
  default:
  System.out.println("please enter a 1,2,3, or 4 ");
}
  }
}