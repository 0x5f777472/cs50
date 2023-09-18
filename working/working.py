import re


def main():
    print(convert(input("Hours: ")))


def convert(s):
    if m := re.search(r"([1-9]|1[0-2]):?([0-5][0-9])? (AM|PM) to ([1-9]|1[0-2]):?([0-5][0-9])? (AM|PM)", s):
        h1, m1, p1, h2, m2, p2 = m.groups()
        h1, h2 = int(h1), int(h2)
        if p1 == "PM":
            h1 = (h1 + 12) % 24
        if p2 == "PM":
            h2 = (h2 + 12) % 24
        if p1 == "AM":
            h1 %= 12
        if p2 == "AM":
            h2 %= 12
        start_time = f"{h1:02}:{m1:02}" if m1 else f"{h1:02}:00"
        end_time = f"{h2:02}:{m2:02}" if m2 else f"{h2:02}:00"
        return f"{start_time} to {end_time}"
    raise ValueError
if __name__ == "__main__":
    main()