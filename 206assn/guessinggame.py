answer = 21

guess = input('Enter guess:')
print ('Your guess is', guess)

while true:
	if guess < answer:
    	print ('Your guess is too low')
	if guess > answer:
    	print ('Your guess is too high')
    if guess == answer:
    	print ('Congratulations!')
    	break