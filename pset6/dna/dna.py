from sys import argv, exit
import csv
import re

# check to see if correct numeber of in-line argument
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)
# open scv file into a ordered dictionary
file = open(argv[1], "r")
reader = csv.DictReader(file)
# open the text file to read
tfile = open(argv[2], "r")
# set variable to opened text file
string = tfile.read()


# search for Dna code in text file
def check(substring):
    count = 1
    res = [i.start() for i in re.finditer(substring, string)]
    l = len(res)
    for i in range(l):
        try:
            if res[i]+len(substring) == res[i+1]:
                count += 1
        except IndexError:
            break
    return(count)


# set variabel of the person
person = None

# interate through dictionary to find the person that the dna belongs
for row in reader:
    if argv[1] == "databases/small.csv":
        A = int(row["AGATC"])
        B = int(row["AATG"])
        C = int(row["TATC"])
        if check("AGATC") == A and check("AATG") == B and check("TATC") == C:
            person = row["name"]

    if argv[1] == "databases/large.csv":
        point = 0
        AA = int(row["AGATC"])
        BB = int(row["TTTTTTCT"])
        CC = int(row["AATG"])
        DD = int(row["TCTAG"])
        EE = int(row["GATA"])
        FF = int(row["TATC"])
        GG = int(row["GAAA"])
        HH = int(row["TCTG"])
        if check("AGATC") == AA:
            point += 1
            if check("TTTTTTCT") == BB:
                point += 1
                if check("AATG") == CC:
                    point += 1
        if check("TCTAG") == DD:
            point += 1
            if check("GATA") == EE:
                point += 1
            if check("TATC") == FF:
                point += 1
        if check("GAAA") == GG:
            point += 1
        if check("TCTG") == HH:
            point += 1
        if point >= 7:
            person = row["name"]
if person == None:
    print("No match")
else:
    print(person)