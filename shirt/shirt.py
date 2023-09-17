import sys
from PIL import Image, ImageOps
if len(sys.argv) < 3:
    sys.exit("Too few command-line arguments")
elif len(sys.argv) > 3:
    sys.exit("Too many command-line arguments")
elif sys.argv[1].rpartition('.')[2].lower() not in ["jpg", "jpeg", "png"] or sys.argv[2].rpartition('.')[2].lower() not in ["jpg", "jpeg", "png"]:
    sys.exit("Invalid input")
elif sys.argv[1].rpartition('.')[2].lower() != sys.argv[2].rpartition('.')[2].lower():
    sys.exit("Input and output have different extensions")
else:
    try:
        shirt = Image.open("shirt.png")
        before = Image.open(sys.argv[1])
        after = Image.open(sys.argv[2], mode='w')
        cropped = ImageOps.fit(before, )
    except FileNotFoundError:
        ...