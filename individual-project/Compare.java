public class Compare{

public static boolean compareBedroomAmt(int bel, int beu){
  if(bel - beu <= math.abs(1)){
    return true;
  }else{
    return false;
  }
}

public static boolean compareBathroomAmt(int bal, int bau){
  if(bal - bau <= math.abs(1)){
    return true;
  }else{
    return false;
  }
}

public static boolean compareYrBuilt(int ybl, int ybu){
  if(ybl - ybu <= math.abs(30)){
    return true;
  }else{
    return false;
  }
}

public static boolean compareSqFootage(double sfl, double sfu){
  if(sfl - sfu <= math.abs(500)){
    return true;
  }else{
    return false;
  }
}

public static boolean compareHeating(){
  
}

public static boolean comparePrice(){
  
}

}