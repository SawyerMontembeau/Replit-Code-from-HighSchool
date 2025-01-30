using System;

class Program {
  public static void Main (string[] args) {
    Console.WriteLine ("Hello Dylan");
    //variables - string, char, int, double, bool
    string name = "Kennebunk";
    string phrase = "Hello and Welcome to " + name + " Highschool";
    char grade = 'A';
    int num = 30;
    double gpa = 3.4;
    bool isPresent = true;

    Console.WriteLine(phrase);
    Console.WriteLine(phrase.Length);
    Console.WriteLine("hello students".ToUpper());
    Console.WriteLine("hello students".ToLower());
    Console.WriteLine(phrase.Contains("Welcome"));
    Console.WriteLine(name[0]);
    Console.WriteLine(phrase.IndexOf("and"));
    Console.WriteLine(phrase.Substring(10,7));

    //Math
    int a  = 3;
    int b = 5;
    int c = 9;
    Console.WriteLine(a + b + c);
    Console.WriteLine("a + b + c = " + (a + b + c));
    Console.WriteLine(Math.Pow(3,2));
    Console.WriteLine(Math.Abs(-55));
    Console.WriteLine(Math.Sqrt(64));
    Console.WriteLine(Math.Min(21,121));
    Console.WriteLine(Math.Max(3,14));

    //user input with ReadLine

    Console.Write("Enter your name: ");
    string n = Console.ReadLine();
    Console.WriteLine("hello " + n + "!");

    int num2 = Convert.ToInt32("22");
    Console.WriteLine(5+num2);

    Console.Write("Enter a number x ");
    int x = Convert.ToInt32(Console.ReadLine());
    Console.Write("Enter a number y ");
    int y = Convert.ToInt32(Console.ReadLine());
    Console.Write("x + y = " + (x+y));

    //Arrays
    int[] specialNums = {3,4,9,19,88,16};
    Console.WriteLine(specialNums[4]);

    string[] friends = new string[5];
    friends[0] = "Dylan Hurley";
    friends[1] = "Flynn Crean";
    friends[2] = "Max Aiello";
    friends[3] = "jef";
    friends[4] = "carl";
    
    sayHi("Flumpo");
    cube(3);
  }//end of main method
  
  //write static methods here
  static void sayHi(string name){
    Console.WriteLine("Hello " + name + "!");
  }

  static void cube(double num){
    Console.WriteLine(Math.Pow(num,3));
  }
}