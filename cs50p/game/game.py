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
        secret = randint(1, level)
        guess = int(input("Guess: "))
        if guess < secret:
            print("Too small!")
        elif guess > secret:
            print("Too large!")
        else:
            print("Just Right!")
            break
    except:
        continue