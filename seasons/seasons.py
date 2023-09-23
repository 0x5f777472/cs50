from datetime import date


def main():
    birth = get_birth()
    timedelta = get_timedelta(birth)
    mins = get_mins(timedelta)
    print(wordify(mins))


def get_birth():
    birth_string = input("Date of Birth: ")
    birth = date(birth_string.split('_'))
    print(birth)

if __name__ == "__main__":
    main()
