import java.util.*;
class Main {
  public static void main(String[] args) {
    Scanner scan  = new Scanner(System.in);
    boolean hasKey = false;
    boolean isHurt = false;
    System.out.println("Your new adventure begins now!\n");
    System.out.println("You wake up in a vast open plain. To your left is a path that leads into a forest, to your right is a path leading to the foot of a mountain.\n Which way will you go?\n\ntype the FULL PHRASE to choose your option:\n1) forest\n2) mountain\n3) go back to sleep\n");
    
    String ans1 = scan.nextLine();
    
    if(ans1.equalsIgnoreCase("forest")){
      System.out.println("You take the path into the forest. After some walking in the dark and dreary enviornment you come across a house. The house has 2 entrances, the front door and the basement. Which way will you go?\n\ntype the FULL PHRASE to choose your option:\n1) front door\n2) basement\n");
      
      String ansf = scan.nextLine();

      if(ansf.equalsIgnoreCase("front door")){
        System.out.println("You decide to go right through the front door, it is unlocked. Inside there are two places to explore up the stairs or the bottom floor. Which will you investigate first?\n\ntype the FULL PHRASE to choose your option:\n1) upstairs\n2) bottom floor\n");

      }else if(ansf.equalsIgnoreCase("basement")){
        System.out.println("You walk around the back of the house and to the basement door, It takes some strength but after a couple tugs, you pry the door open. As soon as the door is ajar you hear a click, and have just enough time to see a string on the door handle pull the trigger on a crossbow aimed straight at you.\n\nApparently you should never trust a basement, you died.\n\n ENDING 2");

      }else{
        System.out.println("Your phrase was not an option");
      }

    }else if(ans1.equalsIgnoreCase("mountain")){
      System.out.println("You take the path to the mountain, when you reach the base there is an old well that seems unusually deep, pulling up the bucket will a long amount of time and you will hurt your hands. Would you like to pull up the bucket or continue up the mountain?\n\ntype the FULL PHRASE to choose your option:\n1) pull\n2) continue");
      
      String ansm = scan.nextLine();

      if(ansm.equalsIgnoreCase("pull")){
        hasKey = true;
        isHurt = true;
        System.out.println("After a couple grueling hours of pulling, the bucket reaches the top. Your hands are blistered and battered but there was a merit, inside is a key, you grab it. You continue up the mountain.\n\nBy the time you reach a plateau it is dark, luckily there is an old, worn down building that looks like it hasn't been used for some time. Will you check out the building or continue up the mountain?\n\ntype the FULL PHRASE to choose your option:\n1) building\n2) continue");

        String ansp = scan.nextLine();

        if(ansp.equalsIgnoreCase("building")){
         System.out.println("");

        }else if(ansp.equalsIgnoreCase("continue")){
          

        }else{
          System.out.println("Your phrase was not an option");
        }

      }else if(ansm.equalsIgnoreCase("continue")){
        System.out.println("You continue up the mountain. After some time you reach a plateau. There is an old, worn down building that looks like it hasn't been used for some time. The door is locked tight so you cannot enter. \n\nAs you continue up the mountain you come across a cave, do you enter or continue?\n\ntype the FULL PHRASE to choose your option:\n1) cave\n2) continue");

      }else{
        System.out.println("Your phrase was not an option");
      }

    }else if(ans1.equalsIgnoreCase("go back to sleep")){
      System.out.println("You somehow reach the conclusion that the best course of action is to go back to sleep... somehow. You close your eyes and drift back to sleep, not a care in the world.\n\n ENDING 1");

    }else{
      System.out.println("Your phrase was not an option");
    }
  }
}