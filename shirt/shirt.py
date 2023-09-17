import sys
from PIL import Image
if len(sys.argv) < 3:
    sys.exit("Too few command-line arguments")
elif len(sys.argv) > 3:
    sys.exit("Too many command-line arguments")
elif sys.argv[1].rsplit('.', 1)[1].lower() or sys.argv[2].rsplit('.', 1)[1].lower()
    sys.exit("Invalid input")
elif sys.argv[1][-4:].lower() != sys.argv[2][-4:].lower():
    ...
else:
    try:
        ...
    except:
        ...