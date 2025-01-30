import java.util.*;
class Main {
  public static int numb(char letter) {
    int num = 0;

    switch (letter) {
      case 'A':
      case 'B':
      case 'C':
        num = 2;
        break;
      case 'D':
      case 'E':
      case 'F':
        num = 3;
        break;
      case 'G':
      case 'H':
      case 'I':
        num = 4;
        break;
      case 'J':
      case 'K':
      case 'L':
        num = 5;
        break;
      case 'M':
      case 'N':
      case 'O':
        num = 6;
        break;
      case 'P':
      case 'Q':
      case 'R':
      case 'S':
        num = 7;
        break;
      case 'T':
      case 'U':
      case 'V':
        num = 8;
        break;
      case 'W':
      case 'X':
      case 'Y':
      case 'Z':
        num = 9;
        break;
        default:

    }
    return num;
  }


  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    System.out.println("Type some letters to convert into a phone number variant: \n");
    String str = scan.nextLine();
    
    for(int x = 0;x<str.length();x++){
      
      if(Character.isLetter(str.charAt(x))){
        System.out.print(numb(Character.toUpperCase(str.charAt(x))));
      }else{
        System.out.print(str.charAt(x));

      }
      
    }

  }
}