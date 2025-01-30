import java.util.*;
class Main {
  public static void main(String[] args) {
ArrayList<String> groceries = new ArrayList<String>();
groceries.add("Bananas");
groceries.add("Wheat Bread");
groceries.add("1% milk");
groceries.add("Crackers");
groceries.add("Oatmeal");
System.out.println("Here is the current list using the built in .toString() java method: \n");
System.out.println(groceries.toString());

System.out.println("Notice the Brackets [...]\n");
System.out.println("Let's use the .set method to change one of the elements of the list\n");
groceries.set(0, "Apples");
System.out.println(groceries.toString());

ListIterator iterator = groceries.listIterator();
while(iterator.hasNext())
  System.out.println(iterator.next());

System.out.println("\nNumber of items in your list is " + groceries.size());

System.out.println("Using groceries.get(0): " + groceries.get(0));
System.out.println("Using groceries.get(1): " + groceries.get(1));

Scanner scan = new Scanner(System.in);

System.out.println("Enter another item or \"quit\" to exit");
String item = scan.next().toLowerCase();

if(item == "quit"){
  System.out.println("thank you for shopping");
}else{
  for (int i = 0; i<groceries.size(); i++){
    if(groceries.get(i).toLowerCase() == item){
      System.out.println("That Item is already on the list");
    }else{
      groceries.add(item);
    }

  }

}

  }
}