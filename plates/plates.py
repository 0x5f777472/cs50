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
                    passed = 1
            safe = 1
            for i in range(len(s)):
                if s[i].isnumeric() and s[i] == 0:
                    safe = 0
                    break
            if passed and safe:
                return True
    return False

main()
