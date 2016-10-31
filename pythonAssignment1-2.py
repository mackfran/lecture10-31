import operator

##COMMENT YOUR CODE!!:
print ('Name: Mackenzie Francisco')
print ('uniqname: mackfran')
# Section Day/Time: Thursday/1-2PM
# References: Ibrahim R, Kelly S, the GSIs, Python for Everybody textbook (Chapters 6 and 10), 
#             Internet sources (listed above the code for the task they were used for)
# Expected score: 100
# Other notes

#
# For each task below, fill in the code for the functions below.
# main() will call the functions with a few different inputs, check
# the results, and print 'OK' when each function's output is correct.
#
# The starter code for each function includes a 'return'
# which is just a placeholder for your code. You need to fill in code
# for the function that returns the correct result as specified.



# Task A. String manipulation (function 'string_manip')
#   Remove any leading and trailing spaces from the input string
#   Convert the input string to upperscase

#   Replace any remaining spaces with the pound sign '#'
#   Remove any occurences of the string UMSI
#   If the remaining string consists entirely of digits (0..9), just return that string.
#   If the remaining string is a single character just return that string.
#   Otherwise, return a the string in reverse
#

## Internet sources:
	# http://stackoverflow.com/questions/18174416/replacing-spaces-with-hyphens
	# http://stackoverflow.com/questions/21388541/how-do-you-check-if-a-string-contains-only-numbers-python
	# http://stackoverflow.com/questions/931092/reverse-a-string-in-python

def string_manip(s):
  # remove white space from the beginning and end of the string
  # convert the string to all uppercase letters
  # replace all remaining spaces with the pound sign
  string = s.strip().upper().replace(' ','#')
  #remove occurences of UMSI string
  if 'UMSI' in string:
  	string = string.replace('UMSI','')
  
  # if the string is a single character, return that string
  if len(string) == 1:
  	return string
  # if the string consists entirely of digits, return that string
  elif string.isdigit() == True:
  	return string
  # otherwise, return the string in reverse
  else:
  	return string[::-1]


# Task B. Loops (function 'bananas')
#
# Given an integer count, return a string
# of the form '1 banana, 2 banana, ..., <count> banana', where <count> is the number
# passed in.  There are some special rules:
#   If the count is zero, return 'no bananas'
#   If the count is one, return 'a banana'
# However, if the count is 6 or more, then use the string
# ' and <num> more bananas' as the last item instead of the actual list of bananas,
# where <num> is the number of remaining bananas.  Note that in this case, there should
# be *no comma* between the last numbered banana and the "and <n> more bananas" string.
#
# Examples:
#     bananas(0)  returns 'no bananas'
#     bananas(3)  returns '1 banana, 2 banana, 3 banana'
#     bananas(5)  returns '1 banana, 2 banana, 3 banana, 4 banana, 5 banana'
#     bananas(10) returns '1 banana, 2 banana, 3 banana, 4 banana, 5 banana and 5 more bananas'  # note: no final comma
#     bananas(20) returns '1 banana, 2 banana, 3 banana, 4 banana, 5 banana and 15 more bananas'
#

def bananas(count):
	# creates empty string
  string = ""

  # deals with special rules for no bananas or one banana
  if count == 0:
  	return ('no bananas')
  elif count == 1:
  	return ('a banana')

  # if the count is 6 or more
  elif count > 6:
  	# finds number of remaining bananas after the first 6
  	difference = count - 5
  	# creates string of the form '1 banana, 2 banana, ..., <count> banana'
  	for x in range(1,6):
  		string += str(x) + ' banana, '
  	# removes final comma
  	string = string[:-2]
  	# adds string of the form ' and <difference> more bananas' to account for the remaining bananas
  	string += ' and ' + str(difference) + ' more bananas'
  	return string

  # if the count is 2, 3, 4, or 5
  elif count > 1 and count < 6:
  	for x in range(1,6):
  		string += str(x) + ' banana, '
  	string = string[:-2]
  	return string
  
  else:
  	print('Error')
 

# Task C. Palindromes
#
# Given a string, determine if the string is a palindrome.
#
# Examples:
#     palidrome('anna')  returns 'True'
#     palidrome('abcdef')  returns 'False'
#     palidrome('')  returns 'True'

## Internet sources:
	# http://stackoverflow.com/questions/931092/reverse-a-string-in-python

def palindrome(word):
  # if a string is equivalent to itself in reverse, it is a palindrome
  if word == word[::-1]:
  	return True
  else:
  	return False


# Task D. Dictionaries and sorting (function 'name_counts')
#
# Given a list of strings, return a list of tuples containing the counts of each of the
# UNIQUE strings. The returned results should be ordered by the counts
# in decreasing order. In case of ties of counts, break the tie by string value in increasing order.
#
# Examples:
#   name_counts(['Becca', 'Catherine', 'Catherine', 'Catherine', 'Christopher', 'Christopher'])
# should return [('Catherine', 3), ('Christopher', 2), ('Becca', 1)]
#
#   name_counts(['Christopher', 'Mike', 'Becca', 'Christopher', 'Bacon', 'Catherine', 'Christopher', 'Becca'])
# should return [('Christopher', 3), ('Becca', 2), ('Bacon', 1), ('Catherine', 1), ('Mike', 1)])
#

## Internet sources:
	# http://stackoverflow.com/questions/18595686/how-does-operator-itemgetter-and-sort-work-in-python
	# https://docs.python.org/2.7/howto/sorting.html
	# http://stackoverflow.com/questions/3496518/python-using-a-dictionary-to-count-the-items-in-a-list

def name_counts(names):
  # creates empty dictionary
  dictionary = {}

  # parses through each name in the list of names
  for name in names:
  	# if the name is not already in the dictionary, its count = 1
  	if name not in dictionary:
  		dictionary[name] = 1
  	# if the name is already in the dictionary, adds 1 to its count
  	else:
  		dictionary[name] += 1

  # creates a list of tuples where each tuple is a key-value pair
  t = list(dictionary.items())
  
  # sorts the list alphabetically
  	## the itemgetter function takes a list and grabs an n-th element out of it
  	## this first sort grabs the first element (the name), sorting the list alphabetically
  first_sort = sorted(t, key=operator.itemgetter(0))
  # sorts the alphabetically sorted list by the counts in decreasing order
  	## this sort grabs the second element (the count), and initially sorts the list by counts in increasing order
  	## setting reverse=True sorts the list by counts in decreasing order
  second_sort = sorted(first_sort, key=operator.itemgetter(1), reverse=True)

  return second_sort


#######################################################################
# DO NOT MODIFY ANY CODE BELOW
#######################################################################

# Provided simple test() function used in main() to print
# what each function returns vs. what it's supposed to return.
def test(got, expected):
  score = 0;
  if got == expected:
    score = 5;
    print(" OK ",end=" ")
  else:
    print (" XX ", end=" ")
  print("Got: ",got, "Expected: ",expected)
  return score


# Provided main() calls the above functions with interesting inputs,
# using test() to check if each result is correct or not.
def main():
  total = 0;
  print()
  print ('Task A: string manipulation'
   """Each OK is worth five points.""")
 # OK  got: ' Colleen van Lent' expected: 'NEL#NAV#NEELLOC'
 # OK  got: '  276876 expected: '276876'
 # OK  got: '  276 876 expected: '678#672'
 # OK  got: '!UMSI!' expected: '!!'
 # OK  got: 'UMSI' expected: ''
 # OK  got: '' expected: ''
 #  """)
  total += test(string_manip(' Colleen van Lent'), 'TNEL#NAV#NEELLOC')
  total += test(string_manip('276876  '), '276876')
  total += test(string_manip('  276 876'), '678#672')
  total += test(string_manip('!UMSI!'), '!!')
  total += test(string_manip('UMSI'), '')
  total += test(string_manip(''), '')


  print ('Task B: bananas'
       """Each OK is worth five points.""")

  # Each line calls bananas, compares its result to the expected for that call.
 #  """ If this is what you get, you are good to go. Each OK is worth five points.
 # OK  got: 'no bananas' expected: 'no bananas'
 # OK  got: 'a banana' expected: 'a banana'
 # OK  got: '1 banana, 2 banana, 3 banana, 4 banana, 5 banana' expected: '1 banana, 2 banana, 3 banana, 4 banana, 5 banana'
 # OK  got: '1 banana, 2 banana, 3 banana, 4 banana, 5 banana and 5 more bananas' expected: '1 banana, 2 banana, 3 banana, 4 banana, 5 banana and 5 more bananas'
 # OK  got: '1 banana, 2 banana, 3 banana, 4 banana, 5 banana and 94 more bananas' expected: '1 banana, 2 banana, 3 banana, 4 banana, 5 banana and 94 more bananas'
 #  """)
  total += test(bananas(0), 'no bananas')
  total += test(bananas(1), 'a banana')
  total += test(bananas(5), '1 banana, 2 banana, 3 banana, 4 banana, 5 banana')
  total += test(bananas(10), '1 banana, 2 banana, 3 banana, 4 banana, 5 banana and 5 more bananas')
  total += test(bananas(99), '1 banana, 2 banana, 3 banana, 4 banana, 5 banana and 94 more bananas')

  print ('Task C: palindromes' """Each OK is worth five points.""")
 
 #  """ If this is what you get, you are good to go. Each OK is worth five points.
 # OK  got: 1 expected: 1
 # OK  got: 2 expected: 2
 # OK  got: 3 expected: 3
 # OK  got: 5 expected: 5
 # OK  got: 0 expected: 0
 #  """)
  total += test(palindrome('anna'), True)
  total += test(palindrome('bookkeeper'), False)
  total += test(palindrome('a'), True)


  
  print('Task D: name_counts'
  """ Each OK is worth five points.""")
 # OK  got: [] expected: []
 # OK  got: [('Christopher', 1)] expected: [('Christopher', 1)]
 # OK  got: [('Christopher', 3)] expected: [('Christopher', 3)]
 # OK  got: [('Bacon', 3), ('Christopher', 3), ('Eddie', 1)] expected: [('Bacon', 3), ('Christopher', 3), ('Eddie', 1)]
 # OK  got: [('Bacon', 3), ('Eddie', 2), ('Becca', 1), ('Catherine', 1), ('Christopher', 1), ('Mike', 1)] expected: [('Bacon', 3), ('Eddie', 2), ('Becca', 1), ('Catherine', 1), ('Christopher', 1), ('Mike', 1)]
 #  """
  total += test(name_counts([]), [])
  total += test(name_counts(['Christopher']), [('Christopher', 1)])
  total += test(name_counts(['Christopher', 'Christopher', 'Christopher']), [('Christopher', 3)])
  total += test(name_counts(['Eddie', 'Bacon', 'Christopher', 'Christopher', 'Christopher', 'Bacon', 'Bacon']), [('Bacon', 3), ('Christopher', 3), ('Eddie', 1)])
  total += test(name_counts(['Bacon', 'Catherine', 'Eddie', 'Bacon', 'Becca', 'Christopher', 'Bacon', 'Eddie', 'Mike']), [('Bacon', 3), ('Eddie', 2), ('Becca', 1), ('Catherine', 1), ('Christopher', 1), ('Mike', 1)])
  
  
  print("You final score is: ",total)
  print("You will earn 5 points for properly commenting your code and modifying the file to print your name and unique id at the start.")
# Standard boilerplate to call the main() function.
if __name__ == '__main__':
  main()