using System;

class Program {
  public static void Main (string[] args) {
    Console.WriteLine("Welcome to the calculator!");
    
    Console.Write("Enter a number x ");
    double x = Convert.ToInt32(Console.ReadLine());
    Console.Write("Enter a number y ");
    double y = Convert.ToInt32(Console.ReadLine());
    
    Console.WriteLine("Enter the number corresponding to an operator for the equation:");
    Console.WriteLine("1: +");
    Console.WriteLine("2: -");
    Console.WriteLine("3: *");
    Console.WriteLine("4: /");
    int op = Convert.ToInt32(Console.ReadLine());
    if(op == 1){
      Console.Write("Your equation is " + x + " + " + y + " = " + (x+y));
    }else if(op == 2){
      Console.Write("Your equation is " + x + " - " + y + " = " + (x-y));
    }else if(op == 3){
      Console.Write("Your equation is " + x + " * " + y + " = " + (x*y));
    }else if(op == 4){
      Console.Write("Your equation is " + x + " / " + y + " = " + (x/y));
    }else{
      Console.WriteLine("huh?");
    }
    
  }
}