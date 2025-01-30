#API -  Application programming interface
#The API allows one computer to talk to another
#API's  are a service that connects your software application to another company's data, software, applications and servers over the internet
#GET requests - you getting information from something else
#POST requests - you posting information to their site
#API information is located at url's
#"endpoint" - is simpliy the specific url where the API's info is located on their server
#The data that we recieve from the API call is in the form of a JSON file which is converted to a python dictionary
# must import the requests.py module in order to make API calls

#This program is going to access SWAPI's API of all things Star Wars
import requests
import re
def main():
  url = "https://swapi.dev/api/people/"
  responseObject = requests.get(url)
  print("STATUS CODE:", responseObject)
  response_dict = responseObject.json()
  print(response_dict)
  print("\nPrint the keys to the response_dict dictionary: ")
  print(response_dict.keys(),"\n")
  people = response_dict["results"]
  #people is a list OF dictionaries, each dictionary is a Star Wars Character
  print("\nHere is the dictionary for Luke Skywalker: \n", people[0])
  home_url = people[0]["homeworld"]
  home_dict_obj = requests.get(home_url)
  home_dict = home_dict_obj.json()
  print(home_dict["name"])

  #use people to print the following fior every starwars character
  #Name
  #birth year
  #home world
  #films
  #one other piece of info you are interested in

  #write a function called convert_bby(bby) that will convert the bby date to an earth date
  def convert_bby(bby): 
    bbyI = int(re.search(r'\d+',bby).group())
    yr = 1815-bbyI
    date = str(yr) + "AD"
    print("Birth Year AD:",date)
  
  for person in people:
    print("Name:",person["name"])
    print("Birth Year:", person["birth_year"])
    convert_bby(person["birth_year"])
    print("Home World:",requests.get(person["homeworld"]).json()["name"])
    print("Films:")
    for film in person["films"]:
      print(requests.get(film).json()["title"])
    print("Starships:")
    for starship in person["starships"]:
      print(requests.get(starship).json()["name"])
    print("\n")
  
main()