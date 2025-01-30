/*Write a program where you allow the user to fill up a 5 x 5 two dimensional array with double numbers. Then you print our the array with 5 values per line.*/
import java.util.*;
class Main {
  public static void main(String[] args) {
Scanner scan = new Scanner(System.in);
System.out.println("How many rows would you like the array to have?");
int rows = scan.nextInt();
System.out.println("How many columns would you like the array to have?");
int columns = scan.nextInt();

double [][] doubleNumbers = new double[rows][columns];

System.out.println("Please enter all numbers in decimal form");
for (int i = 0; i < rows; i++){
System.out.println("Please enter a number for row " + (i+1));
  for (int j = 0; j < columns; j++){
    doubleNumbers[i][j] = scan.nextDouble();
  }

}

 for (int i = 0; i < rows; i++){
System.out.print("\nRow "+ (i+1)+ ":");
  for (int j = 0; j < columns; j++){
    if(j+1 < doubleNumbers[i].length){
      System.out.print(doubleNumbers[i][j] + ", ");
    }else{
      System.out.print(doubleNumbers[i][j]);
    }
    
  
  }

}

  }
}