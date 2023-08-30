# TODO
def main():
    while True:
        try:
            number = int(input("Number: "))
            length = count(number)
            initial = number // (10 ** (length - 2))
            if luhn(number) % 10 == 0:
                if length == 15 &
        except:
            continue

def nth(number, n):
    return (number / (10 ** n)) % 10

def luhn(number):
    sum = 0
    for i in range(1, count(number)):
        stupid = 2 * nth(number, i)
        for j in range(count(stupid)):
            sum += nth(stupid, j)
            j += 1
        i += 2
    for i in range(count(number)):
        sum += nth(number, i)
        i += 2
    return sum

def count(number):
    return len(str(number))

if __name__ == '__main__':
    main()