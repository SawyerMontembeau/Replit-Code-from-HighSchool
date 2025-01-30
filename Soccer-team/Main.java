import java.util.*;
import java.text.NumberFormat;
import java.util.ArrayList;
import static java.lang.System.*;

class Main {
  public static void printDetail(ArrayList<Roster> teamRoster)
  {
    NumberFormat fmt = NumberFormat.getCurrencyInstance();

    out.println("*******************************************************");
    out.println("Soccor Team Roster Report\n");
    out.println("Number of Players on team " + Roster.count);
    double total_salary = 0;
    for(int i = 0; i<teamRoster.size(); i++)
    {
      total_salary += teamRoster.get(i).salary;
    }
    out.println("Team Salary: " + fmt.format(total_salary));
    out.println("Average Player Salary: " + fmt.format(total_salary/teamRoster.size())+ "\n");
    out.println("Player Roster Details: \n");
    out.println("Name\t\tCountry\tPosition\tJersey\t\tSalary\tGoals\tAssists");
    out.println("-------------------------------------------------------");
  }
  public static void main(String[] args) {
  
  Scanner input = new Scanner(System.in);
  out.println("You are going to build a soccor team of Players.\n");

  ArrayList<Roster> team = new ArrayList<Roster>();
  String answer = "yes";
  double total_salary = 0;

  while(answer.equalsIgnoreCase("yes"))
  {
    out.println("What is the players name?: ");
    String name = input.nextLine();

    out.println("What is the players country?: ");
    String country = input.nextLine();

    out.println("What is the players position? (Offence, Defence, or Mid): ");
    String position = input.nextLine();
    
    out.println("What is the players jersey number?: ");
    int jersey = input.nextInt();

    out.println("What is the players salary?: ");
    double salary = input.nextDouble();

    out.println("How many goals does the player have?: ");
    int goals = input.nextInt();

    out.println("How many assists does the player have?: ");
    int assists = input.nextInt();

    Roster player = new Roster(name,position,goals,assists,jersey,country,salary);
    team.add(player);

    out.println("Do you want to add another player? yes/no: ");
    answer = input.next();
  }
  printDetail(team);
  for(int i = 0; i < team.size(); i++)
  {
    out.println(team.get(i).toPrint());
  }
  
  out.println("\nPlayer Updates (NEW goals, assists, and salary): ");
  out.println("\nWould you like to update player information? yes/no: ");
  answer = input.nextLine();

  if(answer.equalsIgnoreCase("yes"))
  {
    total_salary = 0;
    while(answer.equalsIgnoreCase("yes"))
    {
      out.println("Name of player: ");
      String name = input.nextLine();

      out.println("New goals scored: ");
      int goals = input.nextInt();

      out.println("New assists: ");
      int assists = input.nextInt();

      out.println("Current Salary: ");
      double salary = input.nextDouble();

for (int i = 0; i < team.size(); i++)
{
    if(team.get(i).name.equalsIgnoreCase(name))
    {
      team.get(i).update(goals,assists,salary);
      break;
    }
  } 
  out.println("\nDo you want to update player information? yes or no: ");
  answer = input.nextLine();
    }
  printDetail(team);
  for(int i = 0; i < Roster.count; i++)
  {
    out.println(team.get(i).toPrint());
  } 
  }
  }
}
