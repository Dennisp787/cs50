from sys import argv, exit
import csv
import cs50

if len(argv) != 2:
    print("Usage: python import.py characters.csv")
    exit(1)

open(f"students.db", "w").close()
db = cs50.SQL("sqlite:///students.db")
db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")

with open(argv[1], "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        d = {}
        l = (row["name"].split(" "))
        if len(l) == 3:
            d.update({"first": l[0], "middle": l[1], "last": l[2]})
        else:
            d.update({"first": l[0], "middle": None, "last": l[1]})
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                   d["first"], d["middle"], d["last"], row["house"], row["birth"])

