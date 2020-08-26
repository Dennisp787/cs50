from cs50 import get_string

word = 1
sentence = 0
letter = 0
lower = 'abcdefghijklmnopqrstuvwxyz'
upper = 'ABCDEFGHJKLMNOPQRSTUVWXYZ'
pun = '.?!'
text = get_string("Text: ")

for i in text:
    if i == " ":
        word += 1
    elif i in pun:
        sentence += 1
    elif i in lower:
        letter += 1
    elif i in upper:
        letter += 1

L = letter/word * 100
S = sentence/word * 100
index = 0.0588 * L - 0.296 * S - 15.8
index = round(index)
if index < 1:
    print("Before Grade 1")

elif index < 16:
    print("Grade {}".format(index))

elif index >= 16:
    print("Grade 16+")
