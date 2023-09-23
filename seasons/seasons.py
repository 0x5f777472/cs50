from datetime import date


def main():
    timedelta = get_delta()
    print(timedelta)
    mins = get_mins(timedelta)
    print(wordify(mins))


def get_delta():
    birth_string = input("Date of Birth: ")
    birth = date.fromisoformat(birth_string)
    return date.today() - birth

if __name__ == "__main__":
    main()
