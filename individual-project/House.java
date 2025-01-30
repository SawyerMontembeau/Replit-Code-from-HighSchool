public class House{
//variables
public String address;
public int bedroomAmt;
public int bathroomAmt;
public int yrBuilt;
public double sqFootage;
public String heating;//electric or oil
public double price;

//constructors
public House(String a,int bea, int baa, int yb, double sf, String h, double p){
  address = a;
  bedroomAmt = bea;
  bathroomAmt = baa;
  yrBuilt = yb;
  sqFootage = sf;
  heating = h;
  price = p;
}
//getters
public String getAddress(){
  return address;
}

public int getBedroomAmt(){
  return bedroomAmt;
}

public int getBathroomAmt(){
  return bathroomAmt;
}

public int getYrBuilt(){
  return yrBuilt;
}

public double getSqFootage(){
  return sqFootage;
}

public String getHeating(){
  return heating;
}

public double getPrice(){
  return price;
}
//setters
public String setAddress(String a){
  address = a;
  return address;
}

public void setBedroomAmt(int bea){//the amount of bedrooms cannot be over 10
  if(bea < 0 || bea > 10){
    System.out.println("this amount of bedrooms is illogical");
  }else{
    bedroomAmt = bea;
  }
}

public void setBathroomAmt(int baa){// the amount of bathrooms can not be over 10
  if(baa < 0 || baa > 10){
    System.out.println("this amount of bathrooms is illogical");
  }else{
    bathroomAmt = baa;
  }
}

public void setYrBuilt(int yb){ // the yrBuilt cannot be too old
  if(yb < 1800){
    System.out.println("please enter a newer date");
  }else{
    yrBuilt = yb;
  }
}

public void setSqFootage(double sf){// the sqFootage cannot be negative or too large
  if(sf < 0 || sf > 5000){
    System.out.println("this amount of sq footage is illogical");
  }else{
    sqFootage = sf;
  }
}

public void setHeating(String h){ //heating cannot be anything but electric or oil
   if(h.equalsIgnoreCase("electric")){
     heating = h;
   }else if(h.equalsIgnoreCase("oil")){
     heating = h;
   }else{
     System.out.println("That type of heating does not exist");
   }
}

public void setPrice(double p){
  if(p >= 10000000){
    System.out.println("this price is too high for the database");
  }else{
    price = p;
  }
}
//methods

//heating usage
}