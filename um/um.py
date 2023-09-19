import re


def main():
    print(count(input("Text: ")))


def count(s):
    m = re.findall(r"[\b]um[\b]", s)
    return len(m)


if __name__ == "__main__":
    main()
