from re import split
x, y, z = split("\s", input("Expression: "))
match y:
    case "+":
        print(float(int(x) + int(z)))
    case "-":
        print(float(int(x) - int(z)))
    case "*":
        print(float(int(x) * int(z)))
    case "/":
        print(int(x) / int(z))