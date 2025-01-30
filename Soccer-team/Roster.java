import java.text.NumberFormat;

public class Roster{
  public String name, position;
  public int goals;
  public int assists;
  public int jersey_number;
  public String country;
  public double salary;
  public static int count = 0;

  public Roster(String name,String position,int goals, int assists, int jersey_number, String country,double salary)
  {
    this.name = name;
    this.position = position;
    this.goals = goals;
    this.assists = assists;
    this.jersey_number = jersey_number;
    this.country = country;
    this.salary = salary;

    count++;
  }

  public void update(int goal, int asts, double sal)
  {
    goals += goal;
    assists += asts;
    salary = sal;
  }

  private static String capitalize(String phrase)
  {
      String words[] =phrase.split("\\s");
      String capitalizedWord ="";
      for(int i = 0; i < words.length; i++)
      {
      String first = words[i].substring(0,1);
      String afterFirstLetter = words[i].substring(1);
      capitalizedWord += first.toUpperCase() + afterFirstLetter.toLowerCase() + " ";
      }
      return capitalizedWord.trim();
  }

  public String toPrint()
  {
    NumberFormat fmt = NumberFormat.getCurrencyInstance();

    return capitalize(name) + "\t" +capitalize(country) +  "\t" + capitalize(position) +  "\t\t" + jersey_number + "\t\t" + fmt.format(salary) + "\t" + goals + "\t" + assists;
  }

}