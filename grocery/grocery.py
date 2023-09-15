groceries = dict()
while True:
    try:
        item = input()
        if item in groceries:
            groceries[item] += 1
        else:
            groceries[item] = 1
    except EOFError:
        for item in sorted(groceries):
            print(f"{groceries[item]} {item.upper()}")
        break