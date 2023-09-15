def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    if 2 <= len(s) <= 6 and s.isalnum():
        if s.isalpha():
            return True
        if s[:2].isalpha() and s[-1:].isnumeric():
            for i in range(len(s)):
                if s[i].isdigit():
                    return not (s[i] == "0" or s[i:].isalpha())
    return False

main()
