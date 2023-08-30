# TODO
def main():
    while True:
        try:
            number = int(input("Number: "))
            length = count(number)
            initial = number // (10 ** (length - 2))
            if luhn(number) % 10 == 0:
                if length == 15 and (intial == 34 or initial == 37):
                    print("AMEX")
                    break
                elif length == 16 and (initial == 51 or initial == 52 or initial == 53 or initial == 54 or initial == 55):
                    print("MASTERCARD")
                    break
                elif (initial // 10 == 4) and (length == 13 or length == 16):
                    print("VISA")
                    break
                else:
                    print("INVALID")
                    break
            else:
                print("INVALID")
                break
        except:
            continue


def nth(number, n):
    return (number // (10**n)) % 10


def luhn(number):
    sum = 0
    for i in range(1, count(number), 2):
        stupid = 2 * nth(number, i)
        for j in range(count(stupid)):
            sum += nth(stupid, j)
    for i in range(0, count(number), 2):
        sum += nth(number, i)
    return sum


def count(number):
    return len(str(number))


if __name__ == "__main__":
    main()
