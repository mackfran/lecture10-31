import urllib.request
from bs4 import BeautifulSoup
import re

# Name: Mackenzie Francisco
# uniqname: mackfran
# Section Day/Time: Thursday/1-2PM
# References: Zoë Halbeisen, Amanda McLeod, Python for Everybody textbook (Chapters 6, 9, 11, and 12)
#             Internet sources (listed above the code for the part they were used for)
# Other notes: For Part Four, I went for the "Additional 10 points" option where you enter the link to
#              the entire directory.

# Part 1
## Internet sources:
	# http://www.practicepython.org/solution/2014/07/10/17-decode-a-web-page-solutions.html
	# https://docs.python.org/3.0/library/urllib.request.html
	# http://stackoverflow.com/questions/8176763/printing-every-entry-in-a-list-on-its-own-individual-line-in-python
	# http://stackoverflow.com/questions/23814280/how-to-check-if-a-list-has-an-empty-string

print('New York Times -- First 10 Story Headings')

# the URL of the NY Times website we want to parse
url = 'http://www.nytimes.com'
# effectively open and read the url
html = urllib.request.urlopen(url).read()
# decode the HTML text of the NY Times homepage
soup = BeautifulSoup(html, 'lxml')

# create empty list of headlines
nyt_headlines = []
# find and loop through all elements on page with the class name 'story-heading'
for story_heading in soup.find_all(class_='story-heading'):
	# if the heading is a link, format it nicely and add it to the list of headlines
	if story_heading.a: 
		nyt_headlines.append(story_heading.a.text.replace('\n', ' ').strip())
	# otherwise, take out the contents and format it nicely
	else: 
		nyt_headlines.append(story_heading.contents[0].strip())

# create empty list of headlines with text
text_headlines = []
for story_heading in nyt_headlines:
	# if the headline is not empty, add it to this new list
	if story_heading != '':
		text_headlines.append(story_heading)
	else:
		continue

# print out only the first 10 headlines
for x in text_headlines[:10]:
	print(x)
print('\n')

# Part 2
## Internet sources:
	# http://www.practicepython.org/solution/2014/07/10/17-decode-a-web-page-solutions.html
	# https://docs.python.org/3.0/library/urllib.request.html

print('Michigan Daily -- MOST READ')

# the URL of the Michigan Daily page we want to parse
url = 'https://www.michigandaily.com/section/opinion'
# effectively open and read the url
html = urllib.request.urlopen(url).read()
# decode the HTML text of the Michigan Daily page
soup = BeautifulSoup(html, 'lxml')

# find and loop through all elements on page in the "MOST READ" panel
for story_heading in soup.find_all(class_='panel-pane pane-mostread'): 
	# find and loop through all the listed elements in this panel
	for article in story_heading.find_all(class_='item-list'):
		# find and loop through all the tags, format them nicely, and print them
		for article_name in article.find_all('a'):
			print(article_name.text.replace('\n', ' ').strip())
print('\n')

# Part 3
## Internet sources:
	# http://stackoverflow.com/questions/11696745/beautifulsoup-extract-img-alt-data
	# https://www.crummy.com/software/BeautifulSoup/bs3/documentation.html#The%20attributes%20of%20Tags

print("Colleen's page -- Alt tags")

# the URL of the web page we want to parse
url = 'http://www.collemc.people.si.umich.edu/data/gallery.html'
# effectively open and read the url
html = urllib.request.urlopen(url).read()
# decode the HTML text of the web page
soup = BeautifulSoup(html, 'lxml')

# find and loop through all images on the page
for image in soup.find_all('img'):
	# use the get() method for dictionaries to print the alt text for images that have it
	# or print an error message for images that don't
	print(image.get('alt', 'No alternative text provided!!'))
print('\n')


# Part 4
## Internet sources:
	# http://stackoverflow.com/questions/15517483/how-to-extract-urls-from-a-html-page-in-python
	# https://github.com/caogl/SI-601/blob/master/Class%203:%20Retrieving%20and%20manipulating%20web%20data/si601-lab3.py
	# http://stackoverflow.com/questions/3075550/how-can-i-get-href-links-from-html-using-python
	# http://stackoverflow.com/questions/7732694/find-specific-link-w-beautifulsoup

print('Emails connected to UMSI directory')

# prompt user for the URL of the web page we want to parse (in this case, the link to the full directory)
url = input('Enter link to full directory - ')
# effectively open and read the url
html = urllib.request.urlopen(url).read()
# decode the HTML text of the web page
soup = BeautifulSoup(html, 'lxml')

# find and loop through all anchor tags on the page
# utilize regular expressions to compile the links beginning with '/node/'
for link in soup.find_all('a', href=re.compile('/node/')):
	contact_link = link.get('href')
	# the URL of the main web page plus the link to an individual contact's page we want to parse
	url = 'https://www.si.umich.edu' + contact_link
	# effectively open and read the url
	html = urllib.request.urlopen(url).read()
	# decode the HTML text of the web page
	soup = BeautifulSoup(html, "lxml")
	# find and loop through all elements on page with class name 'field-item even'
	for contact in soup.find_all(class_='field-item even'):
		# if the heading is a link, format it nicely
		if contact.a:
			email = contact.a.text.replace('\n', ' ').strip()
			# if the reformatted link ends with 'umich.edu', print it
			if email.endswith('umich.edu'):
				print(email)
			else:
				continue
		else:
			continue

print('\n')
print('Expected score: 150')
