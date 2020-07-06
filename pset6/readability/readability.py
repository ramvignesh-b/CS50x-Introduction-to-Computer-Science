from cs50 import get_string

text = get_string("Text: ")
letter = word = sentence = 0
for i in text:
    if i.isalpha():
        letter += 1
    if i in ["!", ".", "?"]:
        sentence += 1
    if i in [" "]:
        word += 1
word += 1

L = letter * 100 / word
S = sentence * 100 / word
index = round(0.0588 * L - 0.296 * S - 15.8)

#print("Letter: ", letter, " Words: ", word, " Sentences: ", sentence, " Index: ", index)

if (index < 1):
    print("Before Grade 1")
elif (index <= 16):
    print(f"Grade {index}")
else:
    print("Grade 16+")