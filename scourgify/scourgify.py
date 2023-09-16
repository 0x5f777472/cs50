import sys
import csv
if len(sys.argv) < 3:
    sys.exit("Too few command-line arguments")
elif len(sys.argv) > 3:
    sys.exit("Too many command-line arguments")
elif sys.argv[1][-4:] != ".csv":
    sys.exit("Not a CSV file")
else:
    try:
        with open(sys.argv[1], "r") as b:
            before = list(csv.reader(b))
        with open(sys.argv[2], "w") as a:
            after = csv.writer(a)
            after.writerow(["first", "last", "house"])
            for row in before:
                if row == "name":
                    continue
                last, first = row[0].split(", ")
                after.writerow([first, last, row[1]])
    except EnvironmentError:
        sys.exit(f"Could not read {sys.argv[1]}")