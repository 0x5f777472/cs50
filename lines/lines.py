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
    try:
        with open(sys.argv[1], "r") as file:
            lines = file.readlines()
        line_count = 0
        for line in lines:
            if not line.isspace():
                if line.lstrip()[0] != "#":
                    line_count += 1
        print(line_count)
    except EnvironmentError:
        print("oops")