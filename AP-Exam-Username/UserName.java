import java.util.*;
public class UserName

{

// The list of possible user names, based on a user’s first and last names and initialized by the constructor.

private ArrayList<String> possibleNames;

public String firstName;
public String lastName;

public UserName (String firstName, String lastName){

  firstName = this.firstName;
  lastName = this.lastName;

  for (int i = 0; i < firstName.length(); i++) {
    possibleNames.add(lastName + firstName.substring(0 , i));
  }
}

public boolean isUsed(String name, String[] arr){ 

for(int i = 0; i<arr.length ;i++){
  
  if(name.equals(arr[i])){
    return true;
    break;
  }

}
return false;
}

 
public ArrayList<String> setAvailableUsernames (String[ ] usedNames){

 for(int i = 0; i < possibleNames.size(); i++){
   
   if(isUsed(possibleNames.get(i) , usedNames)){
   possibleNames.remove(i);
   }

 }
return possibleNames;
}

}

