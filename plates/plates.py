def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    if 2 <= len(s) <= 6 and s.isalnum() and s[:2].isalpha() and s.find("0"):
        ...
        return True
    return False

main()
