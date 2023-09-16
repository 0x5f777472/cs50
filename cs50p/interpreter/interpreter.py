x, y, z = input("Expression: ").split(" ")
match y:
    case "+":
        print(float(int(x) + int(z)))
    case "-":
        print(float(int(x) - int(z)))
    case "*":
        print(float(int(x) * int(z)))
    case "/":
        print(int(x) / int(z))