import java.util.*;
public class PasswordGenerator{

public int pwnum = 0;
public String prefix;
public int length;
public Random rand = new Random();

public PassworGenerator(int l, String p){
  prefix = p;
  length = l;
}

public String pwGen(){
  String pswrd = prefix + ".";
  for(int i = 0; i < length; i++){
    pswrd = pswrd + rand.nextInt(10);
  }
  pwnum += 1;
  return pswrd;
}

public int pwCount(){
  return pwnum;
}

public PasswordGenerator(int l){
  prefix = "A";
  length = l;
}

}