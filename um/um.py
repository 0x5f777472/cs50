import re


def main():
    print(count(input("Text: ")))


def count(s):
    m = re.findall(r"(?:[^A-Za-z0-9]|\b)um(?:[^A-Za-z0-9]|\b)", s.lower())
    return len(m)


if __name__ == "__main__":
    main()
