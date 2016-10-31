def string_manip(s):
  # remove white space from the beginning and end of the string
  first_string = s.strip()

  # take the string and return a new string with all uppercase letteres
  new_str = first_string.upper()

  # replace all remaining spaces with the pound sign
  another_str = new_str.replace(" ","#")

  # if the string is a single character, return that string
  if len(another_str) == 1:
    return another_str
    exit()
  # if the string consists entirely of digits, return that string
  elif another_str.isdigit() == True:
    return another_str
    exit()
  # otherwise, return the string in reverse
  else:
    return another_str[::-1]

print(string_manip(' Colleen van Lent'))
print(string_manip('276876    '))
print(string_manip('    276 876'))