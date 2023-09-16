import random
while True:
    try:
        level = int(input("Level: "))
        if level < 1:
            continue
    except:
        continue