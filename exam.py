# name: Mackenzie Francisco
# uniqname: mackfran

import urllib.request
from bs4 import BeautifulSoup
import operator
import re

# Part A

url = input('Enter link - ')
html = urllib.request.urlopen(url).read()
soup = BeautifulSoup(html, 'lxml')

all_links = {}
for link in soup.find_all('a'):
	page_link = link.get('href')
	
	if page_link == '':
		key = 'Empty'
		if key not in all_links:
			all_links[key] = 1
		else:
			all_links[key] += 1

	elif page_link not in all_links:
		all_links[page_link] = 1

	else:
		all_links[page_link] += 1

for k, v in sorted(all_links.items(), key=operator.itemgetter(1)):
	print(v, k)

# Part B

email_list = []
def parseData(fname):
	data = open(fname, 'r')
	for line in data:
		match = re.findall(r'[\w\.-]+@[\w\.-]+', line)
		for item in match:
			if item not in email_list:
				email_list.append(item)

firstpart_emails = []
for email in email_list:
	first_part = email.split('@')[0]
	firstpart_emails.append(first_part)

parseData('mbox-short.txt')
print(firstpart_emails)

print('uniqname: mackfran')
print('Expected score: 35')