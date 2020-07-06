import csv
import cs50
from sys import argv

if len(argv) != 2:
    print("Usage python import.py characters.csv")
    exit(-1)

db = cs50.SQL('sqlite:///students.db')

with open(argv[1], "r") as file:
    reader = csv.reader(file)
    flag = 1
    for row in reader:
        if flag:
            flag = 0
            continue
        name = row[0].split()
        names = []
        if len(name) == 2:
            names.append(name[0])
            names.append(None)
            names.append(name[1])
        else:
            names.append(name[0])
            names.append(name[1])
            names.append(name[2])
        db.execute('INSERT INTO students (first, middle, last, house, birth) VALUES (?,?,?,?,?)', names[0], names[1], names[2], row[1], row[2])

    exit(0)