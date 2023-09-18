import re
import sys


def main():
    print(parse(input("HTML: ")))


def parse(s):
    m = re.search(r"youtube.com/.*?\"", s)
    return m




if __name__ == "__main__":
    main()
