import operator

##COMMENT YOUR CODE!!:
# Name: Mackenzie Francisco
# Section Day/Time: Thursday/1-2PM
# References:
# Expected score:
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

## http://stackoverflow.com/questions/18174416/replacing-spaces-with-hyphens
## http://stackoverflow.com/questions/21388541/how-do-you-check-if-a-string-contains-only-numbers-python

def string_manip(s):
  line = s.strip().upper().replace(' ','#')
  if "UMSI" in line:
    line - line.replace('UMSI','')
  try:
    line = int(line)
    return line
  except:
    if len(line) == 1:
      return line
    else: 
      return line[::-1]

  # return '' ### Replace with your code

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
### Your code goes here
  print('Fill in code for bananas')


  # return '' ### Replace with your code
 

# Task C. Palindromes
#
# Given a string, determine if the string is a palindrome.
#
# Examples:
#     palidrome('anna')  returns 'True'
#     palidrome('abcdef')  returns 'False'
#     palidrome('')  returns 'True'

def palindrome(word):
 ### Your code goes here
  print('Fill in code for palindrome')


  # return '' ### Replace with your code


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

def name_counts(names):
#### Your code goes here
  print('Fill in code for name_counts')


  # return '' ### Replace with your code

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