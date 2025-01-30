import java.util.*;
class Main {
  public static void main(String[] args) {
Scanner scan = new Scanner(System.in);
System.out.println("Enter a name:");
String name = scan.nextLine();

for(int i = 0; i <= name.length(); i++){
  
  if(i == 0){
     System.out.print(name.substring((name.length() - i)));
  }else{
 System.out.print(name.substring((name.length() - i),(name.length() - i+1)));
  }
 

}

  }
}