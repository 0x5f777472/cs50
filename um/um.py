import re


def main():
    print(count(input("Text: ")))


def count(s):
    m = re.findall(r"(?:\W|\b)um(?:\W|\b)", s.lower())
    return len(m)


if __name__ == "__main__":
    main()
