import sys
import csv
if len(sys.argv) < 3:
    sys.exit("Too few command-line arguments")
elif len(sys.argv) > 3:
    sys.exit("Too many command-line arguments")
elif sys.argv[1][-4:] != ".csv":
    sys.exit("Invalid input file name")
else:
    try:
        with open(sys.argv[1], "r") as file:
            lines = list(csv.reader(file))
        print(lines)
    except EnvironmentError:
        sys.exit(f"Could not read {sys.argv[1]}")