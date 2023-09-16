import sys
import csv
from tabulate import tabulate
if len(sys.argv) < 2:
    sys.exit("Too few command-line arguments")
elif len(sys.argv) > 2:
    sys.exit("Too many command-line arguments")
elif sys.argv[1][-4:] != ".csv":
    sys.exit("Not a CSV file")
else:
    try:
        with open(sys.argv[1], "r") as file:
            lines = list(csv.reader(file))
        print(tabulate(lines, headers="firstrow", tablefmt="grid"))
    except EnvironmentError:
        sys.exit("File does not exist")