from random import randint
while True:
    try:
        level = int(input("Level: "))
        if level < 1:
            continue
        break
    except:
        continue
while True:
    try:
        guess = int(input("Guess: "))
    except:
        continue