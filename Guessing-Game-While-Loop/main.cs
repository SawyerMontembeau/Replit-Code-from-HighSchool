using System;

class Program {
  public static void Main (string[] args) {
      string secret_word = "psychology";
      bool wordGuessed = false;
      int attempt = 1;
    while(wordGuessed == false && attempt < 6){
      Console.WriteLine("Guess a word, you have 5 attempts, this is attempt # " + attempt);
      string word = Console.ReadLine();
      if(word == secret_word){
        wordGuessed = true;
        Console.WriteLine("You Guessed the word!");
      }else{
        attempt += 1;
        Console.WriteLine("That is not the word!");
      } 
    }
  }
}