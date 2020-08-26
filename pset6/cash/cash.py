from cs50 import get_float


def coin():
    c = round(cash * 100)
    quarters = c / 25
    dimes = (c % 25) / 10
    nickels = ((c % 25) % 10) / 5
    pennies = ((c % 25) % 10) % 5
    t = int(quarters) + int(dimes) + int(nickels) + int(pennies)
    print(t)


while True:
    cash = get_float("How much change: ")
    if cash > 0:
        coin()
        break

