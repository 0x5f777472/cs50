from random import randint
def main():
    ...


def get_level():
    while True:
        try:
            level = int(input("Level: "))
            if level not in [1,2,3]:
                continue
            return level
        except:
            continue


def generate_integer(level):
    match level:
        case 1:
            x = randint(0, 9)
            y = randint(0, 9)
        case 2:
            x = randint(10, 99)
            y = randint(10, 99)
        case 3:
            x = randint(100, 999)
            y = randint(100, 999)
        return x, y


if __name__ == "__main__":
    main()