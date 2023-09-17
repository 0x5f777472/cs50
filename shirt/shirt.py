import sys
import 
if len(sys.argv) < 3:
    sys.exit("Too few command-line arguments")
elif len(sys.argv) > 3:
    sys.exit("Too many command-line arguments")
elif sys.argv[1] :
    sys.exit("Not a CSV file")
else:
    try:
