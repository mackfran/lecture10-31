from nltk.tokenize import sent_tokenize, word_tokenize

text = "Hello students, how are you doing today? Have you recovered from the exam?  I hope you are feeling better.  Things will be fine."

print(sent_tokenize(text))
print(word_tokenize(text))

for i in word_tokenize(text):
	print(i)

