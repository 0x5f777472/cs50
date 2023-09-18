import re
import sys


def main():
    print(parse(input("HTML: ")))


def parse(s):
    m = re.match(r"src=\".*?youtube\.com/embed/(\w*)\"", s)
    if m:
        return f"https://youtu.be/{}"




if __name__ == "__main__":
    main()
