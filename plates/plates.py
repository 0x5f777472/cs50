def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    if 2 <= len(s) <= 6:
        if s.isalpha():
            return True
        if s.isalnum():
            for i in range(2, len(s)):
                if s[-(len(s) - i):].isnumeric():
    return False

main()
