import re
import sys


def main():
    print(parse(input("HTML: ")))


def parse(s):
    m = re.search(r"youtube.com/.*?\"", s)
    if m:
        return f"https://youtu.be/{m.group(0).rsplit("/", 1)[-1]}"




if __name__ == "__main__":
    main()
