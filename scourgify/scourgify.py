import sys
import csv
if len(sys.argv) < 3:
    sys.exit("Too few command-line arguments")
elif len(sys.argv) > 3:
    sys.exit("Too many command-line arguments")
elif sys.argv[1][-4:] != ".csv":
    sys.exit(f"Could not read {sys.argv[1]}")
else:
    try:
        with open(sys.argv[1], "r") as file:
            lines = list(csv.reader(file))
        print(tabulate(lines, headers="firstrow", tablefmt="grid"))
    except EnvironmentError:
        sys.exit("File does not exist")