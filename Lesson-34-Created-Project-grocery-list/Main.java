import java.util.*;
class Main {
  public static void main(String[] args) {

Scanner scan = new Scanner(System.in);
System.out.println("How many rows would you like the grocery list to have?");
int rows = scan.nextInt();
System.out.println("How many columns would you like the grocery list to have?");
int columns = scan.nextInt();

String [][] glist = new String[rows][columns];

System.out.println("For organization, have row 1 consist of categories (dairy, fruits, etc)");
System.out.println("Or begin each new row with a category\n");
for (int i = 0; i < rows; i++){
System.out.println("Please enter the items for row " + (i+1));
  for (int j = 0; j < columns; j++){
    glist[i][j] = scan.next();
  }

}

 for (int i = 0; i < rows; i++){
System.out.print("\nRow "+ (i+1)+ ":");
  for (int j = 0; j < columns; j++){
    if(j+1 < glist[i].length){
      System.out.print(glist[i][j] + ", ");
    }else{
      System.out.print(glist[i][j]);
    }  
  }
 }
}

}