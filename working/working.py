import re


def main():
    print(convert(input("Hours: ")))


def convert(s):
    if m := re.search(r"([1-9]|1[0-2])(?::([0-5][0-9]))? (AM|PM) to ([1-9]|1[0-2])(?::([0-5][0-9]))? (AM|PM)", s):
        h1 = int(m.group(1))
        m1 = m.group(2)
        p1 = m.group(3)
        h2 = int(m.group(4))
        m2 = m.group(5)
        p2 = m.group(6)
        if p1 == "PM" and h1 != 12:
            h1 += 12
        if p2 == "PM" and h2 != 12:
            h2 += 12
        if p1 == "AM" and h1 == 12:
            h1 -= 12
        if p2 == "AM" and h2 == 12:
            h2 -= 12
        if m1 and m2:
            return f"{h1:02}:{m1} to {h2:02}:{m2}"
        elif m1:
            return f"{h1:02}:{m1} to {h2:02}:00"
        elif m2:
            return f"{h1:02}:00 to {h2:02}:{m2}"
        else:
            return f"{h1:02}:00 to {h2:02}:00"
    raise ValueError
if __name__ == "__main__":
    main()