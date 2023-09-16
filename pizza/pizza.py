import sys
import csv
from tabulate import tabulate
if len(sys.argv) < 2:
    print("Too few command-line arguments")
    sys.exit(1)
elif len(sys.argv) > 2:
    print("Too many command-line arguments")
    sys.exit(1)
elif sys.argv[1][-4:] != ".csv":
    print("Not a CSV file")
    sys.exit(1)
else:
    try:
        with open(sys.argv[1], "r") as file:
            lines = list(csv.reader(file))
        print(tabulate(lines, headers="firstrow", tablefmt="grid"))
    except EnvironmentError:
        print("File does not exist")
        sys.exit(1)