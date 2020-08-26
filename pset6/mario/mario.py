from cs50 import get_int


def ask():
    for i in range(height):
        print(" "*((height-i)-1), end="")
        for j in range(i+1):
            print("#", end="")
        print()


while True:
    height = get_int("Height: ")
    if height < 9 and height > 0:
        ask()
        break
