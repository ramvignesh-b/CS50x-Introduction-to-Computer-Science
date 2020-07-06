import cs50
from sys import argv

db = cs50.SQL('sqlite:///students.db')

if len(argv) != 2:
    print("Usage python roster.py <house_name>")
    exit(-1)

house = argv[1]

row = db.execute('SELECT * FROM students WHERE house = ? ORDER BY last, first', house)

for i in range (0, len(row)):
    if row[i]['middle'] == None:
        print(row[i]['first'] + ' ' + row[i]['last'] + ', born ' + str(row[i]['birth']))
    else:
        print(row[i]['first'] + ' ' + row[i]['middle'] + ' ' + row[i]['last'] + ', born ' + str(row[i]['birth']))
exit(0)