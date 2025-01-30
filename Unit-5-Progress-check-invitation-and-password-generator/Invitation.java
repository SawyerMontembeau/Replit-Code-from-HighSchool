public class Invitation{

private String hostName;
private String address;


public Invitation(String n, String a){
  hostName = n;
  address = a;
}

public String returnHost(){//a
  return hostName;
}

public String updateAddress(String ad){//b
  address = ad;
  return address;
}

public String fullInv(String guest){ //c
  String fullInv = "Dear " + guest + ", please attend my event at " + address + ". See you then, " + hostName;
  return fullInv;
}

public Invitation(String address){//d
  this.address = address;  
  hostName = "Host";
}

}