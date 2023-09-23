from datetime import date


def main():
    birth = get_birth()
    timedelta = get_timedelta(birth)
    mins = get_mins(timedelta)
    print(wordify(mins))


def get_birth():
    birthdate = input("Date of Birth: ")
    

if __name__ == "__main__":
    main()
