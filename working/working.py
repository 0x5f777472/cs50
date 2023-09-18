import re


def main():
    print(convert(input("Hours: ")))


def convert(s):
    if m := re.search(r"([1-9]|1[0-2])(?::([0-5][0-9]))? (AM|PM) to ([1-9]|1[0-2])(?::([0-5][0-9]))? (AM|PM)", s):
        h1 = m.group(1)
        p1 = m.group(3)
        h2 = m.group(4)
        p2 = m.group(6)
        if None in m.groups:
            return f"{h1:02}:00 to {h2:02}:00"
        m1 = m.group(2)
        m2 = m.group(5)
        return f"{h1:02}:{m1} to {h2:02}:{m2}"

if __name__ == "__main__":
    main()