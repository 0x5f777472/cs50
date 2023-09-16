import sys
if len(sys.argv) < 2:
    print("Too few command-line arguments")
    sys.exit(1)
elif len(sys.argv) > 2:
    print("Too many command-line arguments")
    sys.exit(1)
elif sys.argv[1][-3:] != ".py":
    print("Not a Python file")
    sys.exit(1)
else:
    with open(sys.argv[1], "r") as file:
        ...