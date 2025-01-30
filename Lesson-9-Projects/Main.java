import java.util.*;
class Main {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int ans = 1;
while(ans == 1){

    System.out.println("How old are you?");
    int age = scan.nextInt();

    if(age<18){
    System.out.println("Are you watching with an adult?");
    System.out.println("Enter 1 for YES or 2 for NO");
    int yn = scan.nextInt();
      if(yn == 1){
        System.out.println("You may watch all but NC-17 movies. But be advised some material may be inappropriate for some ages.");
      }
      else
      {
         System.out.println("You may watch up to PG-13, some material may be innapropriate  for children.");
      }
System.out.println("Do you want to enter another person?\n Enter 1 for YES and 2 for NO");
ans = scan.nextInt();
    }
    else
    { 
       System.out.println("You may watch all content regardless if an adult is present.");

    }
    System.out.println("Do you want to enter another person?\n Enter 1 for YES and 2 for NO");
    ans = scan.nextInt();
}


  }
}