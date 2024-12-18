import sys
from datetime import date
import inflect
p = inflect.engine()

def main():
    timedelta = get_delta()
    mins = get_mins(timedelta)
    print(wordify(mins))


def get_delta():
    birth_string = input("Date of Birth: ")
    try:
        birth = date.fromisoformat(birth_string)
        return date.today() - birth
    except:
        sys.exit("Invalid Date")

def get_mins(timedelta):
    return timedelta.days * 1440

def wordify(mins):
    return p.number_to_words(mins, andword="").capitalize() + " minutes"

if __name__ == "__main__":
    main()
