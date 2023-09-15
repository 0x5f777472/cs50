change = 50
while change:
    print(f"Amount Due: {change}")
    coin = input("Insert Coin: ")
    if coin in ["5", "10", "25"]:
        change -= int(coin)