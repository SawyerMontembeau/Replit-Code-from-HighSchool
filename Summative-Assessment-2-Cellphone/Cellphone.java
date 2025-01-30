import java.text.SimpleDateFormat;
import java.util.*;
public class Cellphone {

int year;
String maker;
String model;
String color;
double price;
double batteryLife;
boolean conc;
String osp;
int diagSS;
int camMegapixelS;
int memGB;
double monthlyPlanAmt;
String billDate;

public Cellphone(int year, String maker, String model, String color, double price, boolean conc, String osp, int diagSS, int camMegapixelS, int memGB, double monthlyPlanAmt, String billDate)
{
 this.year = year;
 this.maker = maker;
 this.model = model;
 this.color = color;
 this.price = price;
 batteryLife = 100.00;
 this.conc = conc;
 this.osp = osp;
 this.diagSS = diagSS;
 this.camMegapixelS = camMegapixelS;
 this.memGB = memGB;
 this.monthlyPlanAmt = monthlyPlanAmt;
 this.billDate = billDate;
}

public String printDetail(){
  return "The phones year is: " + year + "/nThe phones maker is: " + maker + "/nThe phones model is: " + model + "/nThe phones color is: " + color + "/nThe phones price is: $" + price + "/nThe phones battery percentage is: " + batterLife + "%" + "/nThe phone's been dropped: " + conc + "/nThe phones operating system platform is: " + osp + "/nThe phones diagonal screen size is" + dss + " inches" + "/nThe phones camera megapixel size is: " + camMegapixelS + "/nThe phones memory is: " + memGB + " GB" + "/nThe phones monthly plan amount is: $" + monthlyPlanAmt + " per month" + "/nThe phones bill date is: " + billDate;
}

public double batteryLow(int time){
  if(time >= 6)
  {
    batteryLife = 0;
    return batterLife;
  }
  else if(time >= 5)
  {
    batteryLife = 10;
    return batterLife;
  }
  else if(time >= 4)
  {
    batteryLife = 30;
    return batterLife;
  }
  else if(time >= 3)
  {
    batteryLife = 50;
    return batterLife;
  }
  else if(time >= 2)
  {
    batteryLife = 70;
    return batterLife;
  }
  else if(time >= 1)
  {
    batteryLife = 80;
    return batterLife;
  }
  else if(time > 0)
  {
    batteryLife = 90;
    return batterLife;
  }
  else 
  {
    return batteryLife;
  }
}

public String droppedPhone(){
  if(conc = true){
    return "The phone has been dropped and broken";
  }else{
    return "The phone has been dropped but not broken";
  }
}

public String payBill(){
  SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
  Date date = new Date();
  String date1 = formatter.format(date);
  String stringToSplit = date1;
  String[] dateStrArr;
  String delimiter = "/";
  String[] billDStr = billDate.split(delimiter);
  int[] dateNumArr = new int[3];
  int[] dueDatesNum = new int[3];
  dateStrArr = stringToSplit(delimiter);

  for(int i = 0; i < dateStrArr.length; i++){ 
    dateNumArr[i] = Interger.parseInt(dateStrArr[i]);
  } //sets the dateNumArr to the interger form of the date in the String array (current dates)

  for(int i = 0; i < billDL.length; i++){
    dueDatesNum[i] = Interger.parseInt(billDStr[i]);
  }//sets the due date to the interger form of the bill date.

  if(dateNumArr[0] = dueDatesNum[0]){
    return "The bill is due today.";
  }else if(dateNumArr[0]<dueDatesNum[0]){
    return "The bill is due in" + Math.abs(dueDatesNum[0] - dateNumArr[0]) + " days.";
  }else if(dateNumArr[0]>dueDatesNum[0]){
    return "The bill is overdue by " + math.abs(dateNumArr[0] - dueDatesNum[0]) + " days.";
  }
}

public String memoryRemain(int pictures){
  int memUsed;
  if(pictures >= 1000){
    memUsed = 16;
  }else if(pictures >= 750){
    memUsed = 12;
  }else if(pictures >= 500){
    memUsed = 8;
  }else if(pictures >= 250){
    memUsed = 4;
  }else if(pictures >= 0){
    memUsed = 0;
  }
  
  if((memGB - memUsed) < 1) {
    return "There is less than 1 GB of memory left.";
  }else if(memGB - memUsed <= 4){
    return "There is less than 4 GB of memory left.";
  }else if(memGB - memUsed <= 8){
    return "There is less than 8 GB of memory left.";
  }else if(memGB - memUsed <= 12){
    return "There is less than 2 GB of memory left.";
  }else if(memGB - memUsed <= 16){
    return "There is less than or 16 GB of memory left";
  }
}

}