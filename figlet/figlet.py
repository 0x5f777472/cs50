import sys
import random
from pyfiglet import Figlet
if len(sys.argv) == 1:
word = input("Input: ")
    f = Figlet(font=random.choice(Figlet().getFonts()))
    print("Output:")
    print(f.renderText(word))
elif len(sys.argv) == 3 and sys.argv[1] in ["-f", "--font"] and sys.argv[2] in Figlet().getFonts():
    f = Figlet(font=sys.argv[2])
    print("Output:")
    print(f.renderText(word))
else:
    print("Invalid Usage")
    sys.exit(1)