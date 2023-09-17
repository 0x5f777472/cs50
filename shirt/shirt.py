import sys
from PIL import Image
if len(sys.argv) < 3:
    sys.exit("Too few command-line arguments")
elif len(sys.argv) > 3:
    sys.exit("Too many command-line arguments")
elif sys.argv[1].endswith((".jpg", ".jpeg", ".png")):
    sys.exit("Invalid input")
else:
    try:
        ...
    except:
        ...