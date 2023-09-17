import sys
from PIL import Image
if len(sys.argv) < 3:
    sys.exit("Too few command-line arguments")
elif len(sys.argv) > 3:
    sys.exit("Too many command-line arguments")
elif not sys.argv[1].endswith((".jpg", ".jpeg", ".png")) or not sys.argv[2].endswith((".jpg", ".jpeg", ".png")):
    sys.exit("Invalid input")
elif sys.argv[1][-4:].lower() != sys.argv[2][-4:].lower():
    ...
else:
    try:
        ...
    except:
        ...