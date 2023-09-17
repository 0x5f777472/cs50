import sys
from PIL import Image, ImageOps
if len(sys.argv) < 3:
    sys.exit("Too few command-line arguments")
elif len(sys.argv) > 3:
    sys.exit("Too many command-line arguments")
elif sys.argv[2].rpartition('.')[-1].lower() not in ["jpg", "jpeg", "png"]:
    sys.exit("Invalid output")
elif sys.argv[1].rpartition('.')[-1].lower() != sys.argv[2].rpartition('.')[-1].lower():
    sys.exit("Input and output have different extensions")
else:
    try:
        shirt = Image.open("shirt.png")
        with Image.open(sys.argv[1]) as before:
            cropped = ImageOps.fit(before, shirt.size)
            cropped.paste(shirt, shirt)
            cropped.save(sys.argv[2])
    except FileNotFoundError:
        sys.exit("File not found")