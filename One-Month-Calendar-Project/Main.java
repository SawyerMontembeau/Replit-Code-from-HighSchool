import java.util.*;
class Main {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int ms, md;

    System.out.println("What day does the month start:\n 1 for Sunday:\n 7 for Saturday:");
    ms = scan.nextInt();

    System.out.println("How many days are in the month?");
    md = scan.nextInt();
    
    System.out.println("\n");

    for(int x = 1; x < ms; x++){
      System.out.print("\t");
    }

    for(int x = 1; x <= md; x++){
      System.out.print(x + " ");

    if((x + ms) % 7 == 1){
      System.out.print("\n");
    }

    }

  }
}