import textwrap
import csv
from csv import reader, DictReader
from sys import argv

if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(-1)

STR = []
profile = []


def count_repeat(text, dna):
    flag = maxCount = count = 0
    # Splice 1 ..... n where n is the length of STR dna
    for j in range (0, len(dna)):
        # Split the text string based on STR dna's length
        list = textwrap.wrap(text[j:],len(dna))
        for i in range (0, len(list)):
            # No consecutive Repeats
            if flag == 1 and list[i] != dna:
                if count > maxCount:
                    maxCount = count
                count = 0
            # Found DNA for the first time
            if list[i] == dna:
                flag = 1
                count += 1
        # Keep the max consecutive repeat Count found so far
        if count > maxCount:
            maxCount = count
        # Reset the repeat count to zero
        flag = count = 0
    return maxCount


# Get database

with open(argv[1], 'r') as people:
    reader = DictReader(people)
    STR = reader.fieldnames[1:]
    for line in reader:
        profile.append(line)

sequenceCount = dict.fromkeys(STR, 0)

# Get sequence

with open(argv[2], 'r') as sequence:
    text = sequence.readline()
    for dna in STR:
        sequenceCount[dna] = count_repeat(text, dna)


# check if matches person's DNA

for person in profile:
    match = 0
    for dna in STR:
        if int(person[dna]) == sequenceCount[dna]:
            match += 1
        else:
            match = 0
            break

    if match != 0:
        print(person['name'])
        exit(0)
print("No match")
exit(1)