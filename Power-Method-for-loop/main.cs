using System;

class Program {
  public static void Main (string[] args) {
    toPow(5,2);
  }
  static void toPow(double num, double pow){
    double powNum = num;
    for(int i = 1; i<pow;i++){
      powNum = powNum * num;
    }
    Console.WriteLine(powNum);
  }
  
}