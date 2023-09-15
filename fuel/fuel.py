while True:
    gauge = input("Fraction: ")
    try:
        x, y = gauge.split("/")
        x = int(x)
        y = int(y)
        if x > y or y == 0:
            continue
        frac = 100 * x/y
        if frac > 99:
            print("F")
        elif frac < 1:
            print("E")
        else:
            print(f"{round(frac)}%")

    except (ValueError, ZeroDivisionError):
        pass
