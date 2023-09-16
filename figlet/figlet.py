import sys
import random
from pyfiglet import Figlet
word = input("Input: ")
if len(sys.argv) == 1:
    f = Figlet(font=random.choice(Figlet().getFonts()))
    print("Output:")
    print(f.renderText(word))
elif len(sys.argv) == 3 and sys.argv[1] in ["-f", "--font"]:
    f = Figlet(font=sys.argv[2])
    print("Output:")
    print(f.renderText(word))
else:
    sys.exit(1)