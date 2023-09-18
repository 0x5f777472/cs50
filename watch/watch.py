import re
import sys


def main():
    print(parse(input("HTML: ")))


def parse(s):
    m = re.search(r"src=\".*?youtube\.com/embed/(\w*)\"", s)
    if m:
        return f"https://youtu.be/{m.group(1)}"




if __name__ == "__main__":
    main()
