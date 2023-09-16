import sys
import random
from pyfiglet import Figlet
figlet = Figlet()
word = input("Input: ")
if len(sys.argv) == 1:
    font=random.choice(figlet.getFonts())
    print("Output:\n" + figlet.figlet_format(word))
elif len(sys.argv) == 3 and sys.argv[1] in ["-f", "--font"]:
