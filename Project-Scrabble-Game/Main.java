import java.util.*;
class Main {
public static void main(String[] args) {
System.out.println("Enter a word");
Scanner scan = new Scanner(System.in);
String word = scan.nextLine().toUpperCase();
int sum = 0;
char c;
for(int i = 0; i < word.length(); i++){
 c = word.charAt(i);

switch(c){
  case 'A':
  case 'E':
  case 'I':
  case 'L':
  case 'N':
  case 'O':
  case 'R':
  case 'S':
  case 'T':
  case 'U':
sum = sum + 1;
break;
  case 'D':
  case 'g':
sum = sum + 2;
break;
  case 'B':
  case 'C':
  case 'M':
  case 'P':
sum = sum + 3;
break;
  case 'F':
  case 'H':
  case 'V':
  case 'W':
  case 'Y':
sum = sum + 4;
break;
  case 'K':
sum = sum + 5;
break;
  case 'J':
  case 'X':
sum = sum + 8;
break;
  case 'Q':
  case 'Z':
sum = sum + 10;
break;
default:
}

}
System.out.println(sum);
  }
}