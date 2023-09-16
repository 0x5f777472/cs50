import sys
import random
from pyfiglet import Figlet
figlet = Figlet()
word = input("Input: ")
if len(sys.argv) == 1:
    font = random.choice(figlet.getFonts())
    print("Output:\n" + Figlet(font=random).renderText(word))

print("Output:\n" + Figlet(font=sys.argv[2]).renderText(word))