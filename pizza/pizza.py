import csv
import tabulate
import sys
if len(sys.argv) < 2:
    print("Too few command-line arguments")
    sys.exit(1)
elif len(sys.argv) > 2:
    print("Too many command-line arguments")
    sys.exit(1)
elif sys.argv[1][-3:] != ".csv":
    print("Not a CSV file")
    sys.exit(1)
else:
    try:
        with open(sys.argv[1], "r") as file:
            lines = csv.reader(file)
    except EnvironmentError:
        print("oops")