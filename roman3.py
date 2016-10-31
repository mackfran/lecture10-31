#Names: Mackenzie Francisco, Angel Tsai, Owen Gatto

import unittest
from romanconvert import roman_to_int

def test(got, expected):
  score = 0
  if got == expected:
    score = 1
    print(" OK ",end=" ")
  else:
    print (" XX ", end=" ")
  print("Got: ",got, "Expected: ",expected)
  return score

def main():
	total = 0;
	total += test(roman_to_int("I"), 1)
	total += test(roman_to_int("V"), 5)
	total += test(roman_to_int("XII"), 12)
	
	##total += test(roman_to_int("B"), "Not a Roman numeral")
	
	total += test(roman_to_int("CCXCIV"), 294)
	total += test(roman_to_int("CCCXII"), 312)
		                 
	total += test(roman_to_int("D"), 500)
	total += test(roman_to_int("L"), 50)
	total += test(roman_to_int("D"), 500)
	print str(total) + 'out of 8'

if __name__ == '__main__':
  main()

