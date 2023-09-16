import random
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
        case 2:
        case 3:
        


if __name__ == "__main__":
    main()