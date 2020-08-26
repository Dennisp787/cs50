from sys import argv, exit
import csv
import cs50

if len(argv) != 2:
    print("Usage: roster.py House name")
    exit(1)
db = cs50.SQL("sqlite:///students.db")

if argv[1] == "Gryffindor":
    row = db.execute("SELECT * FROM students WHERE house = 'Gryffindor' ORDER BY last")
    for i in row:
        if i['middle'] != None:
            print(i['first'], i['middle'], i["last"], "born", i["birth"])
        else:
            print(i['first'], i["last"]+",", "born", i["birth"])

elif argv[1] == "Hufflepuff":
    row = db.execute("SELECT * FROM students WHERE house = 'Hufflepuff' ORDER BY last")
    for i in row:
        if i['middle'] != None:
            print(i['first'], i['middle'], i["last"], "born", i["birth"])
        else:
            print(i['first'], i["last"]+",", "born", i["birth"])

elif argv[1] == "Ravenclaw":
    row = db.execute("SELECT * FROM students WHERE house = 'Ravenclaw' ORDER BY last")
    for i in row:
        if i['middle'] != None:
            print(i['first'], i['middle'], i["last"], "born", i["birth"])
        else:
            print(i['first'], i["last"]+",", "born", i["birth"])

elif argv[1] == "Slytherin":
    row = db.execute("SELECT * FROM students WHERE house = 'Slytherin' ORDER BY last")
    for i in row:
        if i['middle'] != None:
            print(i['first'], i['middle'], i["last"], "born", i["birth"])
        else:
            print(i['first'], i["last"]+",", "born", i["birth"])
