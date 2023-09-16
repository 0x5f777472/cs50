import sys
if sys.argv == 1:
    print("Too few command-line arguments")
    sys.exit(1)
elif sys.argv > 2:
    print("Too many command-line arguments")
    sys.exit(1)