#The first thing that we must do to work with APIs in python is to import the python request module
import requests
#allows us to use the .get method to call up the API url

url = 'http://api.github.com/search/repositories?q=language:python&sort=stars'
# The url directs the request to part of Github's website that responds to API calls
# search/repositories tells the api to conduct a search through all repositories on github
# ? - it signals that we are about to pass an argument
# q= - signals that we are about to start a query
# &sort = stars - gets the reviews

responseObject = requests.get(url)
response_dict = responseObject.json()
print(response_dict.keys())
print(response_dict['total_count'])
print(response_dict['incomplete_results'])
#create a new list that is the value of the key 'items' in the dictionary response_dict

repo_dicts = response_dict['items']
print("Repositories: " + str(len(repo_dicts)))
repo_dict = repo_dicts[0]
print("Number of keys in the first dictionary:",str(len(repo_dict)))

i = 1
for key in sorted(repo_dict.keys()):
  print(str(i) +". " + key)
  i += 1

print("Stars: ", repo_dict['stargazers_count'])
print("Owner:", repo_dict["owner"]["login"])
print("Trees:",repo_dict["trees_url"])
print("Watchers:", repo_dict["watchers"])
print("Forks:", repo_dict["forks"])

#create a for loop to print selected info of your choice about each and every repository inside the list of repositories that we called repo_dicts.

counter = 0
for repo_dict in repo_dicts:
  print("\n" + str(counter) + ". ")
  print("Stars: ", repo_dict['stargazers_count'])
  print("Owner:", repo_dict["owner"]["login"])
  print("Trees:",repo_dict["trees_url"])
  print("Watchers:", repo_dict["watchers"])
  print("Forks:", repo_dict["forks"])
  counter +=1

#dogs - https://dog.ceo/api/breeds/image/random
#I-tunes Search - https://itunes.apple.com/search?term=radiohead
#jokes - https://v2.jokeapi.dev/joke/Any?safe-mode
#teleport - https://api.teleport.org/api/urban_areas/teleport%3A9q8yy/scores/