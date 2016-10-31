answer = 21

while True:
	guess = input('Enter guess:')
	try:
		int(guess)
	except:
		print ('Invalid input')
		continue
	print ('Your guess is', guess)
	if guess < answer:
		print ('Your guess is too low')
	if guess > answer:
		print ('Your guess is too high')
	if guess == answer:
		print ('Congratulations!')
		break