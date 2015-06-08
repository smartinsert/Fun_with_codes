from __future__ import print_function
import requests
import io
from bs4 import BeautifulSoup
import pdb
import operator
import pprint
import re

#http = urllib3.PoolManager()
base_url = 'https://www.zomato.com/'
city = raw_input('Enter the city: ')
user_dish = raw_input('Enter the dish: ')
dish = re.sub('\s+','%20',user_dish)
print(dish)
host = base_url+city
print(host)
#print(base_url+city+"/"+"restaurants?q="+dish)
http_file = requests.get(host, params={'q' : dish})

#buff = io.BufferedReader(http_file,2048)
#html_text = buff.read()

#print(html_text)
soup = BeautifulSoup(http_file)
links = soup.find_all("a")

names = soup.find_all("div",{"class":"search-name clearfix"})

restaurants = []
for data in names:
    name = data.contents[1].find_all("a",{"class":"result-title"})[0].text
    restaurants.append(str(name))  

ratings = soup.find_all("div",{"class":"search-result-stars ln24 clearfix"})

rankings = []
for number in ratings:
    rating = number.contents[1].find_all("div",{"class":"tooltip"})[0].text
    rankings.append(float(rating))

output = dict(zip(restaurants,rankings))
sorted_rest = sorted(output.items(), key=operator.itemgetter(1),reverse=True)
pprint.pprint(sorted_rest)
