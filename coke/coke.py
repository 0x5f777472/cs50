change = 50
while True:
    print(f"Amount Due: {change}")
    coin = input("Insert Coin: ")
    if coin in ["5", "10", "25"]:
        change -= int(coin)
    if change <= 0:
        print(f"Change Owed: {-change}")
        break