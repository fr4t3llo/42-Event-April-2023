import requests

name = input("Enter the name of a Pokemon: ").lower()
res = requests.get("https://pokeapi.co/api/v2/pokemon/" + name)
if res.status_code == 200:
  print (res.status_code)
  data = res.json()
  print("Name: " + name)
  print("Abilities:")
  abilities = data['abilities']
  for ability in abilities:
     print("- " + ability['ability']['name'])
else:
  print (res.status_code)
  print("not a pokemon")