public class Sport{

private String name;
private int numAthletes;

public Sport(){ //default constructor
  name ="";
  numAthletes = 0;
}

public Sport(String n, int numAth){ //overloaded constructor
  name = n;
  numAthletes = numAth;
}

public Sport(String n){
  name = n;
  numAthletes = 0;
}

public void setName(String n){ //setter | 
  name = n;
}

public String getName(){ //getter | accessor method
  return name;
}

public int getNumAthletes(){ //getter | accessor method
  return numAthletes;
}

public String toString(){// toString method
  return "Sport: " + name + "\nNumber of Athletes: " + numAthletes;
}

}